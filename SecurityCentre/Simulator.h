#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Model/DeviceStorage.h"
#include <QWidget>

namespace Ui {
class Simulator;
}

/*!
 * Simulator class implementing methods for simulating signals for devices testing.
 */
class Simulator : public QWidget
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _storage A shared pointer to DeviceStorage instance
     * \param parent A pointer to parent QWidget, default is nullptr
     */
    explicit Simulator(std::shared_ptr<DeviceStorage> _storage, QWidget *parent = nullptr);

    //! A destructor
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
