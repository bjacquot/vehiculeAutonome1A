#ifndef MOYENNEDROITEGAUCHE_H
#define MOYENNEDROITEGAUCHE_H

#include "comportement.h"

class MoyenneDroiteGauche : public Comportement
{
public:
    MoyenneDroiteGauche();
    //correcteur &c;
protected:
    float angle;
    double distanceBord;
    double nouvelValeur;

public slots:
    void process() override;
};

#endif // MOYENNEDROITEGAUCHE_H
