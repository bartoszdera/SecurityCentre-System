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

/*!
 * MainWindow class implementing signals handles for the main window of the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _storage A shared pointer to DeviceStorage instance
     * \param parent A pointer to parent QWidget, default is nullptr
     */
    MainWindow(std::shared_ptr<DeviceStorage> _storage, QWidget *parent = nullptr);

    //! A destructor
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<DeviceStorage> storage;

private slots:
    void on_actionOtworz_triggered();
    void on_facialRec_Agent_Button_clicked();
    void on_rfid_Agent_Button_clicked();
    void on_fingerprint_Agent_Button_clicked();
    void on_smoke_Detector_Sensor_Button_clicked();
    void on_motion_Corridor_Sensor_Button_clicked();
    void on_motion_Conference_Room_Sensor_Button_clicked();

public slots:
    void accessGranted(int deviceId);
    void accessDenied(int deviceId);
    void signalRegistered(int deviceId);

};
#endif // MAINWINDOW_H
