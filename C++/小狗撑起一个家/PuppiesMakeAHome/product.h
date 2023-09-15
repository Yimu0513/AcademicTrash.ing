#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
    QString kind;
    int value;
    double energy;
    
public:
    Product();
    Product(QString k,int v,double e);
};

#endif // PRODUCT_H
