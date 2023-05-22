#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

#include "celestialbodyorbit.h"
#include "celestialpoint.h"

class CelestialBody
{
public:
    CelestialBody(int x, int y, int bodyRadius = 25, int orbitRadius = 0);
    ~CelestialBody();

    void addSatellite(std::shared_ptr<CelestialBody> satellite);
    void addParentBody(CelestialBody *parent);

    void updateBodyOrbit(int x, int y);
    void updateBodyCenter(int x, int y);

    std::shared_ptr<CelestialPoint> getBodyCenter();

    void setBodyCenter(std::shared_ptr<CelestialPoint> point);

    void draw(QPainter &painter);

protected:
    int bodyRadius;
    int bodyCenterX;
    int bodyCenterY;

    QColor bodyColor;
    QPen pen;
    QBrush brush;

private:
    CelestialBody *parentBody; // Child does not own parent, only observes, so this is fine
    std::shared_ptr<CelestialBodyOrbit> orbit;

    std::vector<std::shared_ptr<CelestialBody>> satellites;
};

#endif // CELESTIALBODY_H
