#ifndef SUIVREBORD_H
#define SUIVREBORD_H

#include "comportement.h"

class SuivreBord : public Comportement
{
public:
    SuivreBord(correcteur &c1, double distanceMur, double rad);
    correcteur  & c;
    double distanceBord;
    double angle;

public slots:
    void process() override;
};

#endif // SUIVREBORD_H
