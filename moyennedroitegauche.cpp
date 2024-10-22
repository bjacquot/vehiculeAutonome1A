#include "moyennedroitegauche.h"
#include <cmath>

using namespace std;

MoyenneDroiteGauche::MoyenneDroiteGauche(/*correcteur &c1,*/ int rad)
    : Comportement(),/* c{c1},*/ angle(rad)
{
    //angle= rad;
}

void MoyenneDroiteGauche::process()
{
    //correcteur
    double distanceGauche= distanceLidar.at(angle+180);
    double distanceDroite= distanceLidar.at(-angle+180);

    /*
    for(int i=90;i<135;i++){
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

    diffDistance=distanceGauche-distanceDroite;
    //diffDistance + quand tourner a gauche
    //diffDistance - quand tourner a droite


    //envoit des valeurs vers Correcteur
    //c.process(diffDistance);
}
