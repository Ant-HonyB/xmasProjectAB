#include "widget.h"
#include "./ui_widget.h"
#define PORT 9090

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1 initialisation des camions dans l'espace de stockage
    Camion* deutschTruck = new Camion;
    deutschTruck->setDestination(destinationList[0]);
    Camion* frenchTruck = new Camion;
    frenchTruck->setDestination(destinationList[1]);
    Camion* spanishTruck = new Camion;
    spanishTruck->setDestination(destinationList[2]);

    mListCamion.insert(destinationList[2],spanishTruck);
    mListCamion.insert(destinationList[1],frenchTruck);
    mListCamion.insert(destinationList[0],deutschTruck);

    //2 entrée d'un client dans le serveur
    mServer = new QTcpServer(this);
    connect(mServer,SIGNAL(newConnection()),this,SLOT(clientConnected()));
    mServer->listen(QHostAddress::Any,PORT);
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
        qDebug() << "nouveau client, ip : " << sockClient->peerAddress().toString();

        sockClient->write("Bonjour client");
    }

    void Widget::dataIsComing()
    {
        QTcpSocket* sock = (QTcpSocket*)sender();
        QByteArray colInfo = sock->readAll();
        Package* newPack = new Package;
        newPack->fromJSON(colInfo);

        qDebug() << newPack->toJSON(); //reception du colis

        for (int i = 0;i<destinationList.size();i++)
        //en fonction de la destination, on ajoute au bon camion
        {
            qDebug() << "current Dest : " << destinationList.at(i) << "+ " << newPack->getDestination();
            if (newPack->getDestination() == destinationList.at(i))
            {
                qDebug() << "choix destination : " << newPack->getDestination();
                if((mListCamion[destinationList.at(i)]->totalVolume()+newPack->getVolume() <= 40.0)
                        || mListCamion[destinationList.at(i)]->totalWeight()+newPack->getWeight() <= 40.0)
                {
                    qDebug() << "ajout colis :";
                    mListCamion[destinationList.at(i)]->addPackage(newPack);
                    infoToTable(newPack, destinationList.at(i));

                }
                else
                {
                    //faire le voucher et réinitialiser un camion pour cette destination
                }

            }
        }

    }

    void Widget::infoToTable(Package* pack, QString destination)
    {
        QTableWidget *myTab;

        if(destination == destinationList[0])
            myTab = ui->twGermany;
        else if(destination == destinationList[1])
            myTab = ui->twFrance;
        else
            myTab = ui->twSpain;

        myTab->insertRow(0);
        myTab->setItem(0,0,new QTableWidgetItem(pack->getClient(),0));

        QString tempVol = QString::number(pack->getWeight());
        QString tempWeight = QString::number(pack->getVolume());

        myTab->setItem(0,1,new QTableWidgetItem(tempVol,1));
        myTab->setItem(0,2,new QTableWidgetItem(tempWeight,2));
    }

