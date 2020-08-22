#include "calculator.h"
#include "ui_calculator.h"

void Calculator::fadd()
{
    QString DisplayValue = ui->Display->text();
    Calculator::checkLastSign();
}

void Calculator::fsubtract()
{
    QString DisplayValue = ui->Display->text();
    Calculator::checkLastSign();
}

void Calculator::fmultiply()
{
    QString DisplayValue = ui->Display->text();
    Calculator::checkLastSign();
}

void Calculator::fdivade()
{
    QString DisplayValue = ui->Display->text();
    Calculator::checkLastSign();
}
