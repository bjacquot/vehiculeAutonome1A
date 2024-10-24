#ifndef MATERIELREEL_H
#define MATERIELREEL_H


#include "materiel.h" //TODO: FIND + INCLUDE MOTHER CLASS
#include <QTimer>
#include "servomoteur.h"
#include "sl_lidar_driver.h"
#include "tcpclient.h"

using namespace std;
using namespace sl;



class MaterielReel : public Materiel
{
public:
    explicit MaterielReel(QString ip, int port);
    TcpClient tcp;

    //TcpClient //tc

    ILidarDriver * drv;
    QTimer tictoc;          //tictoc.setInterval(periode);
    ServoMoteur Direction{3,1500,500};
    ServoMoteur Vitesse{2,1500,500};//TODO: CONNECT SLOT AVEC

    void updateLidar();

public slots:
    void deplacer(double vitesse, double angle) override; //TODO: ACTIVER OVERRIDE QUAND LA CLASSE MERE EST PRETE
};

#endif // MATERIELREEL_H
