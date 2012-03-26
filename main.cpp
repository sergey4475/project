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

    QFile file(":/styles/default.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);

    mainForm w;

    LoginUser *frmLogin = new LoginUser(0);
    frmLogin->setModal(true);
    frmLogin->Init(&w);
    frmLogin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    frmLogin->show();

    return a.exec();
}
