#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QMap>
#include <QSettings>
#include "package.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots :
    void linkToIP();

private slots:
    void imConnected();
    void dataIsComing();
    void sendOrder();

private:
    Ui::Widget *ui;
    QTcpSocket* mSocket;
    QString ip;
    int port=9090;
    QMap<QString,Package> mPackageTypes;
};
#endif // WIDGET_H
