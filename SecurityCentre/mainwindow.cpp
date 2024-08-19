#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <qobject.h>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::agentCreated(int id_, bool boolState, std::string description_, std::vector<Agent::AuthLog> logs_)
{
    ui->label_ID->setText(QString::fromStdString(std::to_string(id_)));
    ui->label_State->setText("ON");
    ui->textEdit_Description->setText(QString::fromStdString(description_));
    for(Agent::AuthLog log : logs_){
        ui->listWidget->addItem(QString::fromStdString(log.getAuthLog()));
    }
}

void MainWindow::stateChanged(bool boolState){
    if(boolState) {
        ui->label_State->setText("ON");
    }
    else {
        ui->label_State->setText("OFF");
    }
}

void MainWindow::on_button_ChangeState_clicked()
{
    std::cout<<"BUTTON ChangeState CLICKED"<<std::endl;
    emit changeState();
}
