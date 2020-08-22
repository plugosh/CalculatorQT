#include "calculator.h"
#include "ui_calculator.h"



void Calculator::checkLastSign()
{
    QString DisplayValue = ui->Display->text();
    QPushButton *button=(QPushButton *)sender();
    QString buttonValue = button->text();
    std::string ButVal = buttonValue.toStdString();

    if(QString::compare(lastSign,buttonValue, Qt::CaseInsensitive)==0)
    {
        ui->Display->setText(DisplayValue);
    }
    else if(QString::compare(lastSign,"+", Qt::CaseInsensitive)==0)
    {
        std::string DisVal = DisplayValue.toStdString();
        int charIterator = DisVal.size();
        DisVal[charIterator-1]=ButVal[0];
        DisplayValue=QString::fromStdString(DisVal);
        ui->Display->setText(DisplayValue);
    }
    else if(QString::compare(lastSign,"*", Qt::CaseInsensitive)==0)
    {
        std::string DisVal = DisplayValue.toStdString();
        int charIterator = DisVal.size();
        DisVal[charIterator-1]=ButVal[0];
        DisplayValue=QString::fromStdString(DisVal);
        ui->Display->setText(DisplayValue);
    }
    else if(QString::compare(lastSign,"/", Qt::CaseInsensitive)==0)
    {
        std::string DisVal = DisplayValue.toStdString();
        int charIterator = DisVal.size();
        DisVal[charIterator-1]=ButVal[0];
        DisplayValue=QString::fromStdString(DisVal);
        ui->Display->setText(DisplayValue);
    }
    else if(QString::compare(lastSign,"-", Qt::CaseInsensitive)==0)
    {
        std::string DisVal = DisplayValue.toStdString();
        int charIterator = DisVal.size();
        DisVal[charIterator-1]=ButVal[0];
        DisplayValue=QString::fromStdString(DisVal);
        ui->Display->setText(DisplayValue);
    }
    else if(QString::compare(lastSign,".", Qt::CaseInsensitive)==0)
    {
        std::string DisVal = DisplayValue.toStdString();
        int charIterator = DisVal.size();
        DisVal[charIterator-1]=ButVal[0];
        DisplayValue=QString::fromStdString(DisVal);
        ui->Display->setText(DisplayValue);
    }
    else if(QString::compare(lastSign,"(", Qt::CaseInsensitive)==0)
    {
        return;
    }
    else {
        ui->Display->setText(DisplayValue+buttonValue);
    }
    lastSign = buttonValue;
}

bool Calculator::CheckIfZero(bool &isZero)
{
    QString displayValue = ui->Display->text();
    if(QString::compare(displayValue,"0", Qt::CaseInsensitive)==0)
    {
        isZero = true;
    }
    else
    {
        isZero = false;
    }
    return isZero;
}

void Calculator::CheckIfAction()
{

    QString DisplayValue = ui->Display->text();
    std::string check = DisplayValue.toStdString();
    int size = check.size();
    if(check[size-1]=='+'||check[size-1]=='-'||check[size-1]=='*'||check[size-1]=='/'||check[size-1]=='(')
    {
        return;
    }
    else
    {
        ui->Display->setText(DisplayValue+"*");
    }
}

void Calculator::shiftChange()
{
    if(!shiftActive)
    {
    ui->shiftWidget->setVisible(true);
    shiftActive=true;
    }
    else
    {
    ui->shiftWidget->setVisible(false);
    shiftActive=false;
    }
}

void Calculator::matrixChange()
{
    if(!matrixActive)
    {
    ui->matrixWidget->setVisible(true);
    matrixActive=true;
    }
    else
    {
    ui->matrixWidget->setVisible(false);
    matrixActive=false;
    }
}

void Calculator::SetRad()
{
    isRadius=true;
    ui->toggleRad->setStyleSheet("background-color: #D2691E");
    ui->toggleDeg->setStyleSheet("background-color: MistyRose");
}

void Calculator::SetDeg()
{
    isRadius=false;
    ui->toggleDeg->setStyleSheet("background-color: #D2691E");
    ui->toggleRad->setStyleSheet("background-color: MistyRose");
}

