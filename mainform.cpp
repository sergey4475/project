#include "mainform.h"
#include "frmlistspr.h"
#include "arm_admin.h"
#include "ui_mainform.h"

mainForm::mainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainForm)
{
    ui->setupUi(this);
    Init();
}

void mainForm::Init(){
    arm_admin *frm_arm = new arm_admin;
    ui->mdiArea->addSubWindow(frm_arm,Qt::Window);
    frm_arm->setAttribute(Qt::WA_SetWindowIcon);
    frm_arm->init();
    frm_arm->showMaximized();
}

mainForm::~mainForm()
{
    delete ui;
    db.close();
}

void mainForm::on_openSprList_triggered()
{
    frmListSpr *frmList = new frmListSpr;
    ui->mdiArea->addSubWindow(frmList,Qt::Window);
    frmList->setAttribute(Qt::WA_QuitOnClose);
    frmList->show();
}
