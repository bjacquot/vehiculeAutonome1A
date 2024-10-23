#ifndef WIDGETVOITURE_H
#define WIDGETVOITURE_H

#include <QWidget>

class WidgetVoiture : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVoiture(double vitesse, double angle, QWidget *parent = nullptr);

    void processTcpDatas(const QString &data);  // Méthode pour traiter les données TCP

protected:
    void paintEvent(QPaintEvent *event) override;  // Redéfinition de paintEvent

private:
    double vitesse;  // Vitesse de la voiture
    double angle;    // Angle de la voiture

signals:
    void updateVoiture(double vitesse, double angle);  // Signal pour mettre à jour la voiture
};

#endif // WIDGETVOITURE_H
