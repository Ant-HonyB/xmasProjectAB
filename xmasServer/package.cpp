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

float Package::volume()
{
    float myVol = mHeight*mLength*mWidth;
    return myVol;
}

void Package::setWeight()
{
    mWeight = ((float)(rand() % (500 - 10 + 1)) + 10.0)/10.0;
    qDebug() << "myWeight init : " << mWeight;
}

void Package::setClient(QString cl)
{
    mClient = cl;
}

void Package::setDestination(QString dstn)
{
    mCountry = dstn;
}

QByteArray Package::toJSON()
{
    QJsonObject o;
        o["client"] = mClient;
        o["volume"] = this->volume();
        o["country"] = mCountry;
        o["height"] = mHeight;
        o["width"] = mWidth;
        o["length"] = mLength;
        o["weight"] = mWeight;

        QJsonDocument d(o);//transformer en texte
        QByteArray sJson = d.toJson(QJsonDocument::Compact);

        //QJsonObject oRecu = QJsonDocument::fromJson(sJson).object();

        //qDebug() << "Nom" << oRecu["client"].toString();
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




