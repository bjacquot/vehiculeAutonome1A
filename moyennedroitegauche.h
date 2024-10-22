#ifndef MOYENNEDROITEGAUCHE_H
#define MOYENNEDROITEGAUCHE_H

#include "comportement.h"

class MoyenneDroiteGauche : public Comportement
{
public:
    MoyenneDroiteGauche(/*correcteur &c1,*/ int rad);
    /*correcteur &c;
    */
    //pointeur vers l'object c de type correcteur

protected:
    int angle;
    //angle de virage du vehicule
    double diffDistance;
    //différence de distance entre gauche et droite

public slots:
    void process() override;
};

#endif // MOYENNEDROITEGAUCHE_H
