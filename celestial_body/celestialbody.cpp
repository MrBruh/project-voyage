#include "celestialbody.h"

CelestialBody::CelestialBody(int x, int y, int bodyRadius, int orbitRadius)
    : bodyCenterX(x), bodyCenterY(y), bodyRadius(bodyRadius)
{
    orbit = new CelestialBodyOrbit(bodyCenterX, bodyCenterY, orbitRadius);
}

CelestialBody::~CelestialBody()
{

}

void CelestialBody::draw(QPainter &painter)
{
    painter.save();

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::gray);
    painter.drawEllipse(bodyCenterX - bodyRadius, bodyCenterY - bodyRadius, bodyRadius * 2, bodyRadius * 2);

    painter.restore();

    orbit->draw(painter);
}

