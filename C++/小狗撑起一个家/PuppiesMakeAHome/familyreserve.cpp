#include "familyreserve.h"


FamilyReserve::FamilyReserve()
{
    for(int i=0;i<3;i++){
        ReserveEachSum[i]=0;
    }
    products->clear();
}

void FamilyReserve::setFamilyReserve(int item,int num)
{
    ReserveEachSum[item]=num;
}

int FamilyReserve::getFamilyReserve(int item)
{
    return ReserveEachSum[item];
}
