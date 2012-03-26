#ifndef ARM_ADMIN_H
#define ARM_ADMIN_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class arm_admin;
}

class arm_admin : public QWidget
{
    Q_OBJECT
    
public:
    explicit arm_admin(QWidget *parent = 0);
    void init();
    ~arm_admin();
    
private:
    Ui::arm_admin *ui;
};

#endif // ARM_ADMIN_H
