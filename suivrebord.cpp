#include "suivrebord.h"
#include <cmath>  // pour utiliser asin


SuivreBord::SuivreBord(array<int,360>&distanceLidar, Correcteur &c1, int _angle, double _vitesse)
    : Comportement(distanceLidar), c{c1},angle(_angle), vitesse (_vitesse)
{

}


void SuivreBord::process()
{

    double distanceBord = tabdistance.at(angle+180); // Lire la distance à gauche (-180° dans tabdistance[359])"pour suivre le mur gauche"

    double anglef = c.process(distanceBord);

    // Déplacer la voiture avec une vitesse constante (0.3 m/s) et l'angle corrigé
    emit deplacer(0.3, anglef);
}
