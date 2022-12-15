#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <QTcpServer>
#include <QTcpSocket>
#include "camion.h"
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

private slots:
    void clientConnected();
    void dataIsComing();

private:
    Ui::Widget *ui;
    QTcpServer* mServer;
    QList <QString> destinationList {"allemagne","france","espagne"};
    QMap<QString,Camion*> mListCamion;
};
#endif // WIDGET_H
