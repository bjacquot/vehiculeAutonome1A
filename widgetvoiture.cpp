#include "widgetvoiture.h"
#include <QPainter>
#include <QStringList>
#include <QPaintEvent>

WidgetVoiture::WidgetVoiture(double vitesse, double angle, QWidget *parent)
    : QWidget(parent), vitesse(vitesse), angle(angle)  // Initialisation des membres
{
    // Définir une taille minimale pour le widget afin d'assurer que la voiture est visible
    setMinimumSize(400, 300);  // Ajustez la taille selon vos besoins
}

void WidgetVoiture::processTcpDatas(const QString& data)
{
    QStringList values = data.split(";");
    if (values.size() >= 2) {
        // Limiter la vitesse entre 1 et 10
        double newVitesse = values[0].toDouble();
        if (newVitesse < 1) {
            vitesse = 1;
        } else if (newVitesse > 10) {
            vitesse = 10;
        } else {
            vitesse = newVitesse;
        }

        angle = values[1].toDouble();  // Mise à jour de l'angle
    }

    update();  // Mettre à jour le widget
}

void WidgetVoiture::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Dessiner la voiture (rectangle statique)
    QRect voitureRect(100, 100, 200, 100);  // Position fixe pour la voiture
    painter.setBrush(Qt::blue);  // Couleur de la voiture
    painter.drawRect(voitureRect);

    // Roues arrière (qui restent statiques)
    QRect roueArriereGauche(110, 180, 40, 20);  // Roue arrière gauche (fixe)
      // Roue arrière droite (fixe)
    painter.setBrush(Qt::black);  // Couleur des roues
    painter.drawEllipse(roueArriereGauche);  // Dessiner la roue arrière gauche (fixe)
      // Dessiner la roue arrière droite (fixe)

    // Roues avant (qui bougent avec l'angle)
    painter.save();  // Sauvegarder l'état actuel du painter pour la roue avant droite
    painter.translate(270, 110);  // Déplacer le point de référence au centre de la roue avant droite
    painter.rotate(angle);        // Appliquer la rotation selon l'angle
    painter.translate(-270, -110); // Revenir à la position initiale
    QRect roueAvantDroite(250, 100, 40, 20);  // Position de la roue avant droite
    painter.drawEllipse(roueAvantDroite);  // Dessiner la roue avant droite
    painter.restore();  // Restaurer l'état


    // Roues arrière (qui bougent avec l'angle)
    painter.save();  // Sauvegarder l'état actuel du painter pour la roue avant droite
    painter.translate(270, 180);  // Déplacer le point de référence au centre de la roue avant arriere
    painter.rotate(angle);        // Appliquer la rotation selon l'angle
    painter.translate(-270, -110); // Revenir à la position initiale
   QRect roueArriereDroite(250, 110, 40, 20);  // Position de la roue avant droite
    painter.drawEllipse(roueArriereDroite);  // Dessiner la roue avant arrière
    painter.restore();  // Restaurer l'état


    QRect roueAvantGauche(110, 100, 40, 20);  // Roue avant gauche (fixe)
    painter.drawEllipse(roueAvantGauche);  // Dessiner la roue avant gauche (fixe)

    // Dessiner la flèche pour la vitesse
    double arrowLength = vitesse * 10;  // Longueur de la flèche proportionnelle à la vitesse (1 à 10)

    // Calculer la position de la flèche (centre de la voiture)
    double arrowX = 200 + arrowLength; // 200 = 100 + 100 (centre de la voiture)
    double arrowY = 150; // 150 = 100 + 50 (centre de la voiture)

    painter.setPen(Qt::red);  // Couleur de la flèche
    painter.drawLine(200, 150, arrowX, arrowY);  // Dessiner la ligne de la flèche

    // Dessiner la tête de la flèche
    painter.drawLine(arrowX, arrowY, arrowX - 10, arrowY + 10); // Partie gauche de la tête de la flèche
    painter.drawLine(arrowX, arrowY, arrowX - 10, arrowY - 10); // Partie droite de la tête de la flèche
}
