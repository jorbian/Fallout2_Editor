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

    strnum = 5;
    pernum = 5;
    endnum = 5;
    charnum = 5;
    intnum = 5;
    aginum = 5;
    lucknum =5;
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

