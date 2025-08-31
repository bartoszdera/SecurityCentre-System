#ifndef DETECTORMGMNTPANEL_H
#define DETECTORMGMNTPANEL_H

#include "Model/DetectorDevice.h"
#include <QWidget>
#include <memory>

namespace Ui {
class DetectorMgmntPanel;
}

/*!
 * DetectorMgmntPanel class representing the management panel for a detector device.
 */
class DetectorMgmntPanel : public QWidget
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _device A shared pointer to a DetectorDevice object representing the device to be managed
     * \param parent A pointer to the parent QWidget, defaulting to nullptr
     */
    explicit DetectorMgmntPanel(std::shared_ptr<DetectorDevice> _device, QWidget *parent = nullptr);

    //! A destructor
    ~DetectorMgmntPanel();

private:
    Ui::DetectorMgmntPanel *ui;
    std::shared_ptr<DetectorDevice> device;

public slots:
    void handleNewLog();
    void on_changeStatus_button_clicked();
};

#endif // DETECTORMGMNTPANEL_H
