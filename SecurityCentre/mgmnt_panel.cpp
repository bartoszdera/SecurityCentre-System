#include "mgmnt_panel.h"
#include "ui_mgmnt_panel.h"

MgmntPanel::MgmntPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MgmntPanel)
{
    ui->setupUi(this);
}

MgmntPanel::~MgmntPanel()
{
    delete ui;
}
