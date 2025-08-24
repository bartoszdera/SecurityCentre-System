#ifndef DETECTORMGMNTPANEL_H
#define DETECTORMGMNTPANEL_H

#include "Model/DetectorDevice.h"
#include <QWidget>
#include <memory>

namespace Ui {
class DetectorMgmntPanel;
}

class DetectorMgmntPanel : public QWidget
{
    Q_OBJECT

public:
    explicit DetectorMgmntPanel(std::shared_ptr<DetectorDevice> _device, QWidget *parent = nullptr);
    ~DetectorMgmntPanel();

private:
    Ui::DetectorMgmntPanel *ui;
    std::shared_ptr<DetectorDevice> device;

public slots:
    void handleNewLog();
    void on_changeStatus_button_clicked();
};

#endif // DETECTORMGMNTPANEL_H
