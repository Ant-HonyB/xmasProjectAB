#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //1 : l'utilisateur se connecte
    connect(ui->pbConnexion,SIGNAL(clicked()),this,SLOT(linkToIP()));


    //connect(ui->pbConnexion,SIGNAL(clicked()),this,SLOT(linkToIP()));

    //2 : paramètrage des colis en fonction du type possible (A, B, C) (à modifier avec .ini)
    Package packA(13,14,15);
    Package packB(15,16,17);
    Package packC(17,18,19);
    mPackageTypes.insert("colis A",packA);
    mPackageTypes.insert("colis B",packB);
    mPackageTypes.insert("colis C",packC);

    //3 : en fonction de la taille, de la destination et du nom du client,
    //création d'un colis personnalisé + envoi au serveur
    connect(ui->BBconfirmation,SIGNAL(accepted()),this,SLOT(sendOrder()));
    connect(ui->BBconfirmation,SIGNAL(rejected()),this,SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::linkToIP()
{
    mSocket = new QTcpSocket;
    ip = ui->editIP->text();
    mSocket->connectToHost(ip,port);
    //connect(mSocket,SIGNAL(connected()),this,SLOT(imConnected()));
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(dataIsComing()));
}

void Widget::imConnected()
{
    mSocket->write("salut !!!");
}

void Widget::dataIsComing()
{
    qDebug() << mSocket->readAll();
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
