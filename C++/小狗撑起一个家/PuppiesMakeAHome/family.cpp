#include "family.h"
#include <QMessageBox>

void Family::addDog(int i)
{
    member=i;
}


Family::Family(){}

void Family::Initial()
{
    dogs.clear();
    wealth=30;
    love=0;
    member=0;
    reserve_bonse=0;
    reserve_dogfood=0;
    reserve_medicine=0;
    playerTime=0;
}

void Family::setFamilyTitle(QString Familytitle)
{
    title=Familytitle;
}

void Family::setFamilyLove(int Familylove)
{
    love=Familylove;
}

void Family::setFamilyWealth(int FamilyWealth)
{
    wealth=FamilyWealth;
}



void Family::setFamilyReserveDogfood(int Dogfood)
{
    reserve_dogfood=Dogfood;
}

void Family::setFamilyReserveBonse(int Bonse)
{
    reserve_bonse=Bonse;
}

void Family::setFamilyReserveMedicine(int Medicine)
{
    reserve_medicine=Medicine;
}

void Family::setPlayerTime(int time)
{
    playerTime=time;
}

QString Family::getFamilyTitle()
{
    return title;
}

int Family::getFamilyLove()
{
    return love;
}

int Family::getFamilyWealth()
{
    return wealth;
}


int Family::getFamilyReserveDogfood()
{
    return reserve_dogfood;
}

int Family::getFamilyReserveBonse()
{
    return reserve_bonse;
}

int Family::getFamilyReserveMedicine()
{
    return reserve_medicine;
}

int Family::getPlayerTime()
{
    return playerTime;
}

void Family::increaseLove()
{
    love++;
    if(love %10==0 &&love/10>=1)
    {
        QMessageBox::information(nullptr, "奖励", "爱心数量达到十的倍数，恭喜获得一颗爱心奖励！");
        love++;
    }
}

void Family::decreaseLove()
{
    love-=1;
}

void Family::increaseWealth(int amount)
{
    wealth+=amount;
}
void Family::decreaseWealth(int amount)
{
    wealth-=amount;
}



