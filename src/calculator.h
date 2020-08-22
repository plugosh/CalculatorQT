#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "cmatrix.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{

    Q_OBJECT



public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

    //friend class m2x2;
    //friend class m3x3;
    //friend class m4x4;

    //matrixFunctions
    void getMatrixVal(cMatrix *ptr,int TabIndex);





private:
    Ui::Calculator *ui;

    cMatrix *ptr;
    QString lastSign;
    bool isZero;
    bool shiftActive=false;
    bool matrixActive=false;
    bool isRadius=true;
    bool matrixMultiplyActive=false;
    int brackets=0;

    m2x2 Matrix_2x2;
    m3x3 Matrix_3x3;
    m4x4 Matrix_4x4;

private slots:


    //control functions
    void checkLastSign();
    void CheckIfAction();
    bool CheckIfZero(bool &isZero);
    void shiftChange();
    void matrixChange();
    void SetRad();
    void SetDeg();

    //main functions / calculator.cpp
    void NumberPressed();
    void allClear();
    void Clear();
    void TurnOff();

    //basic operations
    void fadd();
    void fsubtract();
    void fmultiply();
    void fdivade();



    //math functions
    void Log();
    void Ln();
    void SquareRoot();
    void xPowy();
    void TrgFunctions();
    void ePowx();
    void tenPowx();

    //single signs functions
    void PI();
    void e();
    void rightBracket();
    void leftBracket();
    void dotButton();

    //solution
    void SetBracketNumber(QString &displayValue);
    void SOLUTION();
    void CalculatingProcess_Brackets(std::string &equation,const bool Minus,double &FinalSolution,std::string &DisVal,
                            const int leftBracketPos,const int rightBracketPos,std::string &FSol);
    void CalculatingProcess_NoBrackets(std::string &equation,const bool Minus,double &FinalSolution,std::string &DisVal,std::string &FSol);
    void PowerFunctions(std::string &DisVal,const double FinalSolution,const int leftBracketPos,const int rightBracketPos);
    std::string SinAndTan(std::string &DisVal,const double FinalSolution,const int leftBracketPos,const int rightBracketPos);
    std::string CosAndCtg(std::string &DisVal,const double FinalSolution,const int leftBracketPos,const int rightBracketPos);


    //matrixSlots
    void ClearMatrix();
    void SetDet();
    void SetReverse();
    void addMatrix();
    void multMatrix();
    void addmultMatrix();

};

#endif // CALCULATOR_H

/*
dokoncz odwrotna
*/
