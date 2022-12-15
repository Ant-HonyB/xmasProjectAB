#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
        mServer = new QTcpServer(this);
        connect(mServer,SIGNAL(newConnection()),this,SLOT(clientConnected()));
        mServer->listen(QHostAddress::Any,9090);
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
        qDebug() << "qqun frappe à la porte" << sockClient->peerAddress().toString();

        sockClient->write("Coucou");
    }

    void Widget::dataIsComing()
    {
        QTcpSocket* sock = (QTcpSocket*)sender();
        qDebug() << "Message recu depuis" << sock->peerAddress().toString() << ":"<< sock->readAll();
    }

