#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    checkMoney();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkMoney(){
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);


    if (this->money >= 100){
        ui->pbCoffee->setEnabled(true);
    }
    if (this->money >= 150){
        ui->pbTea->setEnabled(true);
    }
    if (this->money >= 200){
        ui->pbMilk->setEnabled(true);
    }
}

void MainWindow::changeMoney(int diff){

    this->money += diff;

    if (diff == 0){
        this->money = 0;
    }
    checkMoney();


    ui->lcdNumber->display(this->money);
}

void MainWindow::on_pbReset_clicked()
{
    QMessageBox m;
    m.information(nullptr, "잔돈을 반환합니다", QString::number(this->money));
    changeMoney(0);
}

void MainWindow::on_pb10_clicked()
{
    changeMoney(10);
}

void MainWindow::on_pb50_clicked()
{
    changeMoney(50);
}

void MainWindow::on_pb100_clicked()
{
    changeMoney(100);
}

void MainWindow::on_pb500_clicked()
{
    changeMoney(500);
}

void MainWindow::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void MainWindow::on_pbTea_clicked()
{
    changeMoney(-150);
}

void MainWindow::on_pbMilk_clicked()
{
    changeMoney(-200);
}
