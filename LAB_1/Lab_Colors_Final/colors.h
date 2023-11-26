
#ifndef COLORS_H
#define COLORS_H

#include <QWidget>
#include "QtWidgets"

enum space_name
{
    rgb=0,
    cmyk,
    hsv,
    xyz,
    hls,
    lab
};

QT_BEGIN_NAMESPACE
namespace Ui { class Colors; }
QT_END_NAMESPACE

class Colors : public QWidget

{
    Q_OBJECT

public:
    Colors(QWidget *parent = nullptr);
    ~Colors();
signals:
    void Color(QColor color);
public slots:

    void Names_For_LeftLabels(QString text);
    void Names_For_MidLabels(QString text);
    void Names_For_RightLabels(QString text);
    QVector <int> getValues(space_name value_id);
    void SetColor(space_name value_id, int a,int b,int c, int d = -1);
    void ColorPalette();
    void slidersMoved(int a);
    void spinsChanged(int a);
    void setSpacesAndColor();
    void setColorLabel();
    void setSpinBoxes(QVector<int> valuesLeft, QVector<int> valuesMid, QVector<int> valuesRight);
    void setSliders(QVector<int> valuesLeft);
    void setSpinsAndLabel();

    double From_RGB_To_XYZ(double a);
    double From_XYZ_To_LAB(double a);

    double From_XYZ_To_RGB(double a);
    double From_LAB_To_XYZ(double a);

private:
    Ui::Colors *ui;
    QColor *color_converter;
    space_name space_id;

    bool spin_changed_manual=false;
    bool slider_changed_manual = false;
    QVector<space_name> spaces;

    QString r;
    QString g;
    QString b;

    QSlider *Slider1;
    QSlider *Slider2;
    QSlider *Slider3;
    QSlider *Slider4;

    QComboBox *LeftCB;
    QComboBox *CentralCB;
    QComboBox *RightCB;

    QGridLayout *backgr;
    QGridLayout *sliders;

    QSpinBox *Left1;
    QSpinBox *Left2;
    QSpinBox *Left3;
    QSpinBox *Left4;

    QSpinBox *Mid1;
    QSpinBox *Mid2;
    QSpinBox *Mid3;
    QSpinBox *Mid4;

    QSpinBox *Right1;
    QSpinBox *Right2;
    QSpinBox *Right3;
    QSpinBox *Right4;

    QLabel*SliderLabel1;
    QLabel*SliderLabel2;
    QLabel*SliderLabel3;
    QLabel*SliderLabel4;


    QLabel *LLabel1;
    QLabel *LLabel2;
    QLabel *LLabel3;
    QLabel *LLabel4;

    QLabel *MLabel1;
    QLabel *MLabel2;
    QLabel *MLabel3;
    QLabel *MLabel4;

    QLabel *RLabel1;
    QLabel *RLabel2;
    QLabel *RLabel3;
    QLabel *RLabel4;

    QPushButton *ColorButton;

    void FirstSliderSetRange(bool hueSpace = false);
    void FirstSpinSetRange(QSpinBox* spin, bool hueSpace = false);
};

#endif // COLORS_H
