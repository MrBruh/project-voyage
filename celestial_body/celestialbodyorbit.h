#ifndef CELESTIALBODYORBIT_H
#define CELESTIALBODYORBIT_H

#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class CelestialBodyOrbit
{
public:
    CelestialBodyOrbit(int x, int y, int orbitRadius = 100);
    ~CelestialBodyOrbit();

    void draw(QPainter &painter);
private:
    int orbitRadius;
    int orbitCenterX;
    int orbitCenterY;
    double orbialCompletionPercent;

    QColor orbitColor;
    QPen orbitPen;
};

#endif // CELESTIALBODYORBIT_H
