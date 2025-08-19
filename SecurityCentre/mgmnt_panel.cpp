#include "mgmnt_panel.h"
#include "Model/AgentDevice.h"
#include "Model/electronicdevice.h"
#include "ui_mgmnt_panel.h"

MgmntPanel::MgmntPanel(std::shared_ptr<AgentDevice> _device, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MgmntPanel)
    , device(_device)
{
    ui->setupUi(this);
    ui->label_id->setText(QString("%1").arg(device->getId()));
}

MgmntPanel::~MgmntPanel()
{
    delete ui;
}


void MgmntPanel::on_changeStatus_button_clicked()
{
    device->toggleStatus();
    QString statusText = device->getStatus() == ElectronicDevice::DeviceStatus::ON
                             ? QString("ON")
                             : QString("OFF");
    ui->changeStatus_button->setText(QString("%1").arg(statusText));
}
