#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Model/DetectorDevice.h"
#include "Model/ElectronicDevice.h"
#include "AgentMgmntPanel.h"
#include "DetectorMgmntPanel.h"
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


void MainWindow::on_smoke_Detector_Sensor_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<DetectorDevice>(storage->getDeviceById(4));
    DetectorMgmntPanel* smokeDetectorPanel = new DetectorMgmntPanel(device);
    connect(device.get(), &ElectronicDevice::newLogAdded, smokeDetectorPanel, &DetectorMgmntPanel::handleNewLog);

    smokeDetectorPanel->raise();
    smokeDetectorPanel->activateWindow();
    smokeDetectorPanel->show();
}


void MainWindow::on_motion_Corridor_Sensor_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<DetectorDevice>(storage->getDeviceById(5));
    DetectorMgmntPanel* movementCorridorDetectorPanel = new DetectorMgmntPanel(device);
    connect(device.get(), &ElectronicDevice::newLogAdded, movementCorridorDetectorPanel, &DetectorMgmntPanel::handleNewLog);

    movementCorridorDetectorPanel->raise();
    movementCorridorDetectorPanel->activateWindow();
    movementCorridorDetectorPanel->show();
}


void MainWindow::on_motion_Conference_Room_Sensor_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<DetectorDevice>(storage->getDeviceById(6));
    DetectorMgmntPanel* movementCnferenceRoomDetectorPanel = new DetectorMgmntPanel(device);
    connect(device.get(), &ElectronicDevice::newLogAdded, movementCnferenceRoomDetectorPanel, &DetectorMgmntPanel::handleNewLog);

    movementCnferenceRoomDetectorPanel->raise();
    movementCnferenceRoomDetectorPanel->activateWindow();
    movementCnferenceRoomDetectorPanel->show();
}

