#include "correcteurproportionnel.h"


CorrecteurProportionnel::CorrecteurProportionnel(double _consigne,double Kp)
    : Correcteur(_consigne),Kp(Kp)
{

}

// recoit valeur via comportement en entree
double CorrecteurProportionnel::process(double entree)
{

    double erreur = consigne - entree;
    double commande = Kp * erreur;
    return commande;

}
