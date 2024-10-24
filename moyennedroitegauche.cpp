#include "moyennedroitegauche.h"
#include "QDebug"
using namespace std;

MoyenneDroiteGauche::MoyenneDroiteGauche(array<int,360>&distanceLidar, Correcteur &c1,int _angle1, int _angle2, double _vitesse )
    : Comportement(distanceLidar), c{c1}, vitesse(_vitesse)
{
    angle1 = (-1)*_angle1;
    angle2 =  _angle2;
}

void MoyenneDroiteGauche::process()
{
   if  (etatVoiture==true)
      {

    //distance gauche
    double distanceGauche= distanceLidar.at(angle1+180);
    //distance droite
    double distanceDroite= distanceLidar.at(angle2+180);
    //difference entre les 2
    double entree=(distanceGauche- distanceDroite);



    //envoit des valeurs vers Correcteur
    double direction=c.process(entree);


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

    emit deplacer(vitesse ,direction);
        }


   else
   {
      emit deplacer(0 ,0);
  }

}

void MoyenneDroiteGauche::controlerEtat(QString message)
{
  if (message == "on") etatVoiture==true;
  else if (message == "off") etatVoiture==false;
}





