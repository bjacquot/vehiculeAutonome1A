#ifndef SUIVREBORD_H
#define SUIVREBORD_H
#include"correcteur.h"
#include "comportementn.h"

class SuivreBord : public Comportement
{

public:
    SuivreBord(array<int,360>&_distanceLidar, Correcteur &c1, int _angle, double _vitesse);
    void process() override;

private:
    Correcteur &c; // Référence à l'objet Correcteur
    int angle;
    double vitesse;


};

#endif // SUIVREBORD_H
