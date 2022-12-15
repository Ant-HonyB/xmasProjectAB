#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mServer = new QTcpServer(this);
    connect(mServer,SIGNAL(newConnection()),this,SLOT(clientConnected()));
    mServer->listen(QHostAddress::Any,4044);
    }

    Widget::~Widget()
    {
        delete ui;
    }

    void Widget::clientConnected()
    {
        QTcpSocket* sockClient = mServer->nextPendingConnection();
        connect(sockClient,SIGNAL(readyRead()),this,SLOT(dataIsComing()));
        connect(sockClient,SIGNAL(disconnected()),sockClient,SLOT(deleteLater()));
        qDebug() << "Un nouveau client se connecte : " << sockClient->peerAddress().toString();
        sockClient->write("Bonjour !");
    }

    void Widget::dataFromClient()
    {
        QTcpSocket* sock = (QTcpSocket*)sender();
        qDebug() << "Colis demandé par le client" << sock->peerAddress().toString() << ":"<< sock->readAll();
    }

