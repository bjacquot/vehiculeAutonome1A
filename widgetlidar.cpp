#include "widgetlidar.h"

WidgetLidar::WidgetLidar(QWidget *parent)
    :QWidget(parent)
{
    distanceLidar.fill(0);                          // Remplit le tableau avec des zéros
}

void WidgetLidar::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);                      // Efface le fond et lestracées précedents sur le widget
    QPainter painter(this);                          // Crée un objet QPainter pour dessiner sur le widget
    painter.fillRect(rect(), Qt::white);             // On ajoute un fond blanc sur le widget
    painter.setRenderHint(QPainter::Antialiasing);   // Pour rendre plus jolie le tracer
    painter.translate(1920/2,1080/2);                //Pour configuerer l'origine de tracer
    painter.scale(0.1,0.1);                          // Definit l'echelle du widget *0.1
    painter.setPen(Qt::blue);                        // Définit la couleur des droites

    /*
    // Calculer les positions centrale de x et y
    int centreX = width() / 2;
    int centreY = height() / 2;
    qDebug()<<"CentreX : "<<centreX<<" Centre y: "<<centreY;*/

    for (int i = 0; i < 360; i++) {
        double angle = ((i -180)* 3.14 / 180.0);         // Convertit l'angle en radians
        int distance = distanceLidar[i];                // Récupère la distance mesurée
        // Calculer les positions x et y
        int xEnd = distance * cos(angle);     // Calcul de la coordonnée X de la fin de la ligne
        int yEnd = -distance * sin(angle);     // Calcul de la coordonnée Y de la fin de la ligne
        painter.drawLine(0,0, xEnd, yEnd); // Dessine la ligne depuis le centre jusqu'à la position (xEnd, yEnd)
        //painter.drawLine(centerX, centreY, xEnd,yEnd);
    }
}

void WidgetLidar::processTcpDatas(QString data)
{
    QStringList dataList = data.split(";");             // Découpe data: Qstring  la virgule
    if (dataList.size() == 360) {                       // Vérifie que la liste contient bien 360 valeurs
        qDebug()<<"taille de liste valide";
        for (int i = 0; i < 360; ++i) {                 //On parcours la liste
            distanceLidar[i] = dataList[i].toInt();     // Convertit en entier et met à jour distanceLidar
        }
        update();                                       // Demande à Qt de redessiner le widget
    } else {
        qDebug()<<"problème de taille"<< dataList.size();
    }
}
