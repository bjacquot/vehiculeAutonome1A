#include "correcteurpid.h"
#include <QtGlobal>

CorrecteurPID::CorrecteurPID(double consigne,double kp, double ki, double kd)
    :Correcteur(consigne), Kp(kp), Ki(ki), Kd(kd) {
}

double CorrecteurPID::process(double entree) {

    double erreur = consigne - entree;

    sommeErreurs += erreur;

    double variationErreur = erreur - erreurPrecedente;

    double commande = Kp * erreur + Ki * sommeErreurs + Kd * variationErreur;

    erreurPrecedente = erreur;

    return commande;
}
