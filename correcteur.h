#ifndef CORRECTEUR_H
#define CORRECTEUR_H

class Correcteur {
public:

    Correcteur(double _consigne);
    virtual double process(double entree);

protected:
   double consigne;


};

#endif // CORRECTEUR__H
