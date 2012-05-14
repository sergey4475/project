#include "frmuser.h"
#include "arm_admin.h"
#include "ui_frmuser.h"

frmUser::frmUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmUser)
{
    ui->setupUi(this);
}

frmUser::~frmUser()
{
    QObject *prnt = parent;
    arm_admin *myClass = qobject_cast<arm_admin*>(prnt);
    if (myClass)
          myClass->init_tab();
      else
          qDebug() << "Error parent not MyClass";
    delete ui;
}

void frmUser::Init(int type_rec,int IDCurrenUser,QObject *prnt){
    parent = prnt;
    TypeRecord      = type_rec;
    IDCurrenUser_   =IDCurrenUser;

    QSqlQuery sql;
    sql.exec("SELECT "
             "  sys_usersrole.IDRoleUser AS UserRoleID, "
             "  sys_usersrole.RoleName AS RoleName "
             "FROM "
             "  sys_usersrole ");
    while (sql.next())
        ui->UserRole->addItem(sql.value(1).toString(),sql.value(0).toInt());

    //---------------------- Редактирование текущего пользователя -----------------------
    if (TypeRecord == USER_EDIT){
        sql.prepare("SELECT "
                 "  sys_users.UserName, "
                 "  sys_users.RealUserName, "
                 "  sys_users.Blocked, "
                 "  sys_users.IDRoleUser "
                 "FROM "
                 "  sys_users "
                 "WHERE "
                 "  sys_users.ID = :IDCurrenUser");
        sql.bindValue(":IDCurrenUser",IDCurrenUser);
        sql.exec();
        while (sql.next()){
            ui->UserName->setText(sql.value(0).toString());
            ui->RealUserName->setText(sql.value(1).toString());
            ui->Blocked->setChecked(sql.value(2).toBool());
            //ui->UserRole->setCurrentIndex(sql.value(3).toInt());
            ui->UserRole->setCurrentIndex(ui->UserRole->findData(sql.value(3).toInt()));
        }
    }
}

void frmUser::on_butApply_clicked()
{
    QSqlQuery sql;
    // -------------------------- Добавление нового пользователя ---------------------------
    if (TypeRecord == USER_ADD){
        sql.exec("SELECT UserName FROM sys_users WHERE UserName="+ui->UserName->text());
        if (sql.record().count() == 0){
            if (ui->password->text() == ui->password2->text()){
                sql.prepare("INSERT INTO sys_users(UserName,RealUserName, UserPassword, Blocked) "
                            " VALUES(:UserName,:RealUserName,:password, :Blocked)");
                sql.bindValue(":UserName",ui->UserName->text());
                sql.bindValue(":RealUserName",ui->RealUserName->text());
                sql.bindValue(":UserPassword",hash(ui->password->text()));
                sql.bindValue(":Blocked",ui->Blocked->checkState());
                sql.exec();
                close();
            }else
                QMessageBox::warning(0,"Ошибка добавления пользователя","Пароли не совпадают",QMessageBox::Ok);
        }else
            QMessageBox::warning(0,"Ошибка добавления пользователя","Данное имя ползователя уже существует",QMessageBox::Ok);
    }
    if (TypeRecord == USER_EDIT){
        sql.prepare("UPDATE sys_users  SET UserName = :UserName,RealUserName = :RealUserName, Blocked = :Blocked "
                    "WHERE ID = :IDCurrenUser");
        sql.bindValue(":UserName",ui->UserName->text());
        sql.bindValue(":RealUserName",ui->RealUserName->text());
        sql.bindValue(":Blocked",ui->Blocked->checkState());
        sql.bindValue("IDCurrenUser",IDCurrenUser_);
        sql.exec();
        close();
    }
    QObject *prnt = parent;
    arm_admin *myClass = qobject_cast<arm_admin*>(prnt);
    if (myClass)
          myClass->init_tab();
      else
          qDebug() << "Error parent not MyClass";

}
