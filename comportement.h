#ifndef COMPORTEMENT_H
#define COMPORTEMENT_H
#include <QObject>
// #include "correcteur.h"

using namespace std;

class Comportement : public  QObject
{
    //Q_OBJECT
public:
    Comportement(array<int,360>&tabdistance);

    array<int,360>&distanceLidar;

public slots:
    virtual void process();
    //récupere de newDistances (Materiel)

signals:
    deplacer(double vitesse, double angle);
    //envoit vers deplacer (Materiel)
};

#endif // COMPORTEMENT_H
