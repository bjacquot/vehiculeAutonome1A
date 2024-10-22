#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include <QTimer>

/*
    !! Il faut ajouter QT += network dans le .pro !!

Pour utiliser la classe :

    IP du serveur de simulation : 10.98.32.154
    Ports disponibles : 8880 - 8885
    Créer un objet TcpClient (par exemple crée l'objet dans le mainwindow.h et lui donner ses parametres dans le mainwindow.cpp),
    lui assigner l'IP, puis le port du serveur. L'IP doit etre entre guillemets. Par exemple : tcp1("10.98.32.154", 8885)

    Une fois l'objet créé, il se connectera automatiquement au serveur.
    Chaque donnée reçue déclenchera le signal newData, qui contiendra les données

*/


class TcpClient: public QObject
{
    Q_OBJECT

public:
    TcpClient(QString _AddrIp, int _port);
    void sendDatas(QString datas);
    void connectToServer();
    void connecte();
    void connexion();

public slots:
    void receiveDatas();
    void reconnect();

signals:
    void newDatas(QString datas);

private :
    QTcpSocket clientSocket;

    QDataStream dataIn;
    QDataStream dataOut;

    QString AddrIp;

    int port;

    QTimer reconnectTimer;

};

#endif // TCPCLIENT_H
