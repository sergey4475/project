#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <QDialog>
#include "mainform.h"

namespace Ui {
class LoginUser;
}

class LoginUser : public QDialog
{
    Q_OBJECT
    
private:
    mainForm *win;
public:
    explicit LoginUser(QWidget *parent = 0);
    bool Login();
    void Init(mainForm *w);
    ~LoginUser();
    
private slots:
    void on_login_clicked();

    void on_chancel_clicked();

private:
    Ui::LoginUser *ui;
};

#endif // LOGINUSER_H
