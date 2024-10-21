#ifndef MATERIELREEL_H
#define MATERIELREEL_H


#include "materiel.h"
#include <QTimer>
#include "servomoteur.h"

class MaterielReel : public Materiel
{
public:
    MaterielReel();

    //TcpClient //tc

    ILidarDriver * drv;
    //QTimer ticitoc tout les 50 ms
    servomotoeur direction;
    servomoteur vitesse;
};

#endif // MATERIELREEL_H
