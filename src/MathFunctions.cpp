#include "calculator.h"
#include "ui_calculator.h"
#include <string>

void Calculator::Log()
{
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();
    QString DisplayValue = ui->Display->text();
    if(isZero)
    {
        ui->Display->setText("Log(");
    }
    else
    {
        ui->Display->setText(DisplayValue+"Log(");
    }
    lastSign = "(";
}

void Calculator::Ln()
{
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();
    QString DisplayValue = ui->Display->text();
    if(isZero)
    {
        ui->Display->setText("Ln(");
    }
    else
    {
        ui->Display->setText(DisplayValue+"Ln(");
    }
    lastSign = "(";
}

void Calculator::SquareRoot()
{
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();
    QString DisplayValue = ui->Display->text();
    if(isZero)
    {
        ui->Display->setText("V(");
    }
    else
    {
        ui->Display->setText(DisplayValue+"V(");
    }
    lastSign = "(";
}

void Calculator::xPowy()
{
    QString DisplayValue = ui->Display->text();
    Calculator::CheckIfZero(isZero);

    std::string check = DisplayValue.toStdString();
    int size = check.size();




    DisplayValue = ui->Display->text();

    if(isZero)
    {
    ui->Display->setText(DisplayValue+"^(");
    }
    else
    {
        if(check[size-1]=='+'||check[size-1]=='-'||check[size-1]=='*'||check[size-1]=='/'||check[size-1]=='(')
        {
            check[size-1]='^';
            DisplayValue = QString::fromStdString(check);
            ui->Display->setText(DisplayValue+"(");
        }
        else
        {
            ui->Display->setText(DisplayValue+"^(");
        }

    }
    lastSign = "(";
}

/*void Calculator::Factorial()
{
    Calculator::checkLastSign();
    QString DisplayValue = ui->Display->text();
    std::string DisVal=DisplayValue.toStdString();
    int otherSign;

    for (int i=DisVal.size()-1;i>=0;--i)
    {

        if(DisVal[i]=='+'||DisVal[i]=='-'||DisVal[i]=='*'||DisVal[i]=='/')
        {
            otherSign=i;
            break;
        }
        otherSign=-1;
    }
    //equation.insert(0, DisVal, LB+1, size);
    if(otherSign==-1)
    {
    std::string newDisVal = "(" + DisVal +")";
    DisplayValue = QString::fromStdString(newDisVal);
    ui->Display->setText(DisplayValue);
    }
    else
    {
    DisVal.insert(otherSign+1,"(");
    DisVal.insert(DisVal.size()-1,")");
    DisplayValue = QString::fromStdString(DisVal);
    ui->Display->setText(DisplayValue);
    }

}*/

void Calculator::TrgFunctions()
{
    QPushButton *but=(QPushButton *)sender();
    QString trgVal = but->text();
    QString displayValue = ui->Display->text();
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();

    if(isZero)
    {
        ui->Display->setText(trgVal+"(");
    }
    else
    {
        std::string check = displayValue.toStdString();
        int size = check.size();
        bool isAct;
        if(check[size-1]=='+'||check[size-1]=='-'||check[size-1]=='*'||check[size-1]=='/')
        {
            isAct = true;
        }
        if(check[size-1]>47&&check[size-1]<58)
        {
            displayValue += "*";
        }

        if(!isAct)
        {
            displayValue += "*";
        }

        std::string isbracket = displayValue.toStdString();
        if(isbracket[isbracket.size()]-1==')')
        {
            ui->Display->setText(displayValue+"*"+trgVal+"(");
        }
        else
        {
            ui->Display->setText(displayValue+trgVal+"(");
        }
    }

    lastSign = "(";
}

void Calculator::ePowx()
{
    QString DisplayValue = ui->Display->text();
    Calculator::CheckIfZero(isZero);
    DisplayValue = ui->Display->text();



    if(isZero)
    {
    ui->Display->setText("e^(");
    }
    else
    {
    ui->Display->setText(DisplayValue+"e^(");
    }
    lastSign = "(";
}

void Calculator::tenPowx()
{
    QString DisplayValue = ui->Display->text();
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();
    DisplayValue = ui->Display->text();

    if(isZero)
    {
    ui->Display->setText("10^(");
    }
    else
    {
    ui->Display->setText(DisplayValue+"10^(");
    }
    lastSign = "(";

}
