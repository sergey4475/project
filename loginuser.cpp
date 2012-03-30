#include "loginuser.h"
#include "params.h"
#include "ui_loginuser.h"

LoginUser::LoginUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUser)
{
    ui->setupUi(this);
}

LoginUser::~LoginUser()
{
    delete ui;
}

void LoginUser::Init(mainForm *w){
    ConnectDB(g_hostname, g_dataBase, g_login, g_password, g_driverName,g_connect_port);
    QSqlQuery sql;
    sql.prepare("SELECT UserName, RealUserName "
                "FROM sys_users");
    sql.exec();
    while (sql.next()){
        ui->userName->addItem(sql.value(1).toString(),sql.value(0).toString());
    }
    win = w;
}

bool LoginUser::Login(){
    QSqlQuery sql;
    sql.prepare("SELECT UserPassword "
                "FROM sys_users "
                "WHERE UserName=:user ");
    sql.bindValue(":user",ui->userName->itemData(ui->userName->currentIndex()).toString());
    sql.exec();
    sql.next();
    qDebug() << hash(ui->password->text());
    if (sql.value(0) == hash(ui->password->text()))
        return true;
    else
        return false;
}

void LoginUser::on_login_clicked()
{
    if (Login()==true) {
        win->show();
        close();
    }else
        ui->warr->setText("Ошибка авторизации");
    ui->password->clear();
}

void LoginUser::on_chancel_clicked()
{
    qApp->exit();
    close();
}
