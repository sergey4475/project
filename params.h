#ifndef PARAMS_H
#define PARAMS_H

#define USER_ADD 0
#define USER_EDIT 1

#include <QtCore>
#include <QtSql>
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>

static QSettings set("config.ini",QSettings::IniFormat);
static QString g_hostname       = set.value("Sql/HostName","localhost").toString();
static QString g_dataBase       = set.value("Sql/DataBase","db").toString();
static QString g_login          = set.value("Sql/Login","root").toString();
static QString g_password       = set.value("Sql/Password","admin").toString();
static QString g_driverName     = set.value("Sql/DriverName","QMYSQL").toString();
static int g_connect_port       = set.value("Sql/Port",3306).toInt();
static QSqlDatabase db;

#endif // PARAMS_H
