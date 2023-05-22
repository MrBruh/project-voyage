#include "celestialbody.h"

CelestialBody::CelestialBody(int x, int y, int bodyRadius, int orbitRadius)
    : bodyCenterX(x), bodyCenterY(y), bodyRadius(bodyRadius)
{
    orbit = std::make_shared<CelestialBodyOrbit>(bodyCenterX, bodyCenterY, orbitRadius);

    // Can't do this since parent isn't defined yet
//    if (orbitRadius != 0) {
//        setBodyCenter(orbit->getOrbitLocation());
//    }
}

CelestialBody::~CelestialBody()
{

}

void CelestialBody::draw(QPainter &painter)
{
    // Draw children first, then draw self
    for (std::shared_ptr<CelestialBody> body : satellites) {
        body->draw(painter);
    }

    orbit->draw(painter);

    painter.save();

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::gray);
    painter.drawEllipse(bodyCenterX - bodyRadius, bodyCenterY - bodyRadius, bodyRadius * 2, bodyRadius * 2);

    painter.restore();
}

void CelestialBody::addSatellite(std::shared_ptr<CelestialBody> satellite)
{
    satellite->addParentBody(this);
    satellite->updateBodyOrbit(bodyCenterX, bodyCenterY);

    satellites.emplace_back(satellite);
}

void CelestialBody::addParentBody(CelestialBody *parent)
{
    // Add parent information
    parentBody = parent;

    // Only after parent information is added can we update the body's center
    setBodyCenter(orbit->getOrbitLocation());
}

void CelestialBody::updateBodyOrbit(int x, int y)
{
    orbit->updateOrbitCenter(x, y);
}

std::shared_ptr<CelestialPoint> CelestialBody::getBodyCenter()
{
    return std::make_shared<CelestialPoint>(bodyCenterX, bodyCenterY);
}

// Assuming that 0,0 is the coordinate of the parennt body
void CelestialBody::setBodyCenter(std::shared_ptr<CelestialPoint> point)
{
    std::shared_ptr<CelestialPoint> parentBodyPoint = parentBody->getBodyCenter();
    bodyCenterX = point->x + parentBodyPoint->x;
    bodyCenterY = point->y + parentBodyPoint->y;
}

