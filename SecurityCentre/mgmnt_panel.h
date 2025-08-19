#ifndef MGMNT_PANEL_H
#define MGMNT_PANEL_H

#include <QWidget>

namespace Ui {
class MgmntPanel;
}

class MgmntPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MgmntPanel(QWidget *parent = nullptr);
    ~MgmntPanel();

signals:
    void temp(int argument);

private:
    Ui::MgmntPanel *ui;
};

#endif // MGMNT_PANEL_H
