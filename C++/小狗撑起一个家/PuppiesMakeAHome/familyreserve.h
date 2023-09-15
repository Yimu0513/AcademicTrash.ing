#ifndef FAMILYRESERVE_H
#define FAMILYRESERVE_H
//这个类储存商品的动态数组，但是用于存储家庭中的食物储备
#include "product.h"
#include <QVector>
class FamilyReserve
{
public:
    QVector<Product> products[3];  //三种商品
    int ReserveEachSum[3];//各有多少个
    
    FamilyReserve();
    void setFamilyReserve(int item,int num);
    int getFamilyReserve(int item);

    
};

#endif // FAMILYRESERVE_H
