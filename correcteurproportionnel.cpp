#include "correcteurproportionnel.h"


CorrecteurProportionnel::CorrecteurProportionnel(double Kp, double consigne)
    : Kp(Kp), consigne(consigne),
{

}

// recoit valeur via comportement en entree
double CorrecteurProportionnel::process(double entree)
{

    double erreur = consigne - entree;
    double commande = Kp * erreur;
    return commande;

}
