#include "frmuser.h"
#include "ui_frmuser.h"

frmUser::frmUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmUser)
{
    ui->setupUi(this);
}

frmUser::~frmUser()
{
    delete ui;
}
