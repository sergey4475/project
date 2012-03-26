#include "frmlistspr.h"
#include <QToolBar>
#include <QToolButton>
#include "ui_frmlistspr.h"

frmListSpr::frmListSpr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmListSpr)
{
    ui->setupUi(this);
}

frmListSpr::~frmListSpr()
{
    delete ui;
}
