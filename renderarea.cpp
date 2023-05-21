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

    int rectWidth = 80;
    int rectHeight = 80;
    QRect rect(0, 0, rectWidth, rectHeight);

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

    //! [10]
//    for (int x = 0; x < width(); x += 200) {
//        for (int y = 0; y < height(); y += 200) {
    painter.save();
    painter.translate((width()-rectWidth)/2, (height()-rectHeight)/2);
    //! [10] //! [11]
    if (transformed) {
        painter.translate(50, 50);
        painter.rotate(60.0);
        painter.scale(0.6, 0.9);
        painter.translate(-50, -50);
    }
    //! [11]

    //! [12]
//    switch (shape) {
//    case Line:
//        painter.drawLine(rect.bottomLeft(), rect.topRight());
//        break;
//    case Points:
//        painter.drawPoints(points, 4);
//        break;
//    case Polyline:
//        painter.drawPolyline(points, 4);
//        break;
//    case Polygon:
//        painter.drawPolygon(points, 4);
//        break;
//    case Rect:
//        painter.drawRect(rect);
//        break;
//    case RoundedRect:
//        painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
//        break;
//    case Ellipse:
//        painter.drawEllipse(rect);
//        break;
//    case Arc:
//        painter.drawArc(rect, startAngle, arcLength);
//        break;
//    case Chord:
//        painter.drawChord(rect, startAngle, arcLength);
//        break;
//    case Pie:
//        painter.drawPie(rect, startAngle, arcLength);
//        break;
//    case Path:
//        painter.drawPath(path);
//        break;
//    case Text:
//        painter.drawText(rect,
//                         Qt::AlignCenter,
//                         tr("Qt by\nThe Qt Company"));
//        break;
//    case Pixmap:
//        painter.drawPixmap(10, 10, pixmap);
//    }

    //! [12] //! [13]
    painter.restore();

    CelestialBody sun = CelestialBody(width()/2, height()/2);
    CelestialBody earth = CelestialBody(width()/2 - 100, height()/2, 5, 100);

    sun.draw(painter);
    earth.draw(painter);

//        }
//    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
//! [13]
