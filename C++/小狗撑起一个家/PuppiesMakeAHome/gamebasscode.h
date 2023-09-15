#ifndef GAMEBASSCODE_H
#define GAMEBASSCODE_H


class GameBasscode
{
public:
    GameBasscode();
};



#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 6.20 想不到体重和年龄可以用来干嘛，决定取消这个数据成员
// 锻炼好像也没什么用，删掉
// 6.21 没删东西，把所有的类和函数写完了  抛瓦！

//------------------------------------------家庭类定义部分-------------------------------------------
class Family
{
    private:
    string title;  //家庭的名字
    public:
    Family(string t):title(t){}
    static int love;
    static int wealth;
    static int reserve;  //定义家庭的数据成员，分别是爱心数量，金币余额和食物储备

    static void increaseLove(); //爱心增加的函数


    static void increaseWealth(int amount);  //家庭金币增加的函数

    static void decreaseWealth(int amount);   //家庭金币减少的函数

    static void increaseReserve(int amount);   //家庭食物增加的函数

    static void decreaseReserve(int amount);  //家庭食物减少的函数

};

int Family::love = 0;
int Family::wealth = 10;
int Family::reserve = 0;


//------------------------------------------商店类定义部分-------------------------------------------
class Product
{
    public:
    string productName;
    int price;
    int satiety;   //饱腹感，对应家庭的食物储备
    public:
    Product(string n, int p,int s):productName(n), price(p),satiety(s){}
};

class Shop
{
    private:
    vector<Product> products;  //商店的商品列表

    public:
    Shop(vector<Product> products):products(products) {}
    void addProduct(Product product);
    void purchaseProduct(int index) ;  //购物函数

    void displayProducts();  ///测试函数用于输出商品列表方便我自己的调试

};


//------------------------------------------家庭成员类定义部分-------------------------------------------
//定义一个狗狗类作为基类
class Dog
{
    protected:
    // int age,weight, energy,ability;  //分别是三个动物属性：年龄，体重，精力和能力
    int ability;
    float energy;  //分别是三个动物属性：年龄、精力和能力
    string name;  //小动物的名字

    public:
    //Dog(string n,int ag,int w,int e,int a):name(n),age(ag),weight(w),energy(e),ability(a){}  //动物类的构造函数
    Dog(string n,  int a, float e) : name(n), ability(a), energy(e){}  //动物类的构造函数

    void doHousework(int time);  //做家务的函数声明

    virtual void doWork(int time);  //打工的函数声明
    virtual void eat(int food);   //进食的函数声明

};

//派生大型犬类
class BigDog : public Dog
{
    public:
    BigDog(string n, int a, float e):Dog(n, a, e){}

    void eat(int food) override;
    void doWork(int time) override;

};


//派生小型犬类
class SmallDog : public Dog
{
    public:
    SmallDog(string n, int a, float e):Dog(n, a, e){}

    void eat(int food) override;
    void doWork(int time) override;

};
#endif // GAMEBASSCODE_H
