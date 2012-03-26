#include "arm_admin.h"
#include "ui_arm_admin.h"

arm_admin::arm_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::arm_admin)
{
    ui->setupUi(this);
}

arm_admin::~arm_admin()
{
    delete ui;
}

void arm_admin::init(){
    QSqlTableModel *table = new QSqlTableModel;
    table->insertColumn(0);
    table->insertColumn(1);
    table->insertColumn(2);
    table->setHeaderData(0,Qt::Horizontal,"Вид напоминания");
    ui->tPoslednee->setModel(table);
    ui->tPoslednee->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
}
