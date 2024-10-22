#include "materielsimule.h"

MaterielSimule::MaterielSimule(QObject *parent)
    : Materiel{parent}
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
    QStringList dataList = data.split(';');

    // Conversion de QString  en int dans mon array
    for (int i = 0; i < 360; ++i)
    {
        distancesLidar[i] = dataList[i].toInt();
    }

    // émet le signal avec les nouvelles distances pour la classe Comportement
    emit newDistances();
}
