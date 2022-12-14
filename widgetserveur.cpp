#include "widgetserveur.h"
#include "ui_widgetserveur.h"

WidgetServeur::WidgetServeur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetServeur)
{
    ui->setupUi(this);

}

WidgetServeur::~WidgetServeur()
{
    delete ui;
}


void WidgetServeur::clientConnected()
{
     /*QTcpSocket* sockClient = mServer->nextPendingConnection();
     mClients << sockClient;
     connect(sockClient,SIGNAL(readyRead()),this,SLOT(dataIsComing()));
     connect(sockClient,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));*/
}
void WidgetServeur::clientDisconnected()
{
    /*QTcpSocket* sock = (QTcpSocket*)sender();
    mClients.removeAll(sock);
    sock->deleteLater();*/
}
void WidgetServeur::dataIsComing()
{
    /*QTcpSocket* sock = (QTcpSocket*)sender();
    QByteArray data = sock->readAll();

    for(QTcpSocket* s : mClients)
        s->write(data);*/
}
