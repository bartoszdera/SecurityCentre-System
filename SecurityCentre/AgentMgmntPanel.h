#ifndef AGENTMGMNTPANEL_H
#define AGENTMGMNTPANEL_H

#include "Model/AgentDevice.h"
#include <QWidget>

namespace Ui {
class MgmntPanel;
}

class AgentMgmntPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AgentMgmntPanel(std::shared_ptr<AgentDevice> _device, QWidget *parent = nullptr);
    ~AgentMgmntPanel();

private:
    Ui::MgmntPanel *ui;
    std::shared_ptr<AgentDevice> device;

public slots:
    void on_changeStatus_button_clicked();
    void handleNewLog();
};

#endif // AGENTMGMNTPANEL_H
