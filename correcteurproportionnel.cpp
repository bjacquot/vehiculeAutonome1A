#include "correcteurproportionnel.h"


CorrecteurProportionnel::CorrecteurProportionnel(double Kp)
    : Kp(Kp)
{

}

// recoit valeur via comportement en entree
double CorrecteurProportionnel::process(double entree)
{

    double erreur = consigne - entree;
    double commande = Kp * erreur;
    return commande;

}
