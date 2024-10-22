#ifndef SUIVREBORD_H
#define SUIVREBORD_H
#include"correcteur.h"
#include "comportement.h"

class SuivreBord : public Comportement
{

public:
    SuivreBord(Correcteur &c1, int degree);
    void process() override;

private:
    std::array<int, 360> tabdistance; // Déclaration du tableau
    Correcteur &c; // Référence à l'objet Correcteur
    double distanceBord;
    int angle;


};

#endif // SUIVREBORD_H
