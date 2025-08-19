#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model/DeviceStorage.h"
#include <QMainWindow>
#include <memory>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<DeviceStorage> _storage, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // void choosenAgentID(std::string idValue);
    // void choosenAgentInfo(std::string infoValue);
    // void choosenAgentState(bool stateValue);
    // void choosenAgentLogs(std::vector<std::string> logsValue);

signals:
    // void agentChoosen(int arg1);
    // void agentStateChanged(int arg1);

private slots:
    // void on_button_ChangeAgentState_clicked();
    // void on_spinBox_agentChoice_valueChanged(int arg1);

    void on_actionOtworz_triggered();

    void on_facialRec_Agent_Button_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<DeviceStorage> storage;
};
#endif // MAINWINDOW_H
