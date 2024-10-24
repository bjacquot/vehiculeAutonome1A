#ifndef MOYENNEDROITEGAUCHE_H
#define MOYENNEDROITEGAUCHE_H

#include "comportementn.h"
#include "correcteur.h"

class MoyenneDroiteGauche : public Comportement
{
public:
    MoyenneDroiteGauche(array<int,360> &_distanceLidar,Correcteur &c1, int _angle, double _vitesse);

    double distanceGauche;
    double distanceDroite;
    Correcteur &c;

protected:
    int angle;
    double vitesse;

    //comportement différent
    /*
    int angleMin;
    int angleMax;
    */

public slots:
    void process() override;
};

#endif // MOYENNEDROITEGAUCHE_H
