#include "celestialbodyorbit.h"

CelestialBodyOrbit::CelestialBodyOrbit(int x, int y, int orbitRadius)
    : orbitCenterX(x), orbitCenterY(y), orbitRadius(orbitRadius)
{
    orbitalCompletionPercent = 0.2;
    orbitColor = QColor(56, 214, 111);
    orbitPen = QPen(orbitColor, 1);
}

CelestialBodyOrbit::~CelestialBodyOrbit()
{

}

void CelestialBodyOrbit::updateOrbitCenter(int x, int y)
{
    orbitCenterX = x;
    orbitCenterY = y;
}

std::shared_ptr<CelestialPoint> CelestialBodyOrbit::getOrbitLocation()
{
    int bodyX = orbitRadius * std::cos(2 * pi * orbitalCompletionPercent);
    int bodyY = orbitRadius * std::sin(2 * pi * orbitalCompletionPercent);
    return std::make_shared<CelestialPoint>(bodyX, bodyY);
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
