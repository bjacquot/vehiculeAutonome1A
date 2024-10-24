#ifndef MOYENNEDROITEGAUCHE_H
#define MOYENNEDROITEGAUCHE_H

#include "comportementn.h"
#include "correcteur.h"

class MoyenneDroiteGauche : public Comportement
{
public:
    MoyenneDroiteGauche(array<int,360>&distanceLidar, Correcteur &c1,int _angle1, int _angle2, double _vitesse );
    void process() override;

    bool etatVoiture=false;


protected:
    Correcteur &c;
    int angle1;
    int angle2;
    double vitesse;
public slots:
     void controlerEtat(QString message);
};

#endif // MOYENNEDROITEGAUCHE_H
