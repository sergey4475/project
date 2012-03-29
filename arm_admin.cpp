#include "arm_admin.h"
#include "ui_arm_admin.h"
#include "table_models.h"

#define t_GENERAL 0
#define t_CLIENTS 1

#define t_ADMIN 6

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
    init_tab();
}

void arm_admin::init_tab(){
    //Вкладка администрирование

    if (ui->Tab->currentIndex()==6){
        ui->DriversDB->clear();
        QSqlDatabase db_;
        int count = db_.drivers().count();

        for (int i=0;i<count;++i){
            ui->DriversDB->addItem(db_.drivers().value(i));
        }
        db_.~QSqlDatabase();

        ui->hostname->setText(g_hostname);
        ui->NameDataBase->setText(g_dataBase);
        ui->loginDB->setText(g_login);
        ui->passwordDB->setText(g_password);
        ui->Port->setText(QString("%1").arg(g_connect_port));
        ui->DriversDB->setCurrentIndex(ui->DriversDB->findText(g_driverName));

        QSqlQuery query;
        query.exec("SELECT UserName, RealUserName, Blocked, Deleted "
                   " FROM sys_users");
        userTable *userTab = new userTable;
        userTab->setQuery(query);
        userTab->setHeaderData(0,Qt::Horizontal,QObject::tr("Имя пользователя"));
        userTab->setHeaderData(1,Qt::Horizontal,QObject::tr("Полное имя"));
        ui->table_users->setModel(userTab);
        ui->table_users->hideColumn(2);
        ui->table_users->hideColumn(3);

        ui->table_users->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    }
}


void arm_admin::on_Tab_currentChanged(int index)
{
    init_tab();
}

void arm_admin::on_testBUt_clicked()
{
    QSqlDatabase db_ = QSqlDatabase::addDatabase(ui->DriversDB->currentText());
    db_.close();
    db_.setHostName(ui->hostname->text());
    db_.setDatabaseName(ui->NameDataBase->text());
    db_.setUserName(ui->loginDB->text());
    db_.setPassword(ui->passwordDB->text());
    if (! db_.open()){
         QMessageBox::critical(0,"Ошибка подключения",db.lastError().text(),QMessageBox::Ok);
         db_.close();
    }else{
        QMessageBox::warning(0,"Подключени прошло успешно","Подключение успешно!!!",QMessageBox::Ok);
        db_.close();
    }
    db_.~QSqlDatabase();
}

void arm_admin::on_save_button_clicked()
{
    QSettings settings("config.ini",QSettings::IniFormat);
    settings.setValue("Sql/HostName",ui->hostname->text());
    settings.setValue("Sql/DataBase",ui->NameDataBase->text());
    settings.setValue("Sql/Login",ui->loginDB->text());
    settings.setValue("Sql/Password",ui->passwordDB->text());
    settings.setValue("Sql/Port",ui->Port->text().toInt());
    settings.setValue("Sql/DriverName",ui->DriversDB->currentText());

    g_hostname          = ui->hostname->text();
    g_dataBase          = ui->NameDataBase->text();
    g_login             = ui->loginDB->text();
    g_password          = ui->passwordDB->text();
    g_driverName        = ui->DriversDB->currentText();
    g_connect_port      = ui->Port->text().toInt();

    ConnectDB(g_hostname, g_dataBase, g_login, g_password, g_driverName,g_connect_port);
}
