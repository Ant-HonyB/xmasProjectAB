#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

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
    void clientDisconnected();
    void dataIsComing();


private:
    Ui::Widget *ui;
    QTcpServer* mServer;
    QList<QTcpSocket*> mClients;
};
#endif // WIDGET_H
