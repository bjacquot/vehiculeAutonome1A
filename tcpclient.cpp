#include "tcpclient.h"
#include <QDebug>

TcpClient::TcpClient(): dataIn(&clientSocket)

{
    dataIn.setDevice(&clientSocket);
}

void TcpClient::sendDatas(QString datas)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << datas;
    qDebug()<<"message envoyé :"<<datas;
    //serveurSocket->write(block);
}

