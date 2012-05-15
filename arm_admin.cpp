#include "arm_admin.h"
#include "ui_arm_admin.h"
#include "table_models.h"

#define t_GENERAL 0
#define t_WORKER 1

#define t_ADMIN 6

arm_admin::arm_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::arm_admin)
{
    ui->setupUi(this);
}


//}


arm_admin::~arm_admin()
{
    delete ui;
}

// ------------------ Инициализация формы ----------------
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

// ------------------ Инициализация вкладок --------------
void arm_admin::init_tab(){
    //Вкладка сотрудники
    if (ui->Tab->currentIndex() == t_WORKER){
        QSqlQuery query;
        query.exec("SELECT FName, IName, OName, qualification.name, IsAdministrator, worker.Deleted "
                   "FROM worker LEFT JOIN qualification ON worker.IDqualification = qualification.id");
        peopleTable *sotrModel = new peopleTable;
        sotrModel->setQuery(query);
        sotrModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Фамилия"));
        sotrModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Имя"));
        sotrModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Отчество"));
        sotrModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Квалификация"));
        ui->tWorker->setModel(sotrModel);
        ui->tWorker->hideColumn(3);
        ui->tWorker->hideColumn(5);

    }

    //Вкладка администрирование
    if (ui->Tab->currentIndex() == t_ADMIN){
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
        query.exec("SELECT UserName, RealUserName, ID, Blocked, Deleted "
                   " FROM sys_users");
        peopleTable *userTab = new peopleTable;
        userTab->setQuery(query);
        userTab->setHeaderData(0,Qt::Horizontal,QObject::tr("Имя пользователя"));
        userTab->setHeaderData(1,Qt::Horizontal,QObject::tr("Полное имя"));
        ui->table_users->setModel(userTab);
        ui->table_users->hideColumn(2);
        ui->table_users->hideColumn(3);
        ui->table_users->hideColumn(4);

        ui->table_users->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    }
}


void arm_admin::on_Tab_currentChanged(int index)
{
    init_tab();
}

//******************************** АДМИНИСТРИРОВАНИЕ ***************************
// ============================= Настройка баз данных ==========================
// проверка соединения
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
// сохранение настроек
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
// ======================================================================================

// ============================= Настройка пользователей ==========================
// кнопка добавить пользователя
void arm_admin::on_add_user_clicked()
{
    frmUser *fUsers = new frmUser();
    fUsers->Init(USER_ADD,0,this);
    fUsers->show();
}
// кнопка редактировать пользователя
void arm_admin::on_edit_user_clicked()
{
    QModelIndex ID = ui->table_users->model()->index(ui->table_users->currentIndex().row(),2);
    int IDClients = ID.data().toInt();

    frmUser *fUsers = new frmUser();
    fUsers->Init(USER_EDIT,IDClients,this);
    fUsers->show();

}

void arm_admin::on_table_users_activated(const QModelIndex &index)
{
    on_edit_user_clicked();
}
