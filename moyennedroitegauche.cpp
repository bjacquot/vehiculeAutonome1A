#include "moyennedroitegauche.h"
#include "QDebug"


using namespace std;

MoyenneDroiteGauche::MoyenneDroiteGauche(array<int,360>&distanceLidar, Correcteur &c1, double _vitesse, int _angle)
    : Comportement(distanceLidar), c{c1}, speed(_vitesse), angle(_angle)
{

}

void MoyenneDroiteGauche::process()
{
    double distanceGauche= distanceLidar.at(angle+180);
    double distanceDroite= distanceLidar.at(-angle+180);
    //  qDebug() << "la distance au bord" <<distanceGauche;
    distanceGauche= distanceLidar.at(angle+180);
    distanceDroite= distanceLidar.at(-angle+180);

    /*
    for(int i=angleMin;i<angleMax;i++){
        if (distanceGauche< distanceLidar.at(i+180)){
        distanceGauche= distanceLidar.at(i+180);
        }
        if (distanceDroite< distanceLidar.at(-i+180)){
        distanceDroite= distanceLidar.at(-i+180);
        }
        //recupere la valeur la plus proche de chaque coté, entre angleMin et angleMax
    }
    */


    double entree=(distanceGauche+distanceDroite)/2;


    //envoit des valeurs vers Correcteur
    int direction=c.process(entree);

    emit deplacer(speed,direction);
    //envoit a Materiel
}
