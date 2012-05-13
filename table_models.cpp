#include "table_models.h"

QVariant defModel::data(const QModelIndex &index, int role) const{
    if(role == Qt::BackgroundColorRole) {
        if(index.row() %2){
            return QVariant(QColor(230,230,250));
        }else{
            return QVariant(QColor(255,255,255));
        }
    }

    return QSqlQueryModel::data(index, role);
}

QVariant peopleTable::data(const QModelIndex &index, int role) const {
    // Чередование цвета строк
    if(role == Qt::DecorationRole){
      int Blocked = record(index.row()).value("Blocked").toBool();
      int Deleted = record(index.row()).value("Deleted").toBool();
      QImage image;
      if (index.column() == 0) {
          if (Blocked == true)
              image.load(":/image/icons/UserSecure24.png");
          else if (Deleted == true)
              image.load(":/image/icons/UserDelete24.png");
          else
              image.load(":/image/icons/User24.png");
          }
        return image;
      }

  return defModel::data(index, role);
}

QVariant peopleTable::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Vertical)
        return QVariant(section + 1);
    else
        switch (section) {
            case 0:
                return QVariant("Фамилия");
            case 1:
                return QVariant("Имя");
            case 2:
                return QVariant("Отчество");
}
    return QSqlQueryModel::headerData(section,orientation, role);
}
