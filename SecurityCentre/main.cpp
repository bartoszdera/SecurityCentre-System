#include "mainwindow.h"
#include "Model/rfidagent.h"

#include <QApplication>
#include <qobject.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    RFIDAgent rfidAgent = RFIDAgent(1);
    QObject::connect(&rfidAgent, &RFIDAgent::stateChanged, &w, &MainWindow::stateChanged);
    QObject::connect(&w, &MainWindow::changeState, &rfidAgent, &RFIDAgent::changeState);
    QObject::connect(&rfidAgent, &RFIDAgent::agentCreated, &w, &MainWindow::agentCreated);
    w.show();
    return a.exec();
}
