#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>

/*
    Pour utiliser La classe :
    IP serveur de simulation : 10.98.32.15
    Port disponible : 8880 - 8885
    Creé un objet TcpClient, lui donner l'ip, puis le serveur
    Appeler la methode connectToServer pour se connecter

 */


class TcpClient: public QObject
{
Q_OBJECT

public:
     TcpClient(QString _AddrIp, int _port);
     void sendDatas(QString datas);
     void connectToServer();

public slots:
    void receiveDatas();


signals:
    void newDatas(QString datas);

private :
    QTcpSocket clientSocket;
    QDataStream dataIn;
    QString AddrIp;
    int port;

};

#endif // TCPCLIENT_H
