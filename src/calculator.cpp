#include "calculator.h"
#include "ui_calculator.h"
#include <math.h>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);  
//SADFSADFASDFSA
    ui->det2->setText(QString::number(0));
    ui->Display->setText(QString::number(0));
    ui->shiftWidget->setVisible(false);
    ui->matrixWidget->setVisible(false);
    ui->ApplyWidget->setVisible(false);


    ui->toggleRad->setStyleSheet("background-color: #D2691E");
    ui->toggleDeg->setStyleSheet("background-color: MistyRose");

    //numbers and trygonometry
    QPushButton *sButtons[18];
    for(int i=0;i<18;++i)
    {
        QString buttonName="b_"+QString::number(i);
        sButtons[i]=Calculator::findChild<QPushButton *>(buttonName);
        if(i<10){
            connect(sButtons[i], SIGNAL(released()),this,SLOT(NumberPressed()));
        }
        else {
            connect(sButtons[i], SIGNAL(released()),this,SLOT(TrgFunctions()));
        }
    }

    connect(ui->add,SIGNAL(released()),this,SLOT(fadd()));
    connect(ui->subtract,SIGNAL(released()),this,SLOT(fsubtract()));
    connect(ui->divade,SIGNAL(released()),this,SLOT(fdivade()));
    connect(ui->multiply,SIGNAL(released()),this,SLOT(fmultiply()));
    connect(ui->allClear,SIGNAL(released()),this,SLOT(allClear()));
    connect(ui->b_leftBracket,SIGNAL(released()),this,SLOT(leftBracket()));
    connect(ui->b_rightBracket,SIGNAL(released()),this,SLOT(rightBracket()));
    connect(ui->b_clear,SIGNAL(released()),this,SLOT(Clear()));
    connect(ui->Off,SIGNAL(released()),this,SLOT(TurnOff()));
    connect(ui->OFF2,SIGNAL(released()),this,SLOT(TurnOff()));
    connect(ui->Log,SIGNAL(released()),this,SLOT(Log()));
    connect(ui->naturalLog,SIGNAL(released()),this,SLOT(Ln()));
    connect(ui->power,SIGNAL(released()),this,SLOT(xPowy()));
    connect(ui->b_e,SIGNAL(released()),this,SLOT(e()));
    connect(ui->b_PI,SIGNAL(released()),this,SLOT(PI()));
    connect(ui->b_e_2,SIGNAL(released()),this,SLOT(e()));
    connect(ui->b_PI_2,SIGNAL(released()),this,SLOT(PI()));
    connect(ui->root,SIGNAL(released()),this,SLOT(SquareRoot()));
    connect(ui->SHIFT,SIGNAL(released()),this,SLOT(shiftChange()));
    connect(ui->SHIFT_2,SIGNAL(released()),this,SLOT(shiftChange()));
    connect(ui->toComplex,SIGNAL(released()),this,SLOT(matrixChange()));
    connect(ui->toCalc,SIGNAL(released()),this,SLOT(matrixChange()));
    connect(ui->toggleDeg,SIGNAL(released()),this,SLOT(SetDeg()));
    connect(ui->toggleRad,SIGNAL(released()),this,SLOT(SetRad()));
    connect(ui->epowx,SIGNAL(released()),this,SLOT(ePowx()));
    connect(ui->tenpowx,SIGNAL(released()),this,SLOT(tenPowx()));
    connect(ui->b_DOT,SIGNAL(released()),this,SLOT(dotButton()));
    connect(ui->solution,SIGNAL(released()),this,SLOT(SOLUTION()));
    connect(ui->Det,SIGNAL(released()),this,SLOT(SetDet()));
    connect(ui->Rev,SIGNAL(released()),this,SLOT(SetReverse()));
    connect(ui->ClearMatrix,SIGNAL(released()),this,SLOT(ClearMatrix()));
    connect(ui->Add,SIGNAL(released()),this,SLOT(addMatrix()));
    connect(ui->Mult,SIGNAL(released()),this,SLOT(multMatrix()));
    connect(ui->Apply,SIGNAL(released()),this,SLOT(addmultMatrix()));
}


Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumberPressed()
{
    QPushButton *button=(QPushButton *)sender();
    QString buttonValue = button->text();
    QString displayValue = ui->Display->text();
    Calculator::CheckIfZero(isZero);
    if(isZero)
    {
        ui->Display->setText(buttonValue);
    }
    else
    {
        std::string isbracket = displayValue.toStdString();
        if(isbracket[isbracket.size()]-1==')')
        {
            ui->Display->setText(displayValue+"*"+buttonValue);
        }
        else
        {
            ui->Display->setText(displayValue+buttonValue);
        }
    }

    lastSign = buttonValue;
}

void Calculator::allClear()
{
    ui->Display->setText("0");
    lastSign = 'n';
}

void Calculator::Clear()
{
QString DisplayValue=ui->Display->text();
std::string DisVal = DisplayValue.toStdString();

int size = DisVal.size();

if(size>1)
{
    DisVal.erase(size-1,1);
    DisplayValue=(QString::fromStdString(DisVal));
    ui->Display->setText(DisplayValue);
}
else
{
    ui->Display->setText("0");
}

    lastSign = DisVal[DisVal.size()-1];

}

void Calculator::TurnOff()
{
    QApplication::quit();
}
