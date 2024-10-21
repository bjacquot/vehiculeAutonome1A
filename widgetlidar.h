#ifndef WIDGETLIDAR_H
#define WIDGETLIDAR_H

#include <QWidget>


class WidgetLidar : public QWidget
{
    Q_OBJECT
public:
    WidgetLidar();
protected :
    std::array<int, 360> distanceLidar;
public slots:
    void processTcpDatas(QString data);
};

#endif // WIDGETLIDAR_H
