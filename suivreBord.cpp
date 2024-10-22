#include "suivreBord.h"
#include <cmath>  // pour utiliser asin

SuivreBord::SuivreBord(correcteur &c1, double distanceMur, int degree)
    : Comportement(array<int,360>&tabdistance), c{c1}, distanceBord(distanceMur), angle(rad)
{

}



void SuivreBord::process()
{

    double distanceActuel = tabdistance.at(); // Lire la distance à gauche (-180° dans tabdistance[359])"pour suivre le mur gauche"

    double erreur = distanceMur - distanceActuel; // Calculer l'erreur de distance par rapport à la distanceMur

    // Envoyer cette erreur au correcteur pour qu'il calcule un angle de correction
    double anglef = c1.process(consigne);

    // Déplacer la voiture avec une vitesse constante (0.3 m/s) et l'angle corrigé
    emit deplacer(0.3, anglef);
}
