#ifndef ARM_ADMIN_H
#define ARM_ADMIN_H

#include <QWidget>
#include <QtSql>
#include "params.h"
#include "global_module.h"

namespace Ui {
class arm_admin;
}

class arm_admin : public QWidget
{
    Q_OBJECT
    
public:
    explicit arm_admin(QWidget *parent = 0);
    void init();
    void init_tab();
    ~arm_admin();
    
private slots:
    void on_Tab_currentChanged(int index);

    void on_testBUt_clicked();

    void on_save_button_clicked();

    void on_add_user_clicked();

    void on_save_user();

private:
    Ui::arm_admin *ui;
};

#endif // ARM_ADMIN_H
