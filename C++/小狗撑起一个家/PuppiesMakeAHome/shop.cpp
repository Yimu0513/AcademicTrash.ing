#include "shop.h"
#include "family.h"
#include "product.h"
#include <QMessageBox>

Shop::Shop(const std::vector<Product>& products) : products(products) {}

void Shop::addProduct(const Product& product)
{
    products.push_back(product);
}

void Shop::purchaseProduct(int index)
{
    if (index >= 1 && index <= products.size())
    {
        const Product& selectedProduct = products[index - 1];
        if (Family::wealth >= selectedProduct.price)
        {
            Family::decreaseWealth(selectedProduct.price);
            Family::increaseReserve(selectedProduct.satiety);
            QString message = "Purchased " + selectedProduct.productName + " successfully!\nDeduction amount: " + QString::number(selectedProduct.price);
            QMessageBox::information(nullptr, "Purchase", message);
        }
        else
        {
            QString message = "Not enough coins to purchase " + selectedProduct.productName + "!";
            QMessageBox::warning(nullptr, "Purchase", message);
        }
    }
    else
    {
        QMessageBox::warning(nullptr, "Purchase", "Invalid product index!");
    }
}


