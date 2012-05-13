#ifndef TABLE_MODELS_H
#define TABLE_MODELS_H

#include "global_module.h"

class defModel : public QSqlQueryModel{
public:
    QVariant data(const QModelIndex &index, int role) const;
};

class peopleTable : public defModel {
   QVariant data(const QModelIndex &index, int role) const;
   QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};



#endif // TABLE_MODELS_H
