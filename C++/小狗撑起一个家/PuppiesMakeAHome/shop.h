#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Product.h"

class Shop
{
private:
    std::vector<Product> products;

public:
    Shop(const std::vector<Product>& products);
    void addProduct(const Product& product);
    void purchaseProduct(int index);
};

#endif // SHOP_H

