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
    void addPackage(Package*);
    void setDestination(QString a);
protected:
    QString mDestination;
    QList<Package*> mPackage;
    float mMaxWeight;
    float mMaxVolume;
};

#endif // CAMION_H
