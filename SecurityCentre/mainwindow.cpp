#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Model/ElectronicDevice.h"
#include "agent_mgmnt_panel.h"
#include "simulator.h"
#include <memory>
#include <qobject.h>
#include <qwidget.h>

MainWindow::MainWindow(std::shared_ptr<DeviceStorage> _storage, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , storage(_storage)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOtworz_triggered()
{
    Simulator* simulator = new Simulator(storage);
    simulator->raise();
    simulator->activateWindow();
    simulator->show();
}

void MainWindow::on_facialRec_Agent_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(1));
    AgentMgmntPanel* facialRecAgentPanel = new AgentMgmntPanel(device);
    connect(device.get(), &ElectronicDevice::newLogAdded, facialRecAgentPanel, &AgentMgmntPanel::handleNewLog);

    facialRecAgentPanel->raise();
    facialRecAgentPanel->activateWindow();
    facialRecAgentPanel->show();
}


void MainWindow::on_rfid_Agent_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(2));
    AgentMgmntPanel* rfidAgentPanel = new AgentMgmntPanel(device);
    connect(device.get(), &ElectronicDevice::newLogAdded, rfidAgentPanel, &AgentMgmntPanel::handleNewLog);

    rfidAgentPanel->raise();
    rfidAgentPanel->activateWindow();
    rfidAgentPanel->show();
}


void MainWindow::on_fingerprint_Agent_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(3));
    AgentMgmntPanel* fingerprintAgentPanel = new AgentMgmntPanel(device);
    connect(device.get(), &ElectronicDevice::newLogAdded, fingerprintAgentPanel, &AgentMgmntPanel::handleNewLog);

    fingerprintAgentPanel->raise();
    fingerprintAgentPanel->activateWindow();
    fingerprintAgentPanel->show();
}

