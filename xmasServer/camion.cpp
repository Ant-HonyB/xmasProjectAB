#include "camion.h"

Camion::Camion()
{

}

Camion::~Camion()
{

}

void Camion::setDestination(QString a)
{
    mDestination = a;
}

float Camion::totalVolume()
{
    float totVolume = 0.0;
    for (int i = 0; i<mPackage.size();i++)
    {
        totVolume += totVolume + mPackage[i]->getVolume();
    }
    return totVolume;
}

float Camion::totalWeight()
{
    float totWeight = 0.0;
    for (int i = 0; i<mPackage.size();i++)
    {
        totWeight += totWeight + mPackage[i]->getWeight();
    }
    return totWeight;
}

void Camion::transportVoucher(QString)
{
    //pas encore compris ce que c'était :D
}

void Camion::addPackage(Package* Pack)
{
    mPackage.append(Pack);
}

