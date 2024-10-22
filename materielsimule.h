#ifndef MATERIELSIMULE_H
#define MATERIELSIMULE_H
#include <QString>
#include "tcpclient.h"

#include "materiel.h"

class MaterielSimule : public Materiel
{
public:
    explicit MaterielSimule(QObject *parent = nullptr);
    TcpClient tcp;
public slots :
    void deplacer(double vitesse, double angle) override;
    void processTcpDatas( QString data);
};

#endif // MATERIELSIMULE_H
