#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE
class RenderArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();


private:
    RenderArea *renderArea;
    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *otherOptionsLabel;
    QComboBox *shapeComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QCheckBox *antialiasingCheckBox;
    QCheckBox *transformationsCheckBox;

    QWidget *layoutWidget;
};

#endif // MAINWINDOW_H
