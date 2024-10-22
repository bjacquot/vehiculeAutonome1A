#ifndef CORRECTEUR_H
#define CORRECTEUR_H

class Correcteur {
public:

    Correcteur();
    virtual double process(double entree);

protected:
   double consigne;



};

#endif // CORRECTEUR_H
