#include "materielreel.h"
#include "mainwindow.h"
#include <QtMath>
#include <QDebug>

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif


MaterielReel::MaterielReel()
{
    //partie moteur
    drv = *createLidarDriver();
    if (!drv) {
        qDebug()<<"erreur";
    }
    else
    {
        qDebug()<<"driver ok";
    }

    IChannel* _channel;
    _channel = (*createSerialPortChannel("/dev/ttyUSB0", 115200));

    sl_result     op_result;
    sl_lidar_response_device_info_t devinfo;
    bool connectSuccess = false;
    if (SL_IS_OK((drv)->connect(_channel))) {
        op_result = drv->getDeviceInfo(devinfo);
        if (SL_IS_OK(op_result))
        {
            connectSuccess = true;
            qDebug()<<"connecté sur le lidar";
        }
        else{
            delete drv;
            drv = NULL;
        }
        qDebug()<<"SLAMTEC LIDAR S/N: "<<devinfo.serialnum;
        qDebug()<<"Firmware Ver: "<<(devinfo.firmware_version>>8)<<"."<<(devinfo.firmware_version & 0xFF)
                 <<"Hardware Rev: "<<(int)devinfo.hardware_version;
    }
    drv->setMotorSpeed();
    drv->startScan(0,1);


    //Qtimer pour le lidar

    tictoc.setInterval(50); //50ms = 20hz

    QObject::connect(&tictoc,&QTimer::timeout,
                     this,&MaterielReel::updateLidar); // connecté avec updateLidar()
    tictoc.start();


}

void MaterielReel::deplacer(double vitesse, double angle)//TODO: utiliser connects pour chaque moteur
{
    Vitesse.setPosition(vitesse);
    Direction.setPosition(angle);
}

void MaterielReel::updateLidar()
{
    sl_lidar_response_measurement_node_hq_t nodes[8192];
    size_t   count = _countof(nodes);
    sl_result op_result = drv->grabScanDataHq(nodes, count);

    if (SL_IS_OK(op_result))
    {
        distancesLidar.fill(0);//distances?
        for (int i=0;i<(int)count;i++)
        {
            int angle=round((nodes[i].angle_z_q14 * 90.f) / 16384.f);
            if (angle>=180) angle=angle-360;
            if ((angle>=-180)and(angle<180))
            {
                int d=nodes[i].dist_mm_q2/4.0;
                if (d>0) distancesLidar.at(angle+180)=d;
            }
        }
        for (int i=0;i<360;i++)
        {
            if (distancesLidar.at(i)==0)
            {
                for (int j=1;j<10;j++)
                {
                    int pos=(i+j)%360;
                    if (distancesLidar.at(pos)!=0) distancesLidar.at(i)=distancesLidar.at(pos);
                }
            }
        }
    }

}

void MaterielReel::test()
{
    Vitesse.setPosition(0);
    Direction.setPosition(0);
}
