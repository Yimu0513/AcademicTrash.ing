#include "game.h"
#include <QTextStream>

// Family implementation
Family::Family(QString t) : title(t) {}

void Family::increaseLove()
{
    love += 1;
}

void Family::increaseWealth(int amount)
{
    wealth += amount;
}

void Family::decreaseWealth(int amount)
{
    wealth -= amount;
}

void Family::increaseReserve(int amount)
{
    reserve += amount;
}

void Family::decreaseReserve(int amount)
{
    reserve -= amount;
}

void Family::output()
{
    QTextStream out(stdout);
    out << "title: " << title << " love: " << love << " wealth: " << wealth << " reserve: " << reserve << endl;
}

int Family::love = 0;
int Family::wealth = 10;
int Family::reserve = 0;

// Product implementation
Product::Product(QString n, int p, int s) : productName(n), price(p), satiety(s) {}

Product::Product() : productName(""), price(0), satiety(0)
{

}

// Shop implementation
Shop::Shop(QVector<Product> products) : products(products) {}

void Shop::addProduct(Product product)
{
    products.push_back(product);
}

void Shop::purchaseProduct(int index)
{
    if (index >= 1 && index <= products.size())
    {
        Product selectedProduct = products[index - 1];
        if (Family::wealth >= selectedProduct.price)
        {
            Family::decreaseWealth(selectedProduct.price);
            Family::increaseReserve(selectedProduct.satiety);
            QTextStream out(stdout);
            out << "Purchased " << selectedProduct.productName << " successfully!" << endl;
            out << "Deduction amount: " << selectedProduct.price << endl;
        }
        else
        {
            QTextStream out(stdout);
            out << "Not enough coins to purchase " << selectedProduct.productName << "!" << endl;
        }
    }
    else
    {
        QTextStream out(stdout);
        out << "Invalid product index!" << endl;
    }
}

void Shop::displayProducts()
{
    QTextStream out(stdout);
    for (int i = 0; i < products.size(); ++i)
    {
        out << "[" << i + 1 << "] " << products[i].productName << " Price: " << products[i].price << " satiety: " << products[i].satiety << endl;
    }
}

// Dog implementation
Dog::Dog(QString n, int a, double e) : name(n), ability(a), energy(e) {}


Dog::~Dog()
{
    // 析构函数为空，因为没有需要释放的资源
}
void Dog::doHousework(int time)
{
    if (energy >= 2)
    {
        energy -= time;
        ability += time;
        Family::increaseLove();
    }
    else
    {
        QTextStream out(stdout);
        out << "Lack of energy, hurry up and replenish energy!" << endl;
    }
}

void Dog::doWork(int time)
{
    energy -= time;
    ability += time;
    Family::increaseWealth(time);
    Family::increaseLove();
}

void Dog::eat(int food)
{
    energy += food;
    Family::decreaseReserve(food);
}

// BigDog implementation
BigDog::BigDog(QString n, int a, float e) : Dog(n, a, e) {}

void BigDog::eat(int food)
{
    energy += (food / 2.0);
    Family::decreaseReserve(food);
}

void BigDog::doWork(int time)
{
    if (energy >= 3.0 && ability >= 5)
    {
        energy -= (time / 2.0);
        ability += time;
        Family::increaseWealth(time * 2);
        Family::increaseLove();
    }
    else
    {
        QTextStream out(stdout);
        if (energy < 3.0)
        {
            out << "Lack of energy, hurry up and replenish energy!" << endl;
        }
        if (ability < 5)
        {
            out << "Insufficient ability, hurry up and do housework to increase your ability" << endl;
        }
    }
}

// SmallDog implementation
SmallDog::SmallDog(QString n, int a, float e) : Dog(n, a, e) {}

void SmallDog::eat(int food)
{
    energy += food;
    Family::decreaseReserve(food);
}

void SmallDog::doWork(int time)
{
    if (energy >= 3.0 && ability >= 5)
    {
        energy -= time;
        ability += time;
        Family::increaseWealth(time);
        Family::increaseLove();
    }
    else
    {
        QTextStream out(stdout);
        if (energy < 3.0)
        {
            out << "Lack of energy, hurry up and replenish energy!" << endl;
        }
        if (ability < 5)
        {
            out << "Insufficient ability, hurry up and do housework to increase your ability" << endl;
        }
    }
}
