#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void dataFromClient();

private:
    Ui::Widget *ui;
    QTcpServer* mServer;
    QList<Camion*> mListCamion;
};
#endif // WIDGET_H
