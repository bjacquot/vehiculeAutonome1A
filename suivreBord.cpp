#include "suivreBord.h"
#include <cmath>  // pour utiliser asin

SuivreBord::SuivreBord(Correcteur &c1, double distanceMur, int degree)
    : Comportement(tabdistance), c{c1}, distanceBord(distanceMur), angle(degree)
{

}

void SuivreBord::process()
{

    double distanceActuel = tabdistance.at(270); // Lire la distance à gauche (-180° dans tabdistance[359])"pour suivre le mur gauche"

    double commande = c1.process(distanceActuel);

    // Déplacer la voiture avec une vitesse constante (0.3 m/s) et l'angle corrigé
    emit deplacer(5, commande);
}
