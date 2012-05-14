#include <QtCore>
#include <QtSql>
#include "sqlprocessor.h"

SqlProcessor::SqlProcessor(const QString &log_name)
{
  QTextCodec	*logcodec;

    logcodec = QTextCodec::codecForName("System");

    logFile.setFileName(log_name);
    m_ok = logFile.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!m_ok)
    {
        qDebug() << "Error open  log file"/* << endl*/;
    }
    log.setDevice(&logFile);
    log.setCodec(logcodec);
}

SqlProcessor::~SqlProcessor()
{
    logFile.close();
}


void SqlProcessor::setDb(const QSqlDatabase &db_name)
{
    dbName = db_name;
}

void SqlProcessor::setSqlScript(const QString &script)
{
  QFile			file(script);
  QTextStream	in(&file);
  //QTextCodec 	*incodec;

  QTextStream	error(stderr);
  QString		scriptText;

    m_ok = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!m_ok)
    {
        error << "Error open  script file" << endl;
        return;
    }

    scriptText = in.readAll();
    file.close();

    log << endl << "-----------------------------------------------------" << endl;

    scriptList = scriptText.split(";");
}



bool SqlProcessor::run()
{
    if (!m_ok || scriptList.isEmpty())
        return m_ok;

  QSqlDatabase	db = dbName;
  QSqlQuery		q(db);
  QTextStream	error(stderr);

    log << endl;
    log << endl;
    log << "-------------- EXECUTE ----------------------";
    log << endl;
    log << endl;
    // Исполняем запросы
    int cnt=0;
    foreach(QString str, scriptList)
    {
        //db.transaction();
        if (str.isEmpty())
            continue;

        log << "QUERY #:" << cnt;
        log << endl;
        log << str;
        log << endl;
        m_ok = q.exec(str);
        if (!m_ok)
        {
            QSqlError	e = q.lastError();
            if (e.type() != QSqlError::NoError)
            {
                QString		qerr = e.text();
                //db.rollback();
                log << endl;
                log << "Unable execute query." << endl;
                log << "Resson:" << endl;
                log << qerr << endl;
                log << endl;
                log << "-----------------------------------------------------" << endl;
                log << endl;
                error << "ERROR.\nResson:" << endl;
                error << qerr << endl;
                return false;
            }
            else
            {
                log << endl;
                log << "Query Warining" << endl;
                log << "-----------------------------------------------------" << endl;
                log << endl;
            }
        }
        else
        {
            log << endl;
            log << "Query OK" << endl;
            log << "-----------------------------------------------------" << endl;
            log << endl;
        }
        //db.commit();
        ++cnt;
    }
    return true;
}
