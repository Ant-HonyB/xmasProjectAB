#ifndef PACKAGE_H
#define PACKAGE_H
#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class Package
{
public:
    Package();
    Package(float width, float length, float height);
    ~Package();
    QByteArray toJSON();
    void fromJSON(QByteArray colInfo);
    float getVolume();
    void setWeight();
    float getWeight();
    void setClient(QString cl);
    QString getClient();
    void setDestination(QString dstn);
    QString getDestination();
protected:
    float mHeight;
    float mLength;
    float mWidth;
    float mWeight;
    QString mCountry;
    QString mType;
    QString mClient;
};

#endif // PACKAGE_H
