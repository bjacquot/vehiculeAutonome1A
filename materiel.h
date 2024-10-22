#ifndef MATERIEL_H
#define MATERIEL_H
#include <array>
#include <QObject>
using namespace  std;
class Materiel : public QObject
{
    Q_OBJECT
public:
    explicit Materiel(QObject *parent = nullptr);
    array<int,360> distancesLidar;
public slots:
    virtual void deplacer(double vitesse, double angle);
signals:
    void newDistances();
    void newState(double vitesse, double angle);
};

#endif // MATERIEL_H
