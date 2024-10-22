#include "materielsimule.h"

MaterielSimule::MaterielSimule(QObject *parent)
    : Materiel{parent}
{
    //Connect le signal newDatas de TcpClient au slot processTcpDatas
    connect(&tcp, &TcpClient::newDatas, this, &MaterielSimule::processTcpDatas);

}

void MaterielSimule::deplacer(double vitesse, double angle)
{
    //le comportement ...
    QString command = QString::number(vitesse) + ";" + QString::number(angle);

    // Envoie la commande de mouvement via TCP
    tcp.sendDatas(command);
    Materiel::deplacer(vitesse, angle);

}

void MaterielSimule::processTcpDatas(QString data)
{
    //convertir:
    // Séparer la chaîne de caractères avec le séparateur ';'
    QStringList dataList = data.split(';');

    // Conversion de QString  en int dans mon array
    for (int i = 0; i < dataList.size() && i < 360; ++i) {
        distancesLidar[i] = dataList[i].toInt();
    }

    // Émettre le signal avec les nouvelles distances
    emit newDistances();
}
