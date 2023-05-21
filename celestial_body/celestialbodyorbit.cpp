#include "celestialbodyorbit.h"

CelestialBodyOrbit::CelestialBodyOrbit(int x, int y, int orbitRadius)
    : orbitCenterX(x), orbitCenterY(y), orbitRadius(orbitRadius)
{
    orbitColor = QColor(56, 214, 111);
    orbitPen = QPen(orbitColor, 2);
}

CelestialBodyOrbit::~CelestialBodyOrbit()
{

}

void CelestialBodyOrbit::draw(QPainter &painter)
{
    if(orbitRadius == 0)
    {
        return;
    }

    painter.save();

    painter.setPen(orbitPen);
    painter.setBrush(Qt::NoBrush);

    painter.drawArc(orbitCenterX - orbitRadius, orbitCenterY - orbitRadius,
                    orbitRadius * 2, orbitRadius * 2,
                    0, 360 * 16);

    painter.restore();
}
