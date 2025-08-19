#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <qobject.h>

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

void MainWindow::choosenAgentID(std::string idValue)
{
    ui->label_Agent_ID_value->setText(QString::fromStdString(idValue));
}

void MainWindow::choosenAgentInfo(std::string infoValue)
{
    std::cout<<"agentInfo slot triggered"<<std::endl;
    ui->textEdit_Description->setText(QString::fromStdString(infoValue));
}

void MainWindow::choosenAgentState(bool stateValue)
{
    std::cout<<"agentState slot triggered with bool: "<< stateValue <<std::endl;
    if(stateValue) {
        ui->label_Agent_State_value->setText("ON");
    }
    else {
        ui->label_Agent_State_value->setText("OFF");
    }
}

void MainWindow::choosenAgentLogs(std::vector<std::string> logsValue)
{
    ui->listWidget_Agent_logs->clear();
    for(std::vector<std::string>::iterator it = logsValue.begin(); it != logsValue.end(); ++it) {
        ui->listWidget_Agent_logs->addItem(QString::fromStdString(it->data()));
    }
}

void MainWindow::on_button_ChangeAgentState_clicked()
{
    std::cout<<"BUTTON ChangeState CLICKED"<<std::endl;
    emit agentStateChanged(ui->spinBox_agentChoice->value());
}

void MainWindow::on_spinBox_agentChoice_valueChanged(int arg1)
{
    std::cout<<"Agent with ID: " << arg1 << " selected." <<std::endl;
    emit agentChoosen(arg1);
}
