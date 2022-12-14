#ifndef PACKAGE_H
#define PACKAGE_H
#include <QWidget>

class Package
{
public:
    Package();
    ~Package();
    QByteArray toJSON();
    void fromJSON(QByteArray);
    float volume();
protected:
    float mHeight;
    float mLength;
    float mWidth;
    float mWeight;
    QString mRecipient;
    QString mCountry;
    QString mType;
};

#endif // PACKAGE_H
