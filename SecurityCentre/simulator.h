#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Model/DeviceStorage.h"
#include <QWidget>

namespace Ui {
class Simulator;
}

class Simulator : public QWidget
{
    Q_OBJECT

public:
    explicit Simulator(std::shared_ptr<DeviceStorage> _storage, QWidget *parent = nullptr);
    ~Simulator();

private slots:
    void on_facial_Authorized_Try_clicked();

    void on_facial_Unauthorized_Try_clicked();

    void on_rfid_Authorized_Try_clicked();

    void on_rfid_Unauthorized_Try_clicked();

    void on_fingerprint_Authorized_Try_clicked();

    void on_fingerprint_Unauthorized_Try_clicked();

    void on_Canteen_Smoke_Try_clicked();

    void on_corridor_Movement_Try_clicked();

    void on_meeting_room_Movement_Try_clicked();

private:
    Ui::Simulator *ui;
    std::shared_ptr<DeviceStorage> storage;
};

#endif // SIMULATOR_H
