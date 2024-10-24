#include "moyennedroitegauche.h"
#include "QDebug"


using namespace std;

MoyenneDroiteGauche::MoyenneDroiteGauche(array<int,360>&distanceLidar, Correcteur &c1, int _angle, double _vitesse)
    : Comportement(distanceLidar), c{c1},angle(_angle), vitesse (_vitesse)
{

}


void MoyenneDroiteGauche::process()
{
    double distanceGauche= distanceLidar.at(angle+180);
    double distanceDroite= distanceLidar.at(-angle+180);
    double distanceDevant= distanceLidar.at(180);

    double entree=distanceGauche-distanceDroite;


    //envoit des valeurs vers Correcteur
    double direction=c.process(entree);

    if (direction>1)
    {direction=1;}
    else if (direction<-1)
    {direction=-1;}

    if (vitesse>1)
    {vitesse=1;}
    else if (vitesse<-1)
    {vitesse=-1;}


    qDebug()<< distanceGauche <<distanceDroite;

    //direction = -1;
    //vitesse = 0.5;
    emit deplacer(vitesse,direction);
    //envoit a Materiel
}
