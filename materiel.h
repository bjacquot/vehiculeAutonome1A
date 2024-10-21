#ifndef MATERIEL_H
#define MATERIEL_H

class Materiel
{
public:
    Materiel();
    array<int, 360> distancesLidar; //array type int for 360 values

signals:
    newdistances();
    newState(double vitesse, double angle);
};

#endif // MATERIEL_H
