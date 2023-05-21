#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

#include "celestialbodyorbit.h"

class CelestialBody
{
public:
    CelestialBody(int x, int y, int bodyRadius = 25, int orbitRadius = 0);
    ~CelestialBody();

    void draw(QPainter &painter);

protected:
    int bodyRadius;
    int bodyCenterX;
    int bodyCenterY;

    QColor bodyColor;
    QPen pen;
    QBrush brush;

private:
    CelestialBodyOrbit *orbit;
};

#endif // CELESTIALBODY_H
