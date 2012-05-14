#include <QtGui/QApplication>
#include "mainform.h"
#include "loginuser.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("cp1251");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    a.addLibraryPath(QDir::currentPath()+"/plugins");

    QFile file(":/res/styles/default.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);

    mainForm w;

    ConnectDB(g_hostname, g_dataBase, g_login, g_password, g_driverName,g_connect_port);
    QSqlQuery sql;
    sql.prepare("SELECT UserName, RealUserName "
                "FROM sys_users");
    sql.exec();
    qDebug() << sql.lastError();
    if (!sql.next()){
        QFile file;
        if (g_driverName == "QSQLITE")
            file.setFileName(":/res/scripts/sqlite.sql");
        else if (g_driverName == "QMYSQL")
            file.setFileName(":/res/scripts/mysql.sql");

        file.open(QFile::ReadOnly);
        QString Sql_script = file.readAll();
        QSqlQuery sql(Sql_script,db);
        qDebug() << sql.lastError();
    }


    LoginUser *frmLogin = new LoginUser(0);
    frmLogin->setModal(true);
    frmLogin->Init(&w);
    frmLogin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    frmLogin->show();

    return a.exec();
}
