#include "AgentMgmntPanel.h"
#include "Model/AgentDevice.h"
#include "Model/ElectronicDevice.h"
#include "ui_AgentMgmntPanel.h"

AgentMgmntPanel::AgentMgmntPanel(std::shared_ptr<AgentDevice> _device, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MgmntPanel)
    , device(_device)
{
    ui->setupUi(this);
    ui->label_id->setText(QString("%1").arg(device->getId()));
    // TODO: ustawienie poprawnego labela statusu

    auto logs = device->getLogs();
    for (auto log : logs)
    {
        ui->logs_plainTextEdit->appendPlainText(QString::fromStdString(log));
    }
}

AgentMgmntPanel::~AgentMgmntPanel()
{
    delete ui;
}

void AgentMgmntPanel::on_changeStatus_button_clicked()
{
    device->toggleStatus();
    QString statusText = device->getStatus() == ElectronicDevice::DeviceStatus::ON
                             ? QString("ON")
                             : QString("OFF");
    ui->changeStatus_button->setText(QString("%1").arg(statusText));
}

void AgentMgmntPanel::handleNewLog()
{
    ui->logs_plainTextEdit->appendPlainText(QString::fromStdString(device->getLogs().back()));
}
