#ifndef CORRECTEUR_H
#define CORRECTEUR_H

class Correcteur {
public:

    Correcteur();


   double consigne;


    virtual double process(double entree);
};

#endif // CORRECTEUR_H
