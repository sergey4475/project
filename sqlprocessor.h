#ifndef SQLPROCESSOR_H
#define SQLPROCESSOR_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QSqlDatabase>

class SqlProcessor
{
public:
    SqlProcessor(const QString &log_name);
    ~SqlProcessor();

    void setDb(const QSqlDatabase &db_name);
    void setSqlScript(const QString &script);
    bool run();

private:
    bool		m_ok;
    QSqlDatabase dbName;
    QString		logName;
    QStringList	scriptList;
    QTextStream	log;
    QFile		logFile;
};

#endif // SQLPROCESSOR_H
