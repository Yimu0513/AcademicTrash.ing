#ifndef DOG_H
#define DOG_H

#include <QPixmap>

class Dog
{
protected:
    int ability;    //能力
    double energy;   //精力
    QString name;   //名字
    int ill;     //疾病状态
    int worktime;  //判断工作时长
    int state;  //判断是否正在忙碌

public:

    //Dog(const QString& n, int a, double e);
    Dog();
    virtual ~Dog();

    void DogGrow();   //日常精力消耗
    void setDogName(QString Dogname);
    void setDogAbility(int Dogability);
    void setDogEnergy(double Dogenergy);
    void resetDogIll();
    void setDogIll(int DogIll);
    void setDogState(int Dogstate);
    void setDogWorktime(int Worktime);

    QString getDogName();
    int getDogAbility();
    double getDogEnergy();
    int getDogIll();
    int getDogState();
    int getDogWorktime();
    void judgeDogIll();

    void doHousework();
    virtual void doWork() = 0;
    virtual void eat(int food) = 0;
};

class BigDog : public Dog
{
public:
    BigDog();
    void eat(int food) override;
    void doWork() override;
};

class SmallDog : public Dog
{
public:
    SmallDog();
    void eat(int food) override;
    void doWork() override;
};

#endif // DOG_H
