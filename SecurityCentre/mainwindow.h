#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void agentCreated(int id_, bool boolState, std::string description_, std::vector<Agent::AuthLog> logs_);
    void stateChanged(bool boolState);
    void on_button_ChangeState_clicked();

signals:
    void changeState();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
