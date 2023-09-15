#include "dog.h"
#include "family.h"
#include "config.h"
#include <QMessageBox>
#include <QInputDialog>

const QString allName[2]={"大型犬","小型犬"};  //狗的分类


Dog::Dog()
{
    ill=0;
    ability=0;
    energy=10;
    state=0;
    worktime=0;
}

Dog::~Dog() {}

void Dog::DogGrow()
{
    if(ill==1||energy<=0.0) return;  //如果小狗生病了，就直接退回不会发生经历的的消耗

    if(state==0)
    {
        if(energy-1<=0.0)
        {
            energy=0.0;
        }
        else
        {
            energy--;  //日常活动默认精力减一
        }

    }
    else
    {
        state=0;
    }

}

void Dog::setDogName(QString Dogname)
{
    name=Dogname;
}

void Dog::setDogEnergy(double Dogenergy)
{
    energy=Dogenergy;
}

void Dog::setDogAbility(int Dogability)
{
    ability=Dogability;
}

void Dog::resetDogIll()
{
    worktime=0;
    ill=0;
}

void Dog::setDogIll(int DogIll)
{
    ill=DogIll;
}

void Dog::setDogState(int Dogstate)
{
    state=Dogstate;
}

void Dog::setDogWorktime(int Worktime)
{
    worktime=Worktime;
}

QString Dog::getDogName()
{
    return name;
}

double Dog::getDogEnergy()
{
    return energy;
}

int Dog::getDogAbility()
{
    return ability;
}

int Dog::getDogIll()
{
    return ill;
}

int Dog::getDogState()
{
    return state;
}

int Dog::getDogWorktime()
{
    return worktime;
}

void Dog::judgeDogIll()
{
    if(energy==0.0)
    {
        ill=1;
    }

    if(worktime==5)
    {
        ill=1;
    }
}

void Dog::doHousework()
{
    if (energy >= 2)
    {
        energy --;
        ability ++;
        worktime ++;
        QMessageBox::warning(nullptr, "做家务", "小狗帮忙家务一小时，快夸夸小狗！\n");
        state=1;
    }
    else
    {
        QMessageBox::warning(nullptr, "做家务", "小狗很累，快为小狗补充体力吧！\n");
    }
}

BigDog::BigDog(){}

void BigDog::eat(int food)
{
    energy += (food / 2.0);
}

void BigDog::doWork()
{

    if (energy >= 3.0 && ability >= 5)
    {
        energy -= (1 / 2.0);
        ability ++;
        worktime ++;
        QMessageBox::warning(nullptr, "打工", "小狗将出门打工一小时，记得奖励小狗哦！\n");
        state=1;
    }
    else
    {

        if (energy < 3.0)
        {
            QMessageBox::warning(nullptr, "打工", "小狗很累，快为小狗补充体力吧！\n");
        }
        else if (ability < 5)
        {
            QMessageBox::warning(nullptr, "打工", "经验不足被老板劝退了，去做家务增加经验吧！\n");
        }

    }

}

SmallDog::SmallDog(){}

void SmallDog::eat(int food)
{
    energy += food;
}

void SmallDog::doWork()
{
    QString message="";
    if (energy >= 3.0 && ability >= 5)
    {
        energy --;
        ability ++;
        worktime ++;
        QMessageBox::warning(nullptr, "打工", "小狗将出门打工一小时，记得奖励小狗哦！\n");
        state=1;
    }
    else
    {

        if (energy < 3.0)
        {
            QMessageBox::warning(nullptr, "打工", "小狗很累，快为小狗补充体力吧！\n");
        }
        else if (ability < 5)
        {
            QMessageBox::warning(nullptr, "打工", "经验不足被老板劝退了，去做家务增加经验吧！\n");
        }
    }
}

