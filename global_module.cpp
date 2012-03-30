#include "global_module.h"

void ConnectDB(QString g_hostname, QString g_dataBaseName, QString UserName, QString g_password, QString DriverBD, int g_connect_port){
    db = QSqlDatabase::addDatabase(DriverBD);
    db.close();
    db.setHostName(g_hostname);
    db.setDatabaseName(g_dataBaseName);
    db.setUserName(UserName);
    db.setPassword(g_password);
    db.setPort(g_connect_port);
    if (! db.open()){
        QMessageBox::critical(0,"Ошибка подключения",db.lastError().text(),QMessageBox::Ok);
        db.close();
    }
//   return db;
}

QString hash(QString strParam){
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(strParam.toAscii());
    return (hash.result().toHex());
}

