#include "widgetlidar.h"

WidgetLidar::WidgetLidar(QWidget *parent)
    :QWidget(parent)
{
    distanceLidar.fill(0); // Remplit le tableau avec des zéros
}

void WidgetLidar::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event); // Utilisation de l'event

    QPainter painter(this);                        // Crée un objet QPainter pour dessiner sur le widget
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::blue);                       // Définit la couleur des points en rouge
    int centerX = width() / 2;                // Position centrale en X
    int centerY = height() / 2;               // Position centrale en Y

    for (int i = 0; i < 360; ++i) {
        float angle = ((i -180)* M_PI / 180.0); // Convertit l'angle en radians
        int distance = distanceLidar[i]; // Récupère la distance mesurée, limitée à maxDistance

        // Calculer les positions x et y
        int xEnd = centerX + distance * cos(angle); // Calcul de la coordonnée X de la fin de la ligne
        int yEnd = centerY - distance * sin(angle); // Calcul de la coordonnée Y de la fin de la ligne
        // Dessine la ligne depuis le centre jusqu'à la position (xEnd, yEnd)
        painter.drawLine(centerX, centerY, xEnd, yEnd);
    }
}

void WidgetLidar::processTcpDatas(QString data)
{
    QStringList dataList = data.split(";"); // Découpe data: Qstring  la virgule
    if (dataList.size() == 360) {           // Vérifie que la liste contient bien 360 valeurs
        for (int i = 0; i < 360; ++i) {
            distanceLidar[i] = dataList[i].toInt(); // Convertit en entier et met à jour distanceLidar
        }
        update(); // Demande à Qt de redessiner le widget
    } else {
        qDebug()<<"problème de taille"<< dataList.size();;
    }
}
