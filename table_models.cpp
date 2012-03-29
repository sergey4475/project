#include "table_models.h"

QVariant userTable::data(const QModelIndex &index, int role) const {
    // Чередование цвета строк
    if(role == Qt::BackgroundColorRole) {
        if(index.row() %2){
            return QVariant(QColor(200,220,255));
        }else{
            return QVariant(QColor(255,255,255));
        }
    }
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

  return QSqlQueryModel::data(index, role);
}


