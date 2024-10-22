#include "materiel.h"

Materiel::Materiel(QObject *parent)
    : QObject{parent}
{
}

void Materiel::deplacer(double vitesse, double angle)
{
    // Émettre le signal d'état avec la vitesse et l'angle actuels
    emit newState(vitesse, angle);
}
