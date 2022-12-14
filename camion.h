#ifndef CAMION_H
#define CAMION_H
#include <QWidget>
#include "package.h"

class Camion
{
public:
    Camion();
    ~Camion();
    float totalVolume();
    float totalWeight();
    void transportVoucher(QString);
    bool addPackage(Package);
protected:
    QString mDestination;
    QList<Package> mPackage;
    float mMaxWeight;
    float mMaxVolume;
};

#endif // CAMION_H
