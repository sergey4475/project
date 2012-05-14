#ifndef FRMUSER_H
#define FRMUSER_H

#include <QWidget>
#include "params.h"
#include "global_module.h"

namespace Ui {
class frmUser;
}

class frmUser : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmUser(QWidget *parent = 0);
    void Init(int type_rec,int IDCurrenUser = 0, QObject *prnt = 0);
    ~frmUser();
    
private slots:
    void on_butApply_clicked();

private:
    Ui::frmUser *ui;
    int TypeRecord;
    int IDCurrenUser_;
    QObject *parent;
};

#endif // FRMUSER_H
