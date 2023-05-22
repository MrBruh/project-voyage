#ifndef CELESTIALBODYORBIT_H
#define CELESTIALBODYORBIT_H

#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

#include "celestialpoint.h"

class CelestialBodyOrbit
{
public:
    CelestialBodyOrbit(int x, int y, int orbitRadius = 100);
    ~CelestialBodyOrbit();

    void updateOrbitCenter(int x, int y);

    std::shared_ptr<CelestialPoint> getOrbitLocation();

    void draw(QPainter &painter);
private:
    const double pi = std::acos(-1);

    int orbitRadius;
    int orbitCenterX;
    int orbitCenterY;
    double orbitalCompletionPercent;

    QColor orbitColor;
    QPen orbitPen;
};

#endif // CELESTIALBODYORBIT_H
