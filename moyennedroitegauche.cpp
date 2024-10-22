#include "moyennedroitegauche.h"

using namespace std;

MoyenneDroiteGauche::MoyenneDroiteGauche(Correcteur &c1,int degree)
    : Comportement(distanceLidar), c{c1}, angle(degree)
{
    angle= degree+180;
    //angle en degree + 180 pour passer au numéro de case
}

void MoyenneDroiteGauche::process()
{
    double distanceGauche= distanceLidar.at(angle+180);
    double distanceDroite= distanceLidar.at(-angle+180);


    /*
    for(int i=angleMin;i<angleMax;i++){
        if (distanceGauche< distanceLidar.at(i)){
        distanceGauche= distanceLidar.at(i);
        }
        if (distanceDroite< distanceLidar.at(i+135)){
        distanceDroite= distanceLidar.at(i);
        }
        //recupere la valeur la plus proche de chaque coté, entre 90 et 135 / 225 et 270
        //45 mesures de chaque cotés
    }
    */


    double entree=(distanceGauche+distanceDroite)/2;


    //envoit des valeurs vers Correcteur
    int anglef=c.process(entree);

    emit deplacer(0.5,anglef);
    //envoit a Materiel
}
