#ifndef FRMLISTSPR_H
#define FRMLISTSPR_H

#include <QWidget>

namespace Ui {
class frmListSpr;
}

class frmListSpr : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmListSpr(QWidget *parent = 0);
    ~frmListSpr();
    
private:
    Ui::frmListSpr *ui;
};

#endif // FRMLISTSPR_H
