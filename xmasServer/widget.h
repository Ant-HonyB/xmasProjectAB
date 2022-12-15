#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QMap>
#include <QList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTableWidgetItem>
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
    void infoToTable(Package* pack, QString destination);

private:
    Ui::Widget *ui;
    QTcpServer* mServer;
    QList <QString> destinationList {"Allemagne","France","Espagne"};
    QMap<QString,Camion*> mListCamion;
};
#endif // WIDGET_H
