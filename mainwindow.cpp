#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap original_Image(":/images/fallout2boy.jpg");
    QSize labelSize = ui->Fallout_Boy->size();
    QPixmap scaled_Image = original_Image.scaled(labelSize, Qt::KeepAspectRatio);
    ui->Fallout_Boy->setPixmap(scaled_Image);

    strnum = 0;
    pernum = 0;
    endnum = 0;
    charnum = 0;
    intnum = 0;
    aginum = 0;
    lucknum =0;
    // Initialize the number
    // You can choose any initial value between 1 and 10

    // Update the label with the initial number
    ui->Strength_Number->setText(QString::number(strnum));
    ui->Perception_Number->setText(QString::number(pernum));
    ui->Endurance_Number->setText(QString::number(endnum));
    ui->Charisma_Number->setText(QString::number(charnum));
    ui->Intelligence_Number->setText(QString::number(intnum));
    ui->Agility_Number->setText(QString::number(aginum));
    ui->Luck_Number->setText(QString::number(lucknum));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Strength_Up_clicked()
{
    if (strnum < 10)
    {
        strnum++;
        ui->Strength_Number->setText(QString::number(strnum));
    }
}


void MainWindow::on_Strength_Down_clicked()
{
    if (strnum <= 10 && strnum > 1)
    {
        strnum--;
        ui->Strength_Number->setText(QString::number(strnum));
    }
}

void MainWindow::on_Perception_Up_clicked()
{
    if(pernum < 10)
    {
        pernum++;
        ui->Perception_Number->setText(QString::number(pernum));
    }
}


void MainWindow::on_Perception_Down_clicked()
{
    if (pernum <= 10 && pernum > 1)
    {
        pernum--;
        ui->Perception_Number->setText(QString::number(pernum));
    }
}


void MainWindow::on_Endurance_Up_clicked()
{
    if(endnum < 10)
    {
        endnum++;
        ui->Endurance_Number->setText(QString::number(endnum));
    }
}

void MainWindow::on_Endurance_Down_clicked()
{
    if (endnum <= 10 && endnum > 1)
    {
        endnum--;
        ui->Endurance_Number->setText(QString::number(endnum));
    }
}


void MainWindow::on_Charisma_Up_clicked()
{
    if(charnum < 10)
    {
        charnum++;
        ui->Charisma_Number->setText(QString::number(charnum));
    }
}



void MainWindow::on_Charisma_Down_clicked()
{
    if (charnum <= 10 && charnum > 1)
    {
        charnum--;
        ui->Charisma_Number->setText(QString::number(charnum));
    }
}


void MainWindow::on_Intelligence_Up_clicked()
{
    if(intnum < 10)
    {
        intnum++;
        ui->Intelligence_Number->setText(QString::number(intnum));
    }
}


void MainWindow::on_Intelligence_Down_clicked()
{
    if (intnum <= 10 && intnum > 1)
    {
        intnum--;
        ui->Intelligence_Number->setText(QString::number(intnum));
    }
}


void MainWindow::on_Agility_Up_clicked()
{
    if(aginum < 10)
    {
        aginum++;
        ui->Agility_Number->setText(QString::number(aginum));
    }
}


void MainWindow::on_Agility_Down_clicked()
{
    if (aginum <= 10 && aginum > 1)
    {
        aginum--;
        ui->Agility_Number->setText(QString::number(aginum));
    }
}


void MainWindow::on_Luck_Up_clicked()
{
    if(lucknum < 10)
    {
        lucknum++;
        ui->Luck_Number->setText(QString::number(lucknum));
    }
}


void MainWindow::on_Luck_Down_clicked()
{
    if (lucknum <= 10 && lucknum > 1)
    {
        lucknum--;
        ui->Luck_Number->setText(QString::number(lucknum));
    }
}


void MainWindow::on_load_file_clicked()
{
    this -> filePath = QFileDialog::getOpenFileName(this, "Select a File", "", "All Files (*)");

    if (!filePath.isEmpty()) {
        std::ifstream hexFile(filePath.toStdString(), std::ios::binary);

        if (!hexFile.is_open()) {
            qDebug() << "Failed to open the file.";
            return;
        }

        const int patternLength = 4; // Adjust to match the length of your pattern
        const char desiredPattern[5] = "\x00\x00\x46\x50"; // Example pattern as a string

        bool patternFound = false;
        std::streampos offset = 0;
        int strength = 0; // Variable to store strength value

        while (!hexFile.eof()) {
            hexFile.seekg(offset);

            char readData[patternLength];
            hexFile.read(readData, patternLength);

            if (hexFile.gcount() != patternLength) {
                break; // Reached end of file or unable to read more bytes
            }

            if (memcmp(readData, desiredPattern, 4) == 0) {
                patternFound = true;
                offset += patternLength; // Move offset to the position after the pattern
                break;
            }
            offset += 1; // Increment offset within the loop
        }

        if (patternFound) {
            qDebug() << "Pattern found at offset" << (offset - static_cast<std::streampos>(patternLength));
            offset += 239; // Set offset to 239 bytes after the pattern
            qDebug() << "Offset set to" << offset;

            hexFile.seekg(static_cast<std::streamoff>(offset) + 4); // Move to the new offset + 4 bytes
            char newValue[1];
            int stroffset, peroffset, endoffset, charoffset, intoffset, agiloffset, luckoffset;
            stroffset = offset;
            hexFile.read(newValue, 1);
            strnum = static_cast<int>(newValue[0]);
            ui->Strength_Number->setText(QString::number(strnum));
            qDebug() << "Strength value:" << static_cast<int>(newValue[0]);
            hexFile.seekg(static_cast<std::streamoff>(stroffset) + 4); // Move to the new offset + 4 bytes
            peroffset = stroffset += 4;
            hexFile.read(newValue, 1);
            pernum = static_cast<int>(newValue[0]);
            ui->Perception_Number->setText(QString::number(pernum));
            qDebug() << "Perception value:" << static_cast<int>(newValue[0]);
            hexFile.seekg(static_cast<std::streamoff>(peroffset) + 4); // Move to the new offset + 4 bytes
            hexFile.read(newValue, 1);
            endoffset = peroffset += 4;
            endnum = static_cast<int>(newValue[0]);
            ui->Endurance_Number->setText(QString::number(endnum));
            qDebug() << "Endurance value:" << static_cast<int>(newValue[0]);
            hexFile.seekg(static_cast<std::streamoff>(endoffset) + 4); // Move to the new offset + 4 bytes
            hexFile.read(newValue, 1);
            charoffset = endoffset += 4;
            charnum = static_cast<int>(newValue[0]);
            ui->Charisma_Number->setText(QString::number(charnum));
            qDebug() << "Charisma value:" << static_cast<int>(newValue[0]);
            hexFile.seekg(static_cast<std::streamoff>(charoffset) + 4); // Move to the new offset + 4 bytes
            hexFile.read(newValue, 1);
            intoffset = charoffset += 4;
            intnum = static_cast<int>(newValue[0]);
            ui->Intelligence_Number->setText(QString::number(intnum));
            qDebug() <<  "Intelligence value:" << static_cast<int>(newValue[0]);
            hexFile.seekg(static_cast<std::streamoff>(intoffset) + 4); // Move to the new offset + 4 bytes
            hexFile.read(newValue, 1);
            agiloffset = intoffset += 4;
            aginum = static_cast<int>(newValue[0]);
            ui->Agility_Number->setText(QString::number(aginum));
            qDebug() << "Agility value:" << static_cast<int>(newValue[0]);
            hexFile.seekg(static_cast<std::streamoff>(agiloffset) + 4); // Move to the new offset + 4 bytes
            hexFile.read(newValue, 1);
            lucknum = static_cast<int>(newValue[0]);
            ui->Luck_Number->setText(QString::number(lucknum));
            qDebug() << "Luck value:" << static_cast<int>(newValue[0]);
        }
        else
        {
            qDebug() << "Pattern not found";
            qDebug() << "Desired pattern:" << desiredPattern;
        }
}

}


void MainWindow::on_apply_changes_clicked()
{
if (!filePath.isEmpty()) {
        std::fstream hexFile(filePath.toStdString(), std::ios::binary | std::ios::in | std::ios::out);

        if (!hexFile.is_open()) {
            qDebug() << "Failed to open the file.";
            return;
        }

        const int patternLength = 4; // Adjust to match the length of your pattern
        const char desiredPattern[5] = "\x00\x00\x46\x50"; // Example pattern as a string

        bool patternFound = false;
        std::streampos offset = 0;
        int strength = 0; // Variable to store strength value

        while (!hexFile.eof()) {
            hexFile.seekg(offset);

            char readData[patternLength];
            hexFile.read(readData, patternLength);

            if (hexFile.gcount() != patternLength) {
                break; // Reached end of file or unable to read more bytes
            }

            if (memcmp(readData, desiredPattern, 4) == 0) {
                patternFound = true;
                offset += patternLength; // Move offset to the position after the pattern
                break;
            }
            offset += 1; // Increment offset within the loop
        }

        if (patternFound) {
            qDebug() << "Pattern found at offset" << (offset - static_cast<std::streampos>(patternLength));
            offset += 239; // Set offset to 239 bytes after the pattern
            qDebug() << "Offset set to" << offset;

            hexFile.seekg(static_cast<std::streamoff>(offset) + 4); // Move to the new offset + 4 bytes
            char newValue[1];
            int stroffset, peroffset, endoffset, charoffset, intoffset, agiloffset, luckoffset;
            stroffset = offset;
            hexFile.write(reinterpret_cast<const char*>(&strnum), sizeof(strnum));
            qDebug() << "Strength value:" << static_cast<int>(strnum);
            hexFile.seekg(static_cast<std::streamoff>(stroffset) + 4); // Move to the new offset + 4 bytes
            peroffset = stroffset += 4;
            hexFile.write(reinterpret_cast<const char*>(&pernum), sizeof(pernum));
            qDebug() << "Perception value:" << static_cast<int>(pernum);
            hexFile.seekg(static_cast<std::streamoff>(peroffset) + 4); // Move to the new offset + 4 bytes
            hexFile.write(reinterpret_cast<const char*>(&endnum), sizeof(endnum));
            endoffset = peroffset += 4;
            qDebug() << "Endurance value:" << static_cast<int>(endnum);
            hexFile.seekg(static_cast<std::streamoff>(endoffset) + 4); // Move to the new offset + 4 bytes
            hexFile.write(reinterpret_cast<const char*>(&charnum), sizeof(charnum));
            charoffset = endoffset += 4;
            qDebug() << "Charisma value:" << static_cast<int>(charnum);
            hexFile.seekg(static_cast<std::streamoff>(charoffset) + 4); // Move to the new offset + 4 bytes
            hexFile.write(reinterpret_cast<const char*>(&intnum), sizeof(intnum));
            intoffset = charoffset += 4;
            qDebug() <<  "Intelligence value:" << static_cast<int>(intnum);
            hexFile.seekg(static_cast<std::streamoff>(intoffset) + 4); // Move to the new offset + 4 bytes
            hexFile.write(reinterpret_cast<const char*>(&aginum), sizeof(aginum));
            agiloffset = intoffset += 4;
            qDebug() << "Agility value:" << static_cast<int>(aginum);
            hexFile.seekg(static_cast<std::streamoff>(agiloffset) + 4); // Move to the new offset + 4 bytes
            hexFile.write(reinterpret_cast<const char*>(&strnum), sizeof(strnum));
            qDebug() << "Luck value:" << static_cast<int>(lucknum);
        }
        else
        {
            qDebug() << "Pattern not found";
            qDebug() << "Desired pattern:" << desiredPattern;
        }
}

}


