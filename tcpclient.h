#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>

class TcpClient
{
public:
    TcpClient();
    void sendDatas(QString datas);

private :
    QTcpSocket clientSocket;
    QDataStream dataIn;

signals:
    void newDatas(QString datas);

};

#endif // TCPCLIENT_H
