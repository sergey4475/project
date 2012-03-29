#ifndef FRMUSER_H
#define FRMUSER_H

#include <QWidget>

namespace Ui {
class frmUser;
}

class frmUser : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmUser(QWidget *parent = 0);
    ~frmUser();
    
private:
    Ui::frmUser *ui;
};

#endif // FRMUSER_H
