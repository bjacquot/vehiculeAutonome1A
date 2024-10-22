#ifndef WIDGETLIDAR_H
#define WIDGETLIDAR_H

#include <QWidget>
#include <QPainter>
#include <cmath>
#include <QDebug>


class WidgetLidar : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetLidar(QWidget *parent = nullptr);
protected :
    std::array<int, 360> distanceLidar;
    void paintEvent(QPaintEvent *event);
public slots:
    void processTcpDatas(QString data);
};

#endif // WIDGETLIDAR_H
