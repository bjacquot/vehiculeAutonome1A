#ifndef CORRECTEURPID_H
#define CORRECTEURPID_H

#include "correcteur.h"

class CorrecteurPID : public Correcteur {
public:
    CorrecteurPID(double consigne,  double kp, double ki, double kd);

    virtual double process(double entree);

private:
    double Kp;
    double Ki;
    double Kd;

    double sommeErreurs;
    double erreurPrecedente;


};

#endif // CORRECTEURPID_H
