#include "suivrebord.h"
#include "QDebug"
#include <cmath>  // pour utiliser asin

SuivreBord::SuivreBord(array<int,360>&distanceLidar, Correcteur &c1, int _angle, double _vitesse)
    : Comportement(distanceLidar), c{c1},angle(_angle), vitesse (_vitesse)
{

}

void SuivreBord::process()
{

     double distanceBord = tabdistance.at(angle+180);  // Lire la distance à gauche (-180° dans tabdistance[359])"pour suivre le mur gauche"
    qDebug() << "la distance au bord" <<distanceBord;
    double direction = c.process(distanceBord);
    qDebug() << "l'angle de correction est de "<<direction;


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

   emit deplacer(vitesse, direction);

  }
  
