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
    TcpServeur();
    QTcpSocket  *serveurSocket=nullptr;
    
    QDataStream dataln;
    QTcpServer monServeur;
private :

public slots :
    void sendDatas(QString _datas);
    void recoitDatas();
    void onNewConnection(/*QTcpSocket  *serveurSocket*/) ;
signals :
    void newDatas(QString datas);
};

#endif // TCPSERVEUR_H

