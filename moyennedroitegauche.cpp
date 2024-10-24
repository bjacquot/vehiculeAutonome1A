#include "moyennedroitegauche.h"
#include "QDebug"


using namespace std;

MoyenneDroiteGauche::MoyenneDroiteGauche(array<int,360>&distanceLidar, Correcteur &c1, int _angle, double _vitesse)
    : Comportement(distanceLidar), c{c1},angle(_angle), speed (_vitesse)
{

}


void MoyenneDroiteGauche::process()
{
    double distanceGauche= distanceLidar.at(angle+180);
    double distanceDroite= distanceLidar.at(-angle+180);
    double distanceDevant= distanceLidar.at(180+180);
    //qDebug() << "la distance au bord" <<distanceGauche;

/*
    double angleMin=60;
    double angleMax = 120;

    for(int i=angleMin;i<angleMax;i++){
        if (distanceGauche< distanceLidar.at(i+180)){
        distanceGauche= distanceLidar.at(i+180);
        }
        if (distanceDroite< distanceLidar.at(-i+180)){
        distanceDroite= distanceLidar.at(-i+180);
        }
        //recupere la valeur la plus proche de chaque coté, entre angleMin et angleMax
    }*/


    double entree=distanceGauche-distanceDroite;


    //envoit des valeurs vers Correcteur
    int direction=c.process(entree);
    qDebug()<< distanceGauche <<distanceDroite <<entree << direction;

    if (direction>1)
    {
        direction=1;
    }
    else if (direction<-1)
    {
        direction=-1;
    }
    else
    {
        direction=direction;
    }

    speed=distanceDevant/1000;
    //fait changer la vitesse du robot en fonction de la distance du mur de devant



    //direction = 0;
    //speed = 0;
    emit deplacer(speed,direction);
    //envoit a Materiel
}
