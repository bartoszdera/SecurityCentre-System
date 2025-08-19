#ifndef MGMNT_PANEL_H
#define MGMNT_PANEL_H

#include "Model/AgentDevice.h"
#include <QWidget>

namespace Ui {
class MgmntPanel;
}

class MgmntPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MgmntPanel(std::shared_ptr<AgentDevice> _device, QWidget *parent = nullptr);
    ~MgmntPanel();

signals:
    void temp(int argument);

private slots:
    void on_changeStatus_button_clicked();

private:
    Ui::MgmntPanel *ui;
    std::shared_ptr<AgentDevice> device;
};

#endif // MGMNT_PANEL_H
