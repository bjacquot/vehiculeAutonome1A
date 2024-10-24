#include "tcpserveur.h"
#include "QDebug"


TcpServeur::TcpServeur()
    :monServeur(this)
{

    monServeur.listen((QHostAddress::AnyIPv4),8884);

    connect(&monServeur,&QTcpServer::newConnection,this,&TcpServeur::onNewConnection);
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

void TcpServeur::recoitDatas()
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

    qDebug()<<"connexion";
    serveurSocket = monServeur.nextPendingConnection();
    dataln.setDevice(serveurSocket);
    connect(serveurSocket,&QTcpSocket::readyRead, this, &TcpServeur::recoitDatas);
}
