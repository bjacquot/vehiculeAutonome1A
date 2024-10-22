#include "tcpclient.h"
#include <QDebug>

 TcpClient::TcpClient(QString _AddrIp, int _port) :clientSocket(this)

{
    AddrIp=_AddrIp;
    port=_port;
    dataIn.setDevice(&clientSocket) ;
    connect(&clientSocket, &QTcpSocket::readyRead, this, &TcpClient::receiveDatas);
}


void TcpClient::sendDatas(QString datas)    // envoyer des donées
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << datas;
    qDebug()<<"message envoyé :"<<datas;
    //serveurSocket->write(block);
}

void TcpClient::connectToServer()       // methode pour se connecter au serveur
{
    clientSocket.connectToHost(AddrIp,port);
    if (!clientSocket.waitForConnected(3000)) { // Attendre 3 secondes
        qDebug() << "impossible de se connecter au serveur";
        return;
    }
    qDebug() << "Connecté au serveur sur" << AddrIp << ":" << port;
}


void TcpClient::receiveDatas()      // recevoir des donées
{
    dataIn.startTransaction();
    if (!dataIn.commitTransaction()) return;
    QString receivedData;
    dataIn >> receivedData;
    emit newDatas(receivedData);
    //qDebug() << "Message reçu :" << receivedData;     // si vous voulez voir les valeurs reçus
}
