#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QVector>

class Family
{
private:
    QString title;

public:
    Family(QString t);

    static int love;
    static int wealth;
    static int reserve;

    static void increaseLove();
    static void increaseWealth(int amount);
    static void decreaseWealth(int amount);
    static void increaseReserve(int amount);
    static void decreaseReserve(int amount);

    void output();
};

class Product
{
public:
    QString productName;
    int price;
    int satiety;

public:
    Product(QString n, int p, int s);
    Product();
};

class Shop
{
private:
    QVector<Product> products;

public:
    Shop(QVector<Product> products);
    void addProduct(Product product);
    void purchaseProduct(int index);
    void displayProducts();
};

class Dog
{
protected:
    int ability;
    double energy;
    QString name;

public:
    Dog(QString n, int a, double e);
    virtual ~Dog();
    void doHousework(int time);
    virtual void doWork(int time);
    virtual void eat(int food);
};

class BigDog : public Dog
{
public:
    BigDog(QString n, int a, float e);
    void eat(int food) override;
    void doWork(int time) override;
};

class SmallDog : public Dog
{
public:
    SmallDog(QString n, int a, float e);
    void eat(int food) override;
    void doWork(int time) override;
};

#endif // GAME_H
