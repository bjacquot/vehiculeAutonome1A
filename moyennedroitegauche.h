#ifndef MOYENNEDROITEGAUCHE_H
#define MOYENNEDROITEGAUCHE_H

#include "comportement.h"

class MoyenneDroiteGauche : public Comportement
{
public:
    MoyenneDroiteGauche(correcteur &c1, double rad);
    //correcteur &c;
    //pointeur vers l'object c de type correcteur

protected:
    float angle;
    //angle de virage du vehicule

public slots:
    void process() override;
};

#endif // MOYENNEDROITEGAUCHE_H
