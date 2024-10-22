#ifndef CORRECTEURPROPORTIONNEL_H
#define CORRECTEURPROPORTIONNEL_H

#include "correcteur.h"

class CorrecteurProportionnel : public Correcteur {
public:
    CorrecteurProportionnel(double _consigne,double Kp);
    double process(double entree) override;

private:
    double Kp;





};

#endif // CORRECTEURPROPORTIONNEL_H
