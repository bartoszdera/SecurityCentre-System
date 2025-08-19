#ifndef MAINWINDOW_KOPIA_H
#define MAINWINDOW_KOPIA_H

#include <QMainWindow>
#include <string>
#include "Model/agent.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void choosenAgentID(std::string idValue);
    void choosenAgentInfo(std::string infoValue);
    void choosenAgentState(bool stateValue);
    void choosenAgentLogs(std::vector<std::string> logsValue);

signals:
    void agentChoosen(int arg1);
    void agentStateChanged(int arg1);

private slots:
    void on_button_ChangeAgentState_clicked();
    void on_spinBox_agentChoice_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_KOPIA_H
