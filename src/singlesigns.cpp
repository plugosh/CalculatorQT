#include "calculator.h"
#include "ui_calculator.h"

void Calculator::leftBracket()
{
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();

    if(isZero)
    {
        ui->Display->setText("(");
    }
    else
    {
        QString DisplayValue = ui->Display->text();
        ui->Display->setText(DisplayValue+"(");
    }
}


void Calculator::rightBracket()
{
    QString DisplayValue = ui->Display->text();
    std::string checkBracket = DisplayValue.toStdString();
    bool isLeftBracket=false;
    int size = checkBracket.size();
    int rightBr=0;
    int leftBr=0;

    for(int i=0;i<size;++i)
    {
        if(checkBracket[i]=='(')
        {
            isLeftBracket=true;
            leftBr++;
        }
        if(checkBracket[i]==')')
        {
            rightBr++;
        }
    }


    //1234(    size = 5
    //01234
    if(checkBracket[size-1]=='(')
    {
        return;
    }
    else if(!isLeftBracket)
    {
        return;
    }
    else if(leftBr==rightBr)
    {
        return;
    }
    else
    {
    ui->Display->setText(DisplayValue+")");
    }
}

void Calculator::e()
{
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();
    QString DisplayValue = ui->Display->text();
    if(isZero)
    {
        ui->Display->setText("e");
    }
    else
    {
        ui->Display->setText(DisplayValue+"e");
    }
    lastSign = "e";
}

void Calculator::PI()
{
    Calculator::CheckIfZero(isZero);
    Calculator::CheckIfAction();
    QString DisplayValue = ui->Display->text();
    if(isZero)
    {
        ui->Display->setText("p");
    }
    else
    {
        ui->Display->setText(DisplayValue+"p");
    }
    lastSign = "p";
}


void Calculator::dotButton()
{
    QString DisplayValue = ui->Display->text();
    std::string check = DisplayValue.toStdString();
    int size = check.size();


        if(check[size-1]=='+'||check[size-1]=='-'||check[size-1]=='*'||check[size-1]=='/'||check[size-1]=='(')
        {
            ui->Display->setText(DisplayValue+"0.");
        }
        else if(check[size-1]=='.')
        {
            return;
        }
        else
        {
            ui->Display->setText(DisplayValue+".");
        }



    lastSign = ".";
}
