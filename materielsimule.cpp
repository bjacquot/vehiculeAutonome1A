#include "materielsimule.h"

MaterielSimule::MaterielSimule(int port,QObject *parent)
    : Materiel{parent},tcp("10.98.32.154",port)
{
    //connect le signal newDatas de TcpClient au slot processTcpDatas
    connect(&tcp, &TcpClient::newDatas, this, &MaterielSimule::processTcpDatas);

}

void MaterielSimule::deplacer(double vitesse, double angle)
{
    // commande =  sous forme (vitesse;angle) en QString
    QString commande = QString::number(vitesse) + ";" + QString::number(angle);

    // envoie la commande via TCP
    tcp.sendDatas(commande);
    Materiel::deplacer(vitesse, angle);

}

void MaterielSimule::processTcpDatas(QString data)
{
    //convertion : //
    // Séparer la chaîne de caractères avec ';'
    //qDebug() << data;

    QStringList dataList = data.split(';');
    //qDebug() << dataList;


    // Conversion de QString  en int dans mon array

    // if (dataList.size() < 360) {
    //     qDebug() << "Erreur : données reçues insuffisantes, taille:" << dataList.size();
    //     return;
    // }

    // Conversion de QString en int dans mon array
    if(!data.isEmpty())
    {
        for (int i = 0; i < 360; ++i) {
            distancesLidar.at(i) = dataList.at(i).toInt();
            //qDebug() << dataList[i];

        }
    }
    //qDebug() << distancesLidar.at(360);
    // émet le signal avec les nouvelles distances pour la classe Comportement
    emit newDistances();
}
