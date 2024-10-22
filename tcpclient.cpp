#include "tcpclient.h"
#include <QDebug>

TcpClient::TcpClient(QString _AddrIp, int _port) :clientSocket(this)

{
    AddrIp=_AddrIp;
    port=_port;
    dataIn.setDevice(&clientSocket) ;
    connect(&clientSocket, &QTcpSocket::readyRead, this, &TcpClient::receiveDatas);

    reconnectTimer.setInterval(100);
    reconnectTimer.start();

    connect(&clientSocket, &QTcpSocket::connected , this, &TcpClient::connecte) ;
    connect(&clientSocket, &QTcpSocket::disconnected , this, &TcpClient::connexion);
    connect(&reconnectTimer, &QTimer::timeout , this, &TcpClient::reconnect);

    clientSocket.connectToHost(AddrIp,port);	// Connection automatique au serveur

}


void TcpClient::sendDatas(QString datas)	// envoyer des donées
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << datas;
    //qDebug()<<"message envoyé :"<<datas;  	// si vous voulez voir ce que vous envoyez
    clientSocket.write(block);
}


void TcpClient::connectToServer()   	// methode pour se connecter manuellement au serveur
{
    clientSocket.connectToHost(AddrIp,port);
    if (!clientSocket.waitForConnected(3000)) { // Attendre 3 secondes
        qDebug() << "impossible de se connecter au serveur";
        return;
    }
    qDebug() << "Connecté au serveur sur" << AddrIp << ":" << port;
                                                                  reconnectTimer.stop();
}


void TcpClient::connecte()
{
    reconnectTimer.stop();  	//reconnecté au serveur, stop la tentative de connection (timer)
}


void TcpClient::connexion()
{
    reconnectTimer.start(); 	//deconnecté au serveur, start la tentative de connection (timer)
}


void TcpClient::receiveDatas()  	// recevoir des donées
{
    dataIn.startTransaction();
    if (!dataIn.commitTransaction()) return;
    QString receivedData;
    dataIn >> receivedData;
    emit newDatas(receivedData);
    //qDebug() << "Message reçu :" << receivedData; 	// si vous voulez voir les valeurs reçus
}


void TcpClient::reconnect()
{
    clientSocket.connectToHost(AddrIp,port);
}

