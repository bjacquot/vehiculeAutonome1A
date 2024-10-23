#include "suivrebord.h"
#include <cmath>  // pour utiliser asin

SuivreBord::SuivreBord(Correcteur &c1, int degree)
    : Comportement(tabdistance), c{c1},angle(degree)
{

}

void SuivreBord::process()
{

    double distanceBord = tabdistance.at(angle+180); // Lire la distance à gauche (-180° dans tabdistance[359])"pour suivre le mur gauche"

    double anglef = c.process(distanceBord);

    // Déplacer la voiture avec une vitesse constante (0.3 m/s) et l'angle corrigé
    emit deplacer(0.3, anglef);
}
