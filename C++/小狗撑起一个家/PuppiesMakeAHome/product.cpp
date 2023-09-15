#include "product.h"
#include <QString>

Product::Product(QString k,int v,double e)
{
    kind=k;
    value=v;
    energy=e;
}

Product::Product(){}
