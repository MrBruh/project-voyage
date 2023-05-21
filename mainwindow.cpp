#include "renderarea.h"
#include "mainwindow.h"

#include <QtWidgets>

const int IdRole = Qt::UserRole;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    renderArea = new RenderArea;

    shapeComboBox = new QComboBox;
//    shapeComboBox->addItem(tr("Polygon"), RenderArea::Polygon);
    // Will try a simplified case of only drawing and moving a rectangle
    shapeComboBox->addItem(tr("Rectangle"), RenderArea::Rect);
//    shapeComboBox->addItem(tr("Rounded Rectangle"), RenderArea::RoundedRect);
    shapeComboBox->addItem(tr("Ellipse"), RenderArea::Ellipse);
    shapeComboBox->addItem(tr("Pie"), RenderArea::Pie);
    shapeComboBox->addItem(tr("Chord"), RenderArea::Chord);
//    shapeComboBox->addItem(tr("Path"), RenderArea::Path);
//    shapeComboBox->addItem(tr("Line"), RenderArea::Line);
//    shapeComboBox->addItem(tr("Polyline"), RenderArea::Polyline);
    shapeComboBox->addItem(tr("Arc"), RenderArea::Arc);
//    shapeComboBox->addItem(tr("Points"), RenderArea::Points);
//    shapeComboBox->addItem(tr("Text"), RenderArea::Text);
//    shapeComboBox->addItem(tr("Pixmap"), RenderArea::Pixmap);

    shapeLabel = new QLabel(tr("&Shape:"));
    shapeLabel->setBuddy(shapeComboBox);

    // Decided to keep pen functionality; maybe will do animations with this later
    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
//    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
//    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
//    penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
//    penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
//    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("Pen &Cap:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    // TODO: Figure what is the significance of this
    penJoinLabel = new QLabel(tr("Pen &Join:"));
    penJoinLabel->setBuddy(penJoinComboBox);

    // Only have basic fill paterns of the shapes
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Linear Gradient"),
                                static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("Radial Gradient"),
                                static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("Conical Gradient"),
                                static_cast<int>(Qt::ConicalGradientPattern));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);

    otherOptionsLabel = new QLabel(tr("Options:"));
    antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));

    // Will worry about transformations later, just wanna draw some shapes
    connect(shapeComboBox, &QComboBox::activated,
            this, &MainWindow::shapeChanged);
    connect(penWidthSpinBox, &QSpinBox::valueChanged,
            this, &MainWindow::penChanged);
    connect(penStyleComboBox, &QComboBox::activated,
            this, &MainWindow::penChanged);
    connect(penCapComboBox, &QComboBox::activated,
            this, &MainWindow::penChanged);
    connect(penJoinComboBox, &QComboBox::activated,
            this, &MainWindow::penChanged);
    connect(brushStyleComboBox, &QComboBox::activated,
            this, &MainWindow::brushChanged);
    connect(antialiasingCheckBox, &QAbstractButton::toggled,
            renderArea, &RenderArea::setAntialiased);

    // Layout definition
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4); // there is something about this line I don't understand
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(shapeComboBox, 2, 1);
    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 1);
    mainLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 4, 1);
    mainLayout->addWidget(penCapLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penCapComboBox, 3, 3);
    mainLayout->addWidget(penJoinLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(penJoinComboBox, 2, 3);
    mainLayout->addWidget(brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 3);
    mainLayout->addWidget(otherOptionsLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(antialiasingCheckBox, 5, 1, 1, 1, Qt::AlignRight);
//    mainLayout->addWidget(transformationsCheckBox, 5, 2, 1, 2, Qt::AlignRight);

    // Needed for setting a layout on a MainWindow
    layoutWidget = new QWidget;
    layoutWidget->setLayout(mainLayout);

    this->setCentralWidget(layoutWidget);

    shapeChanged();
    penChanged();
    brushChanged();
    antialiasingCheckBox->setChecked(true);

    setWindowTitle(tr("Yeehaw"));
}

MainWindow::~MainWindow()
{
}

// Called whenever the user changes the shape
void MainWindow::shapeChanged()
{
    RenderArea::Shape shape = RenderArea::Shape(shapeComboBox->itemData(
                                                                 shapeComboBox->currentIndex(), IdRole).toInt());
    renderArea->setShape(shape);
}

void MainWindow::penChanged()
{
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                                          penStyleComboBox->currentIndex(), IdRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(
                                                            penCapComboBox->currentIndex(), IdRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                                penJoinComboBox->currentIndex(), IdRole).toInt());

    renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
}

void MainWindow::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(
                                                                //! [13]
                                                                brushStyleComboBox->currentIndex(), IdRole).toInt());

    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(linearGradient);
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(conicalGradient);
    } else if (style == Qt::TexturePattern) {
        renderArea->setBrush(QBrush(QPixmap(":/images/brick.png")));
    } else {
        renderArea->setBrush(QBrush(Qt::green, style));
    }
}

