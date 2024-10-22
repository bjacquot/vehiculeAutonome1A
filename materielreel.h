#ifndef MATERIELREEL_H
#define MATERIELREEL_H


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

    ILD *drv;
    QTimer tictoc; //tictoc.setInterval(periode);
    servomotoeur direction;
    servomoteur vitesse;

    void updateLidar();

public slots:
    void deplacer(double vitesse, double angle) override;
};

#endif // MATERIELREEL_H
