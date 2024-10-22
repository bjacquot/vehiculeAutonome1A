#include "tcpserveur.h"
#include "QDebug"


TcpServeur::TcpServeur(/*int _monNumeroDePort*/):monServeur(new QTcpServer(this))  {
    //monNumeroDePort=_monNumeroDePort;
    monServeur.listen((QHostAddress::AnyIPv4),8884);



    //connect(&monServeur,&QTcpServer::newConnection,this,&TcpServeur::onNewConnection);
    connect(&monServeur,SIGNAL(newConnection()),this,SLOT(onNewConnection()));



}

void TcpServeur::sendDatas(QString _datas)
{
    QString datas=_datas;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << datas;
    qDebug()<<"message envoyé :"<<datas;
    serveurSocket->write(block);
}
void TcpServeur::reçoitDatas()
{
    dataln.startTransaction();
    if (!dataln.commitTransaction()) return;
    QString donnee;
    dataln >> donnee;
    emit newDatas(donnee);
    qDebug() << "Message reçu :" << donnee;
}

void TcpServeur::onNewConnection()
{
   // connect(&monServeur,&QTcpSocket::readyRead, this, &TcpServeur::reçoitDatas);
    qDebug()<<"connexion";
    serveurSocket = monServeur.nextPendingConnection();

}
