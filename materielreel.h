#ifndef MATERIELREEL_H
#define MATERIELREEL_H

/* erruer deploiment:
Unable to figure out framebuffer device. Specify it manually.
linuxfb: Failed to initialize screen
no screens available, assuming 24-bit color
Cannot create window: no screens available*/

#include "materiel.h" //TODO: FIND + INCLUDE MOTHER CLASS
#include <QTimer>
#include "servomoteur.h"
#include "sl_lidar_driver.h"
using namespace std;
using namespace sl;



class MaterielReel : public Materiel
{
public:
    MaterielReel();

    //TcpClient //tc

    ILidarDriver * drv;
    QTimer tictoc;          //tictoc.setInterval(periode);
    ServoMoteur Direction{2,500,1000};
    ServoMoteur Vitesse{3,500,1000};//TODO: CONNECT SLOT AVEC

    void updateLidar();

    void test();

public slots:
    void deplacer(double vitesse, double angle) override; //TODO: ACTIVER OVERRIDE QUAND LA CLASSE MERE EST PRETE
};

#endif // MATERIELREEL_H
