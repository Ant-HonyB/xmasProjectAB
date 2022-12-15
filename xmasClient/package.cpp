#include "package.h"

Package::Package()
{

}

Package::Package(float width, float length, float height)
{
    mHeight = height;
    mLength = length;
    mWidth = width;

}

Package::~Package()
{

}

float Package::getVolume()
{
    float myVol = mHeight*mLength*mWidth;
    return myVol;
}

void Package::setWeight()
{
    mWeight = ((float)(rand() % (500 - 10 + 1)) + 10.0)/10.0;
    qDebug() << "myWeight init : " << mWeight;
}

float Package::getWeight()
{
    return mWeight;
}

void Package::setClient(QString cl)
{
    mClient = cl;
}

void Package::setDestination(QString dstn)
{
    mCountry = dstn;
}

QString Package::getDestination()
{
    return mCountry;
}

QByteArray Package::toJSON()
{
    QJsonObject o;
        o["client"] = mClient;
        o["volume"] = this->getVolume();
        o["country"] = mCountry;
        o["height"] = mHeight;
        o["width"] = mWidth;
        o["length"] = mLength;
        o["weight"] = mWeight;

        QJsonDocument d(o);//transformer en texte
        QByteArray sJson = d.toJson(QJsonDocument::Compact);
    return  sJson; //just for compilation
}

void Package::fromJSON(QByteArray colInfo)
{
    QJsonObject oRecu = QJsonDocument::fromJson(colInfo).object();
    mClient = oRecu["client"].toString();
    mCountry = oRecu["country"].toString();
    mHeight = oRecu["height"].toDouble();
    mWidth = oRecu["width"].toDouble();
    mLength = oRecu["length"].toDouble();
    mWeight = oRecu["weight"].toDouble();
}




