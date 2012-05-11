#ifndef TABLE_MODELS_H
#define TABLE_MODELS_H

#include "global_module.h"

class defTable : public QSqlQueryModel{
    QVariant data(const QModelIndex &index, int role) const;
};

class userTable : public defTable {
    QVariant data(const QModelIndex &index, int role) const;
};



#endif // TABLE_MODELS_H
