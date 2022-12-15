#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1 : l'utilisateur se connecte
    //QObject::connect(&soc,SIGNAL(connected()),this,SLOT(connexion_OK()));
    connect(ui->pbConnexion,SIGNAL(clicked()),this,SLOT(linkToIP()));
    //connect(mSocket,SIGNAL(connected()),this,SLOT(imConnected()));
    //connect(mSocket,SIGNAL(disconnected()),this,SLOT(imDisconnected()));
    //connect(mSocket,SIGNAL(readyRead()),this,SLOT(dataIscoming()));

    //2 : paramètrage des colis en fonction du type possible (A, B, C)
    Package packA(13,14,15);
    Package packB(15,16,17);
    Package packC(17,18,19);
    mPackageTypes.insert("colis A",packA);
    mPackageTypes.insert("colis B",packB);
    mPackageTypes.insert("colis C",packC);

    //3 : en fonction de la taille, de la destination et du nom du client, création d'un colis personnalisé
    connect(ui->BBconfirmation,SIGNAL(accepted()),this,SLOT(sendData()));
    connect(ui->BBconfirmation,SIGNAL(rejected()),this,SLOT(close()));



    //4 : envoi du colis au serveur.



}

Widget::~Widget()
{
    delete ui;
}

void Widget::linkToIP()
{
    ip = ui->editIP->text();
    mSocket->connectToHost(ip,port);
    qDebug() << "my ip : " << ip;
}

void Widget::clientConnected()
{
     /*QTcpSocket* sockClient = mServer->nextPendingConnection();
     connect(sockClient,SIGNAL(readyRead()),this,SLOT(dataIsComing()));
     connect(sockClient,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));*/
}
void Widget::clientDisconnected()
{
    /*QTcpSocket* sock = (QTcpSocket*)sender();
    mClients.removeAll(sock);
    sock->deleteLater();*/
}
void Widget::dataIsComing()
{
    /*QTcpSocket* sock = (QTcpSocket*)sender();
    mClients.removeAll(sock);
    sock->deleteLater();*/
}

void Widget::sendOrder()
{
    QString myDestination = ui->ComboDestination->currentText();
    QString mySize = ui->comboTaille->currentText();
    QString myName = ui->editNomClient->text();
    qDebug() << myName;

    if(ui->editNomClient->text().size()==0){return;}

    QString a;
    if (mySize == "Petit Cadeau de noël")
    {
        a = "colis A";
    }
    else if(mySize == "Super Cadeau de noël")
    {
        a = "colis B";
    }
    else if(mySize == "Méga Cadeau de noël")
    {
        a = "colis C";
    }
    Package choosedPack = mPackageTypes[a];

    choosedPack.setWeight();
    choosedPack.setClient(myName);
    choosedPack.setDestination(myDestination);

    mSocket->write(choosedPack.toJSON());
}


/*QStringList types = settings.childGroups();

//ui->ComboDestination->addItems(settings.value("pays").toString().split(","));
//ui->comboTaille->addItems(types);*/

//ui->ComboDestination->addItems(settings.value("pays").toString().split(","));

/*
for(QString s : types)
{
    settings.beginGroup(s);
    float width = settings.value("largeur").toFloat();
    qDebug() << width;
    float length =settings.value("longueur").toFloat();
    float heigth = settings.value("hauteur").toFloat();
    //mType[s]=
    settings.endGroup();
}
//Package myPack(width,length,heigth);
*/
