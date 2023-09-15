#ifndef FAMILY_H
#define FAMILY_H


#include <QString>
#include <QVector>
#include "dog.h"
#include <QPaintEvent>

class Family
{
private:
    QString title; //家庭的名字
    int love;  //爱心
    int wealth;  //金币
    int playerTime;  //时间

    int reserve_dogfood,reserve_bonse,reserve_medicine;

public:
    QVector<Dog*> dogs;  //动态存储家庭成员
    int member=0;  //用于记录家庭中已经收养的狗狗

    void addDog(int i);  //收养新狗狗

    
    Family();
    void Initial();
    void setFamilyTitle(QString Familytitle);
    void setFamilyLove(int Familylove);
    void setFamilyWealth(int FamilyWealth);

    void setFamilyReserveDogfood(int Dogfood);
    void setFamilyReserveBonse(int Bonse);
    void setFamilyReserveMedicine(int Medicine);

    void setPlayerTime(int time);
    
    QString getFamilyTitle();
    int getFamilyLove();
    int getFamilyWealth();

    int getFamilyReserveDogfood();
    int getFamilyReserveBonse();
    int getFamilyReserveMedicine();

    int getPlayerTime();

    void increaseLove();
    void decreaseLove();

    void increaseWealth(int amount);
    void decreaseWealth(int amount);
    
};


#endif // FAMILY_H
