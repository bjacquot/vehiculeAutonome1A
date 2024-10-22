#include "moyennedroitegauche.h"

MoyenneDroiteGauche::MoyenneDroiteGauche(std::array<int,360>&distanceLidar,correcteur &c1, double rad)
    : Comportement(),array<int,360>&distanceLidar, c{c1}, angle(rad)
{

}

void MoyenneDroiteGauche::process()
{
//correcteur
    int distanceGauche= distanceLidar[90];
    int distanceDroite= distanceLidar[270];

/* for(int i=90;i<135;i++){
        distanceGauche= distanceGauche+distanceLidar[i];
        distanceDroite= distanceDroite+distanceLidar[i];
}
    distanceGauche=distanceGauche/45;
    distanceDroite=distanceDroite/45;
    //fait la moyenne des 2 distance de droite et gauche
*/

    for(int i=90;i<135;i++){
        if (distanceGauche< distanceLidar[i]){
        distanceGauche= distanceLidar[i];
        }
        if (distanceDroite< distanceLidar[i+135]){
        distanceDroite= distanceLidar[i];
        }
        //recupere la valeur la plus proche de chaque coté, entre 90 et 135 / 225 et 270
        //45 mesures de chaque cotés
    }

    angle=distanceGauche-distanceDroite;
    //angle + quand tourner a gauche
    //angle - quand tourner a droite


    //envoit des valeurs vers Correcteur
    //c.process(angle);
}
