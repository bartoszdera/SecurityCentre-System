#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model/DeviceStorage.h"
#include <QMainWindow>
#include <memory>

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

private slots:

    void on_actionOtworz_triggered();

    void on_facialRec_Agent_Button_clicked();

    void on_rfid_Agent_Button_clicked();

    void on_fingerprint_Agent_Button_clicked();

    void on_smoke_Detector_Sensor_Button_clicked();

    void on_motion_Corridor_Sensor_Button_clicked();

    void on_motion_Conference_Room_Sensor_Button_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<DeviceStorage> storage;
};
#endif // MAINWINDOW_H
