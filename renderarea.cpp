#include "renderarea.h"
#include "celestial_body/celestialbody.h"

#include <QPainter>
#include <QPainterPath>

//! [0]
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    QPalette backgroundColourPal = QPalette();
    QColor spaceBlueColor = QColor(17, 26, 66);

    // #111a42
    backgroundColourPal.setColor(QPalette::Window, spaceBlueColor);

//    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setPalette(backgroundColourPal);
}
//! [0]

//! [1]
QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
//! [1]

//! [2]
QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}
//! [2]

//! [3]
void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
//! [3]

//! [4]
void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}
//! [4]

//! [5]
void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
//! [5]

//! [6]
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
//! [7]

//! [8]
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    static const QPoint points[5] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70),
        QPoint(0, 0)
    };

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;

    int startOrbit = 0;
    int fullOrbit = 360 * 16;
    //! [8]

    //! [9]
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);
    //! [9]

    std::shared_ptr<CelestialBody> sun = std::make_shared<CelestialBody>(width()/2, height()/2);
    std::shared_ptr<CelestialBody> earth = std::make_shared<CelestialBody>(width()/2 - 100, height()/2, 5, 100);

    sun->addSatellite(std::shared_ptr<CelestialBody>(earth));

    sun->draw(painter);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
