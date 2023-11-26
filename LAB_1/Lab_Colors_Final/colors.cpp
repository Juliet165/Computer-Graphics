
#include "colors.h"
#include "ui_colors.h"
#include "QWidget"
#include "QtWidgets"

Colors::Colors(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Colors)
{
    ui->setupUi(this);
    resize(400,400);

    color_converter = new QColor();
    space_id = space_name::rgb;
    spaces = {space_name::rgb, space_name::cmyk, space_name::hsv, space_name::hls, space_name::xyz};


    ColorButton = new QPushButton(this);

    backgr= new QGridLayout;
    backgr->setAlignment(Qt::AlignLeft);
    sliders= new QGridLayout;
    sliders->setAlignment(Qt::AlignRight);

    backgr->addLayout(sliders,0,0,4,4);

    LeftCB = new QComboBox;
    CentralCB = new QComboBox;
    RightCB = new QComboBox;

    LeftCB->setStyleSheet("font: 20px \"Verdana\";");
    CentralCB->setStyleSheet("font: 20px \"Verdana\";");
    RightCB->setStyleSheet("font: 20px \"Verdana\";");

    Slider1 = new QSlider;
    Slider1->setRange(0,255);
    Slider1->setOrientation(Qt::Horizontal);
    SliderLabel1 = new QLabel;
    SliderLabel1->setMaximumSize(30,30);
    SliderLabel1->setAlignment(Qt::AlignRight);


    Slider2 = new QSlider;
    Slider2->setRange(0,255);
    Slider2->setOrientation(Qt::Horizontal);
    SliderLabel2 = new QLabel;
    SliderLabel2->setMaximumSize(30,30);
    SliderLabel2->setAlignment(Qt::AlignRight);

    Slider3 = new QSlider;
    Slider3->setRange(0,255);
    Slider3->setOrientation(Qt::Horizontal);
    SliderLabel3 = new QLabel;
    SliderLabel3->setMaximumSize(30,30);
    SliderLabel3->setAlignment(Qt::AlignRight);

    Slider4 = nullptr;
    SliderLabel4 = new QLabel;
    SliderLabel4->setMaximumSize(30,30);
    SliderLabel4->setAlignment(Qt::AlignRight);

    ColorButton->setMaximumSize(200,200);
    ColorButton->setMinimumSize(200,200);
    ColorButton->setStyleSheet("background-color : rgb(0,0,0);""border-radius : 15px;");


    connect(Slider1, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));
    connect(Slider2, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));
    connect(Slider3, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));

    Left1 = new QSpinBox;
    Left2 = new QSpinBox;
    Left3 = new QSpinBox;
    Left4 = nullptr;
    Left1->setMinimumSize(200,20);

    Left1->setRange(0, 255);
    Left2->setRange(0, 255);
    Left3->setRange(0, 255);

    connect(Left1, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));
    connect(Left2, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));
    connect(Left3, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));

    Mid1 = new QSpinBox;
    Mid2 = new QSpinBox;
    Mid3 = new QSpinBox;
    Mid4 = nullptr;
    Mid1->setMinimumSize(200,20);

    Mid1->setReadOnly(true);
    Mid2->setReadOnly(true);
    Mid3->setReadOnly(true);

    Mid1->setRange(0, 100);
    Mid2->setRange(-128, 127);
    Mid3->setRange(-128, 127);

    Right1 = new QSpinBox;
    Right2 = new QSpinBox;
    Right3 = new QSpinBox;
    Right4 = nullptr;
    Right1->setMinimumSize(200,20);

    Right1->setReadOnly(true);
    Right2->setReadOnly(true);
    Right3->setReadOnly(true);

    Right1->setRange(0, 100);
    Right2->setRange(0, 100);
    Right3->setRange(0, 100);

    LLabel1 = new QLabel("R:");
    LLabel2 = new QLabel("G:");
    LLabel3 = new QLabel("B:");
    LLabel4 = new QLabel;

    MLabel1 = new QLabel("L:");
    MLabel2 = new QLabel("A:");
    MLabel3 = new QLabel("B:");
    MLabel4 = new QLabel;

    RLabel1 = new QLabel("H:");
    RLabel2 = new QLabel("S:");
    RLabel3 = new QLabel("V:");
    RLabel4 = new QLabel;

    Names_For_LeftLabels("RGB");
    Names_For_MidLabels("LAB");
    Names_For_RightLabels("HSV");

    backgr->addWidget(ColorButton, 0,5,1,2);

    sliders->addWidget(SliderLabel1,0,0,1,1);
    sliders->addWidget(SliderLabel2,1,0,1,1);
    sliders->addWidget(SliderLabel3,2,0,1,1);
    sliders->addWidget(SliderLabel4,3,0,1,1);

    sliders->addWidget(Slider1,0,1,1,3);
    sliders->addWidget(Slider2,1,1,1,3);
    sliders->addWidget(Slider3,2,1,1,3);

    backgr->addWidget(LeftCB, 5,0,1,2);
    backgr->addWidget(CentralCB,5,2,1,2);
    backgr->addWidget(RightCB, 5,4,1,2);

    backgr->addWidget(Left1, 7,1);
    backgr->addWidget(Left2, 8,1);
    backgr->addWidget(Left3, 9,1);

    backgr->addWidget(LLabel1,7,0);
    backgr->addWidget(LLabel2,8,0);
    backgr->addWidget(LLabel3,9,0);
    backgr->addWidget(LLabel4,10,0);

    backgr->addWidget(Mid1, 7,3);
    backgr->addWidget(Mid2, 8,3);
    backgr->addWidget(Mid3, 9,3);
    backgr->addWidget(Mid4, 10,3);

    backgr->addWidget(MLabel1,7,2);
    backgr->addWidget(MLabel2,8,2);
    backgr->addWidget(MLabel3,9,2);
    backgr->addWidget(MLabel4,10,2);

    backgr->addWidget(Right1, 7,5);
    backgr->addWidget(Right2, 8,5);
    backgr->addWidget(Right3, 9,5);
    backgr->addWidget(Right4, 10,5);

    backgr->addWidget(RLabel1,7,4);
    backgr->addWidget(RLabel2,8,4);
    backgr->addWidget(RLabel3,9,4);
    backgr->addWidget(RLabel4,10,4);

    LeftCB->addItem("RGB");
    LeftCB->addItem("CMYK");
    LeftCB->addItem("HSV");
    LeftCB->addItem("HLS");
    LeftCB->addItem("XYZ");

    //CentralCB->addItem("CMYK");
    CentralCB->addItem("LAB");
    CentralCB->addItem("HSV");
    CentralCB->addItem("RGB");
    CentralCB->addItem("HLS");
    CentralCB->addItem("XYZ");

    RightCB->addItem("HSV");
    RightCB->addItem("CMYK");
    RightCB->addItem("HLS");
    RightCB->addItem("RGB");
    RightCB->addItem("XYZ");
    RightCB->addItem("LAB");

    connect(LeftCB,SIGNAL(currentTextChanged(QString)),this,SLOT(Names_For_LeftLabels(QString)));
    connect(CentralCB,SIGNAL(currentTextChanged(QString)),this,SLOT(Names_For_MidLabels(QString)));
    connect(RightCB,SIGNAL(currentTextChanged(QString)),this,SLOT(Names_For_RightLabels(QString)));

    connect(ColorButton,SIGNAL(clicked()),this,SLOT(ColorPalette()));

    LLabel1->setStyleSheet("font: 20px \"Verdana\";");
    LLabel2->setStyleSheet("font: 20px \"Verdana\";");
    LLabel3->setStyleSheet("font: 20px \"Verdana\";");
    LLabel4->setStyleSheet("font: 20px \"Verdana\";");
    MLabel1->setStyleSheet("font: 20px \"Verdana\";");
    MLabel2->setStyleSheet("font: 20px \"Verdana\";");
    MLabel3->setStyleSheet("font: 20px \"Verdana\";");
    MLabel4->setStyleSheet("font: 20px \"Verdana\";");
    RLabel1->setStyleSheet("font: 20px \"Verdana\";");
    RLabel2->setStyleSheet("font: 20px \"Verdana\";");
    RLabel3->setStyleSheet("font: 20px \"Verdana\";");
    RLabel4->setStyleSheet("font: 20px \"Verdana\";");

    SliderLabel1->setStyleSheet("font: 20px \"Verdana\";");
    SliderLabel2->setStyleSheet("font: 20px \"Verdana\";");
    SliderLabel3->setStyleSheet("font: 20px \"Verdana\";");
    SliderLabel4->setStyleSheet("font: 20px \"Verdana\";");

    this->setLayout(backgr);
}

double Colors::From_RGB_To_XYZ(double a)
{
    double x=a;
    if(x>= 0.04045)
    {
        return pow((x+0.055)/1.055,2.4);
    }
    else return (x/12.92);
}

double Colors::From_XYZ_To_LAB(double a)
{
    double x=a;
    if(x>= 0.008856)
    {
        return pow(x,1.0/3.0);
    }
    else return (7.787*x + 16.0/116.0);
}


QVector<int> Colors::getValues(space_name value_id)
{
    QVector<int> values;
    switch(value_id)
    {
    case space_name::rgb:
        values.push_back(color_converter->red());
        values.push_back(color_converter->green());
        values.push_back(color_converter->blue());
        break;
    case space_name::cmyk:
        int c,m,y,k;
        color_converter->getCmyk(&c,&m,&y,&k);
        values= {c,m,y,k};
        break;
    case space_name::hsv:
        int h,s,v;
        color_converter->getHsv(&h,&s,&v);
        values= {h,s,v};
        break;

    case space_name::hls:
        int h_,l_,s_;
        color_converter->getHsl(&h_,&s_,&l_);
        values= {h_,l_,s_};
        break;
    case space_name::xyz:
    {
        double X,Y,Z;
        double r = color_converter->red();
        double g = color_converter->green();
        double b = color_converter->blue();

        double Rn, Gn, Bn;
        Rn = qMin(qMax(0.0, From_RGB_To_XYZ (r / 255.0) *100.0), 100.0);
        Gn = qMin(qMax(0.0, From_RGB_To_XYZ (g / 255.0) *100.0), 100.0);
        Bn = qMin(qMax(0.0, From_RGB_To_XYZ (b / 255.0) *100.0), 100.0);

        X = 0.412453*Rn + 0.357580*Gn + 0.180423* Bn;
        Y = 0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
        Z = 0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

        values= {int(X),int(Y),int(Z)};
    }
    break;

    case space_name::lab:
    {
        double L,A,B;
        double X,Y,Z;
        double r = color_converter->red();
        double g = color_converter->green();
        double b = color_converter->blue();

        double Rn, Gn, Bn;
        Rn = From_RGB_To_XYZ (r / 255.0) *100.0;
        Gn = From_RGB_To_XYZ (g / 255.0) *100.0;
        Bn = From_RGB_To_XYZ (b / 255.0) *100.0;

        X= 0.412453*Rn + 0.357580*Gn + 0.18042* Bn;
        Y= 0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
        Z= 0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

        double Xw = 95.047;
        double Yw = 100.0;
        double Zw = 108.883;

        L = 116.0 * From_XYZ_To_LAB(Y/Yw) -16.0;
        A = 500.0 *(From_XYZ_To_LAB(X/Xw) - From_XYZ_To_LAB(Y/Yw));
        B = 200.0 *(From_XYZ_To_LAB(Y/Yw) - From_XYZ_To_LAB(Z/Zw));

        values= {int(L),int(A), int (B)};
    }
    break;
    }

    return values;
}



double Colors::From_LAB_To_XYZ(double a)
{
    double x = a;
    if(pow(x,3)>= 0.008856)
    {
        return pow(x,3);
    }
    else return (x-16.0/116.0)/7.787;
}

double Colors::From_XYZ_To_RGB(double a)
{
    double x=a;
    if(x >= 0.0031308)
    {
        return (1.055*pow(x,1.0/2.4)-0.055);
    }
    else return 12.92*x;
}


void Colors::SetColor(space_name value_id, int a, int b, int c, int d)
{
    switch(value_id)
    {
    case space_name::rgb:
        color_converter->setRed(a);
        color_converter->setGreen(b);
        color_converter->setBlue(c);
        break;
    case space_name::cmyk:
        color_converter->setCmyk(a,b,c,d);
        break;
    case space_name::hsv:
        color_converter->setHsv(a,b,c);
        break;

    case space_name::hls:
        color_converter->setHsl(a,c,b);
        break;
    case space_name::xyz:
    {
        double x = a;
        double y_ = b;
        double z = c;
        double Rn = 0.032406 *x - 0.015372*y_ -0.004986* z;
        double Gn = -0.009689 *x + 0.018758 *y_ + 0.000415 * z;
        double Bn= 0.000557 *x - 0.002040 *y_ + 0.010570 * z;


        double R= qMin(qMax(0.0,From_XYZ_To_RGB(Rn)*255), 255.0);
        double G= qMin(qMax(0.0, From_XYZ_To_RGB(Gn)*255), 255.0);
        double B= qMin(qMax(0.0, From_XYZ_To_RGB(Bn)*255), 255.0);

        color_converter->setRed(R);
        color_converter->setGreen(G);
        color_converter->setBlue(B);
    }
    break;
    case space_name::lab:
    {
        double Xw = 95.047;
        double Yw = 100.0;
        double Zw = 108.883;
        double L=a;
        double A=b;
        double B=c;
        double Y = From_LAB_To_XYZ((L+16.0)/116.0)*Yw;
        double X = From_LAB_To_XYZ(A/500.0 + (L+16.0)/116.0)*Xw;
        double Z = From_LAB_To_XYZ((L+16.0)/116.0 - B/200.0)*Zw;

        double Rn = 0.032406 *X - 0.015372*Y -0.004986* Z;
        double Gn = -0.009689 *X + 0.018758 *Y + 0.000415 * Z;
        double Bn = 0.000557 *X - 0.002040 *Y + 0.010570 * Z;

        double R= From_XYZ_To_RGB(Rn)*255;
        double G= From_XYZ_To_RGB(Gn)*255;
        double B_= From_XYZ_To_RGB(Bn)*255;
        if ((R >255) || (R<0) || (G>255) ||(G<0) ||(B_>255) || (B_<0)){
            QMessageBox::warning(0, "Error", "Происходит округление данных!");
        }
        color_converter->setRed(R);
        color_converter->setGreen(G);
        color_converter->setBlue(B_);
    }
    break;
    }
}


void Colors::Names_For_LeftLabels(QString text)
{
    if(text=="RGB")
    {
        space_id = space_name::rgb;
        spaces[0]=space_name::rgb;

        LLabel1->setText("Red:");
        LLabel2->setText("Green:");
        LLabel3->setText("Blue:");
        LLabel4->setText("");

        SliderLabel1->setText("R:");
        SliderLabel2->setText("G:");
        SliderLabel3->setText("B:");
        SliderLabel4->setText("");

        //FirstSliderSetRange();
        //FirstSpinSetRange(Left1);
        Slider1->setMaximum(255);
        Slider2->setMaximum(255);
        Slider3->setMaximum(255);
        Left1->setRange(0, 255);
        Left2->setRange(0, 255);
        Left3->setRange(0, 255);


        if(Left4)
        {
            delete Left4;
            Left4=nullptr;
        }

        if(Slider4)
        {
            delete Slider4;
            Slider4=nullptr;
        }

    }
    if(text=="CMYK")
    {
        space_id = space_name::cmyk;
        spaces[0]=space_name::cmyk;
        Slider1->setMaximum(255);
        Slider2->setMaximum(255);
        Slider3->setMaximum(255);
        Left1->setRange(0, 255);
        Left2->setRange(0, 255);
        Left3->setRange(0, 255);
        Left4 = new QSpinBox;
        Left4->setRange(0, 255);
        connect(Left4, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));
        backgr->addWidget(Left4, 10,1);
        LLabel1->setText("Cyan:");
        LLabel2->setText("Magenta:");
        LLabel3->setText("Yellow:");
        LLabel4->setText("Key:");

        SliderLabel1->setText("C:");
        SliderLabel2->setText("M:");
        SliderLabel3->setText("Y:");
        SliderLabel4->setText("K:");

        Slider4 = new QSlider;
        Slider4->setRange(0, 255);
        Slider4->setOrientation(Qt::Horizontal);
        connect(Slider4, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));
        sliders->addWidget(Slider4,3,1,1,3);

    }
    if(text=="HSV")
    {
        space_id = space_name::hsv;
        spaces[0]=space_name::hsv;
        Slider1->setMaximum(359);
        Slider2->setMaximum(255);
        Slider3->setMaximum(255);
        Left1->setRange(0, 359);
        Left2->setRange(0, 255);
        Left3->setRange(0, 255);
        LLabel1->setText("Hue:");
        LLabel2->setText("Saturation:");
        LLabel3->setText("Value:");
        LLabel4->setText("");

        SliderLabel1->setText("H:");
        SliderLabel2->setText("S:");
        SliderLabel3->setText("V:");
        SliderLabel4->setText("");

        if(Left4)
        {
            delete Left4;
            Left4=nullptr;
        }

        if(Slider4)
        {
            delete Slider4;
            Slider4=nullptr;
        }
    }
    if(text=="HLS")
    {
        space_id = space_name::hls;
        spaces[0]=space_name::hls;
        Slider1->setMaximum(359);
        Slider2->setMaximum(255);
        Slider3->setMaximum(100);
        Left1->setRange(0, 359);
        Left2->setRange(0, 255);
        Left3->setRange(0, 100);
        LLabel1->setText("Hue:");
        LLabel2->setText("Lightness:");
        LLabel3->setText("Saturation:");
        LLabel4->setText("");

        SliderLabel1->setText("H:");
        SliderLabel2->setText("L:");
        SliderLabel3->setText("S:");
        SliderLabel4->setText("");

        if(Left4)
        {
            delete Left4;
            Left4=nullptr;
        }

        if(Slider4)
        {
            delete Slider4;
            Slider4=nullptr;
        }
    }
    if(text=="XYZ")
    {
        space_id = space_name::xyz;
        spaces[0]=space_name::xyz;
        Left1->setRange(0, 96);
        Left2->setRange(0, 100);
        Left3->setRange(0, 108);
        Slider1->setMaximum(96);
        Slider2->setMaximum(100);
        Slider3->setMaximum(108);
        LLabel1->setText("X-value:");
        LLabel2->setText("Y-value:");
        LLabel3->setText("Z-value:");
        LLabel4->setText("");

        SliderLabel1->setText("X:");
        SliderLabel2->setText("Y:");
        SliderLabel3->setText("Z:");
        SliderLabel4->setText("");

        if(Left4)
        {
            delete Left4;
            Left4=nullptr;
        }

        if(Slider4)
        {
            delete Slider4;
            Slider4=nullptr;
        }
    }
    setSliders(getValues(space_id));
    QVector<int> empty;
    setSpinBoxes(getValues(space_id),empty,empty);
}


void Colors::Names_For_MidLabels(QString text)
{
    if(text=="LAB")
    {
        Mid1->setRange(0,100);
        Mid2->setRange(-128,127);
        Mid3->setRange(-128,127);
        spaces[1] = space_name::lab;
        MLabel1->setText("Lightness:");
        MLabel2->setText("A-value:");
        MLabel3->setText("B-value:");
        MLabel4->setText("");
        if(Mid4)
        {
            delete Mid4;
            Mid4=nullptr;
        }
        setSpacesAndColor();
    }

    if(text=="RGB")
    {
        spaces[1] = space_name::rgb;
        //FirstSpinSetRange(Right1);
        Mid1->setRange(0, 255);
        Mid2->setRange(0, 255);
        Mid3->setRange(0, 255);
        MLabel1->setText("Red:");
        MLabel2->setText("Green:");
        MLabel3->setText("Blue:");
        MLabel4->setText("");
        if(Mid4)
        {
            delete Mid4;
            Mid4=nullptr;
        }
        setSpacesAndColor();
    }
    /*if(text=="CMYK")
    {
        spaces[1]= space_name::cmyk;
        //FirstSpinSetRange(Right1);
        Mid1->setRange(0, 255);
        Mid2->setRange(0, 255);
        Mid3->setRange(0, 255);
        Mid4 = new QSpinBox;
        Mid4->setRange(0, 255);
        Mid4->setReadOnly(true);
        backgr->addWidget(Mid4, 10,3);
        MLabel1->setText("Cyan:");
        MLabel2->setText("Magenta:");
        MLabel3->setText("Yellow:");
        MLabel4->setText("Key:");
        setSpacesAndColor();
    }*/

    if(text=="HSV")
    {
        spaces[1] = space_name::hsv;
        //FirstSpinSetRange(Right1, true);
        Mid1->setRange(0, 359);
        Mid2->setRange(0, 255);
        Mid3->setRange(0, 255);
        MLabel1->setText("Hue:");
        MLabel2->setText("Saturation:");
        MLabel3->setText("Value:");
        MLabel4->setText("");
        if(Mid4)
        {
            delete Mid4;
            Mid4=nullptr;
        }
        setSpacesAndColor();
    }
    if(text=="XYZ")
    {
        spaces[1] = space_name::xyz;
        Mid1->setRange(0, 96);
        Mid2->setRange(0, 100);
        Mid3->setRange(0, 108);
        MLabel1->setText("X-value:");
        MLabel2->setText("Y-value:");
        MLabel3->setText("Z-value:");
        MLabel4->setText("");
        if(Mid4)
        {
            delete Mid4;
            Mid4=nullptr;
        }
        setSpacesAndColor();
    }
    if(text=="HLS")
    {
        spaces[1] = space_name::hls;
        //FirstSpinSetRange(Right1, true);
        Mid1->setRange(0, 359);
        Mid2->setRange(0, 255);
        Mid3->setRange(0, 100);
        MLabel1->setText("Hue:");
        MLabel2->setText("Lightness:");
        MLabel3->setText("Saturation:");
        MLabel4->setText("");
        if(Mid4)
        {
            delete Mid4;
            Mid4=nullptr;
        }
        setSpacesAndColor();
    }
}

void Colors::Names_For_RightLabels(QString text)
{
    //Right2->setRange(0,255);
    //Right3->setRange(0,255);
    if(text=="LAB")
    {
        Right1->setRange(0,100);
        Right2->setRange(-128,127);
        Right3->setRange(-128,127);
        spaces[2] = space_name::lab;
        RLabel1->setText("Lightness:");
        RLabel2->setText("A-value:");
        RLabel3->setText("B-value:");
        RLabel4->setText("");
        if(Right4)
        {
            delete Right4;
            Right4=nullptr;
        }
        setSpacesAndColor();
    }

    if(text=="RGB")
    {
        spaces[2] = space_name::rgb;
        //FirstSpinSetRange(Right1);
        Right1->setRange(0, 255);
        Right2->setRange(0, 255);
        Right3->setRange(0, 255);
        RLabel1->setText("Red:");
        RLabel2->setText("Green:");
        RLabel3->setText("Blue:");
        RLabel4->setText("");
        if(Right4)
        {
            delete Right4;
            Right4=nullptr;
        }
        setSpacesAndColor();
    }
    if(text=="CMYK")
    {
        spaces[2]= space_name::cmyk;
        //FirstSpinSetRange(Right1);
        Right1->setRange(0, 255);
        Right2->setRange(0, 255);
        Right3->setRange(0, 255);
        Right4 = new QSpinBox;
        Right4->setRange(0, 255);
        Right4->setReadOnly(true);
        backgr->addWidget(Right4, 10,5);
        RLabel1->setText("Cyan:");
        RLabel2->setText("Magenta:");
        RLabel3->setText("Yellow:");
        RLabel4->setText("Key:");
        setSpacesAndColor();
    }
    if(text=="HSV")
    {
        spaces[2] = space_name::hsv;
        //FirstSpinSetRange(Right1, true);
        Right1->setRange(0, 359);
        Right2->setRange(0, 255);
        Right3->setRange(0, 255);
        RLabel1->setText("Hue:");
        RLabel2->setText("Saturation:");
        RLabel3->setText("Value:");
        RLabel4->setText("");
        if(Right4)
        {
            delete Right4;
            Right4=nullptr;
        }
        setSpacesAndColor();
    }
    if(text=="XYZ")
    {
        spaces[2] = space_name::xyz;
        Right1->setRange(0, 96);
        Right2->setRange(0, 100);
        Right3->setRange(0, 108);
        RLabel1->setText("X-value:");
        RLabel2->setText("Y-value:");
        RLabel3->setText("Z-value:");
        RLabel4->setText("");
        if(Right4)
        {
            delete Right4;
            Right4=nullptr;
        }
        setSpacesAndColor();
    }
    if(text=="HLS")
    {
        spaces[2] = space_name::hls;
        //FirstSpinSetRange(Right1, true);
        Right1->setRange(0, 359);
        Right2->setRange(0, 255);
        Right3->setRange(0, 100);
        RLabel1->setText("Hue:");
        RLabel2->setText("Lightness:");
        RLabel3->setText("Saturation:");
        RLabel4->setText("");
        if(Right4)
        {
            delete Right4;
            Right4=nullptr;
        }
        setSpacesAndColor();
    }
}


void Colors::setSpacesAndColor()
{
    QVector<int> valuesLeft=getValues(spaces[0]);
    QVector<int> valuesMid=getValues(spaces[1]);
    QVector<int> valuesRight=getValues(spaces[2]);

    setSpinBoxes(valuesLeft, valuesMid, valuesRight);
    setColorLabel();
}

void Colors::setSpinsAndLabel()
{
    QVector<int> valuesLeft;
    QVector<int> valuesMid=getValues(spaces[1]);
    QVector<int> valuesRight=getValues(spaces[2]);


    setSpinBoxes(valuesLeft, valuesMid, valuesRight);
    setColorLabel();
}

void Colors::setColorLabel()
{
    r = QString::number(color_converter->red());
    g = QString::number(color_converter->green());
    b = QString::number(color_converter->blue());

    ColorButton->setStyleSheet("background-color:rgb("+r+","+g+","+b+");");
}

void Colors::setSpinBoxes(QVector<int> valuesLeft, QVector<int> valuesMid, QVector<int> valuesRight) {
    if(!valuesLeft.empty())
    {
        spin_changed_manual = true;
        Left1->setValue((valuesLeft[0]));
        spin_changed_manual = true;
        Left2->setValue((valuesLeft[1]));
        spin_changed_manual = true;
        Left3->setValue((valuesLeft[2]));
        if(Left4 != nullptr)
        {
            spin_changed_manual = true;
            Left4->setValue((valuesLeft[3]));
        }
    }

    if(valuesMid.empty()) return;
    spin_changed_manual = true;
    Mid1->setValue((valuesMid[0]));
    spin_changed_manual = true;
    Mid2->setValue((valuesMid[1]));
    spin_changed_manual = true;
    Mid3->setValue((valuesMid[2]));
    if(Mid4 != nullptr)
    {
        spin_changed_manual = true;
        Mid4->setValue((valuesMid[3]));
    }

    if(valuesRight.empty()) return;
    spin_changed_manual = true;
    Right1->setValue((valuesRight[0]));
    spin_changed_manual = true;
    Right2->setValue((valuesRight[1]));
    spin_changed_manual = true;
    Right3->setValue((valuesRight[2]));
    if(Right4 != nullptr)
    {
        spin_changed_manual = true;
        Right4->setValue((valuesRight[3]));
    }
}

void Colors::setSliders(QVector<int> valuesLeft)
{
    slider_changed_manual = true;
    Slider1->setValue((valuesLeft[0]));
    slider_changed_manual = true;
    Slider2->setValue((valuesLeft[1]));
    slider_changed_manual = true;
    Slider3->setValue((valuesLeft[2]));
    if(Slider4 != nullptr)
    {
        slider_changed_manual = true;
        Slider4->setValue((valuesLeft[3]));
    }
}


void Colors::slidersMoved(int a)
{
    if(slider_changed_manual)
    {
        slider_changed_manual=false;
        return;
    }
    int val1= Slider1->value();
    int val2= Slider2->value();
    int val3= Slider3->value();
    int val4=-1;
    if(Slider4 != nullptr)
    {
        val4=Slider4->value();
    }

    SetColor(space_id, val1, val2, val3, val4);
    setSpacesAndColor();
}

void Colors::spinsChanged(int a)
{
    if(spin_changed_manual)
    {
        spin_changed_manual=false;
        return;
    }
    int val1= Left1->value();
    int val2= Left2->value();
    int val3= Left3->value();
    int val4=-1;
    if(Left4 != nullptr)
    {
        val4=Left4->value();
    }


    SetColor(space_id, val1, val2, val3, val4);
    setSpinsAndLabel();
    QVector<int> values = {val1, val2, val3, val4};
    setSliders(values);
}

void Colors::ColorPalette(){
    *color_converter = QColorDialog::getColor(*color_converter);
    std::string str = std::to_string(color_converter->red())+", "+std::to_string(color_converter->green())+", "+std::to_string(color_converter->blue());
    QString color = QString::fromStdString(str);
    ColorButton->setStyleSheet("background-color: rgb("+color+")");
    SetColor(space_name::rgb, color_converter->red(), color_converter->green(), color_converter->blue());
    setSpacesAndColor();
    setSliders(getValues(space_id));
}

Colors::~Colors()
{
    delete ui;
}


