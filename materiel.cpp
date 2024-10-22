#include "materiel.h"

Materiel::Materiel(QObject *parent)
    : QObject{parent}
{
    distancesLidar.fill(0);
}

void Materiel::deplacer(double vitesse, double angle)
{
    // emet le signal avec la vitesse et l'angle actuels
    emit newState(vitesse, angle);
}
