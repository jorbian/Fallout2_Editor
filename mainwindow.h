#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Strength_Up_clicked();

    void on_Strength_Down_clicked();

    void on_Perception_Up_clicked();

    void on_Perception_Down_clicked();

    void on_Endurance_Up_clicked();

    void on_Endurance_Down_clicked();

    void on_Charisma_Up_clicked();

    void on_Charisma_Down_clicked();

    void on_Intelligence_Up_clicked();

    void on_Intelligence_Down_clicked();

    void on_Agility_Up_clicked();

    void on_Agility_Down_clicked();

    void on_Luck_Up_clicked();

    void on_Luck_Down_clicked();

private:
    Ui::MainWindow *ui;
    int strnum, pernum, endnum, charnum, intnum, aginum, lucknum;
};
#endif // MAINWINDOW_H
