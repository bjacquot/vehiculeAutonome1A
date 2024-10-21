#ifndef SUIVREBORD_H
#define SUIVREBORD_H

#include "comportement.h"

class SuivreBord : public Comportement
{
public:
    explicit SuivreBord();
    correcteur  &C;
    double distanceBord;
    double angle;

public slots:
    void process() override;
};

#endif // SUIVREBORD_H
