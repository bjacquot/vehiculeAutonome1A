#ifndef TCPSERVEUR_H
#define TCPSERVEUR_H
#include "qstring.h"
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include "QObject"

class TcpServeur: public QObject
{
Q_OBJECT
public:
    TcpServeur(/*int _monNumeroDePort*/);
    //int monNumeroDePort;
    QTcpSocket  *serveurSocket;
    void sendDatas(QString _datas);
    //QDataStream getDataln() const;
    QDataStream dataln;
    QTcpServer monServeur;
private :



public slots :

    void reçoitDatas();
    void onNewConnection(/*QTcpSocket  *serveurSocket*/) ;
signals :
    void newDatas(QString datas);
};

#endif // TCPSERVEUR_H
