#ifndef WIDGETSERVEUR_H
#define WIDGETSERVEUR_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include "package.h"
#include "camion.h"


namespace Ui {
class WidgetServeur;
}

class WidgetServeur : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetServeur(QWidget *parent = nullptr);
    ~WidgetServeur();

private slots:
    void clientConnected();
    void clientDisconnected();
    void dataIsComing();

private:
    Ui::WidgetServeur *ui;
     QTcpSocket* mSockClient;
     QList<Camion*> mCamionList;
};

#endif // WIDGETSERVEUR_H
