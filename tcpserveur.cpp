#include "tcpserveur.h"
#include "QDebug"


TcpServeur::TcpServeur():monServeur(new QTcpServer(this))  {

    monServeur.listen((QHostAddress::AnyIPv4),8884);

    connect(&monServeur,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    //connect(&serveurSocket,&newDatas, this, &TcpServeur::reçoitDatas);
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
    QString donnee;
    dataln >> donnee;
    if (!dataln.commitTransaction()) return;
    emit newDatas(donnee);
    qDebug() << "Message reçu :" << donnee;
}

void TcpServeur::onNewConnection()
{

    qDebug()<<"connexion";
    serveurSocket = monServeur.nextPendingConnection();
    dataln.setDevice(serveurSocket);
}
