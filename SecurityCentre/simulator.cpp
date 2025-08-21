#include "simulator.h"
#include "Model/AgentDevice.h"
#include "Model/DeviceStorage.h"
#include "ui_simulator.h"
#include <memory>
#include <qwidget.h>

Simulator::Simulator(std::shared_ptr<DeviceStorage> _storage, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulator),
    storage(_storage)
{
    ui->setupUi(this);
}

Simulator::~Simulator()
{
    delete ui;
}

void Simulator::on_facial_Authorized_Try_clicked()
{
    auto facialAgent = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(1));
    facialAgent->verifyAccess(std::string("twarz1"));
}


void Simulator::on_facial_Unauthorized_Try_clicked()
{
    auto facialAgent = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(1));
    facialAgent->verifyAccess(std::string("twarz0"));
}


void Simulator::on_rfid_Authorized_Try_clicked()
{
    auto rfidAgent = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(2));
    rfidAgent->verifyAccess(15);
}


void Simulator::on_rfid_Unauthorized_Try_clicked()
{
    auto rfidAgent = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(2));
    rfidAgent->verifyAccess(475);
}


void Simulator::on_fingerprint_Authorized_Try_clicked()
{
    auto fingerprintAgent = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(3));
    fingerprintAgent->verifyAccess(237945778L);
}


void Simulator::on_fingerprint_Unauthorized_Try_clicked()
{
    auto fingerprintAgent = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(3));
    fingerprintAgent->verifyAccess(74358L);
}

