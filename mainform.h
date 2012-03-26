#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include "global_module.h"

namespace Ui {
class mainForm;
}

class mainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit mainForm(QWidget *parent = 0);
    void Init();
    ~mainForm();
    
private slots:
    void on_openSprList_triggered();

private:
    Ui::mainForm *ui;
};

#endif // MAINFORM_H
