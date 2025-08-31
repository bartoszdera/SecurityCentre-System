#ifndef AGENTMGMNTPANEL_H
#define AGENTMGMNTPANEL_H

#include "Model/AgentDevice.h"
#include <QWidget>

namespace Ui {
class MgmntPanel;
}

/*!
 * AgentMgmntPanel class implementing the management panel for agent devices.
 */
class AgentMgmntPanel : public QWidget
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _device A shared pointer to an AgentDevice object representing the device to be managed
     * \param parent A pointer to the parent QWidget, the default sets to nullptr
     */
    explicit AgentMgmntPanel(std::shared_ptr<AgentDevice> _device, QWidget *parent = nullptr);

    //! A destructor
    ~AgentMgmntPanel();

private:
    Ui::MgmntPanel *ui;
    std::shared_ptr<AgentDevice> device;

public slots:
    void on_changeStatus_button_clicked();
    void handleNewLog();
};

#endif // AGENTMGMNTPANEL_H
