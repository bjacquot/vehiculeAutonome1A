#ifndef MOYENNEDROITEGAUCHE_H
#define MOYENNEDROITEGAUCHE_H

#include "comportement.h"
#include "correcteur.h"

class MoyenneDroiteGauche : public Comportement
{
public:
    MoyenneDroiteGauche(Correcteur &c1, int degree);

    Correcteur &c;


protected:
    int angle;

    //comportement différent
    /*
    int angleMin;
    int angleMax;
    */
public slots:
    void process() override;
};

#endif // MOYENNEDROITEGAUCHE_H
