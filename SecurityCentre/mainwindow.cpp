#include "mainwindow.h"
#include "./ui_mainwindow.h"
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
    Simulator* simulator = new Simulator();
    simulator->raise();
    simulator->activateWindow();
    simulator->show();
}

void MainWindow::on_facialRec_Agent_Button_clicked()
{
    auto device = std::dynamic_pointer_cast<AgentDevice>(storage->getDeviceById(1));
    AgentMgmntPanel* facialRecAgentPanel = new AgentMgmntPanel(device);
    facialRecAgentPanel->raise();
    facialRecAgentPanel->activateWindow();
    facialRecAgentPanel->show();
}

