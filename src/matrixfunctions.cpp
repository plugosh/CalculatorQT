#include "calculator.h"
#include "ui_calculator.h"
#include "cmatrix.h"
#include <QMessageBox>

//slots
void Calculator::SetDet()
{
    int TabIndex = ui->tabWidget->currentIndex();

    if(TabIndex==0) ptr = &Matrix_2x2;
    else if(TabIndex==1) ptr = &Matrix_3x3;
    else ptr = &Matrix_4x4;

    Calculator::getMatrixVal(ptr,TabIndex);

    double DetVal=ptr->getDeterminant();

    QString DV = QString::number(DetVal);


    if(TabIndex==0) ui->det2->setText(DV);
    else if(TabIndex==1) ui->det3->setText(DV);
    else ui->det4->setText(DV);

}

void Calculator::SetReverse()
{
    std::string *Array;

    int TabIndex = ui->tabWidget->currentIndex();

    if(TabIndex==0) {
        ptr = &Matrix_2x2;
        Array = new std::string[4];
    }
    else if(TabIndex==1) {
        ptr = &Matrix_3x3;
        Array = new std::string[4];
    }
    else {
        ptr = &Matrix_4x4;
        Array = new std::string[4];
    }

    Calculator::getMatrixVal(ptr,TabIndex);

    double DetVal;

    DetVal = ptr->getDeterminant();

    if(DetVal==0.0)
    {
        QMessageBox::about(this,"Nie można odwrócić macierzy","Wyznacznik macierzy jest równy 0");
        return;
    }
    else
    {
        ptr->fReverse();
        if(TabIndex==0)
        {
            ui->m2_1->setText(QString::number(ptr->ReverseValue(0)));
            ui->m2_2->setText(QString::number(ptr->ReverseValue(1)));
            ui->m2_3->setText(QString::number(ptr->ReverseValue(2)));
            ui->m2_4->setText(QString::number(ptr->ReverseValue(3)));
        }
        else if(TabIndex==1)
        {
            ui->m3_1->setText(QString::number(ptr->ReverseValue(0)));
            ui->m3_2->setText(QString::number(ptr->ReverseValue(1)));
            ui->m3_3->setText(QString::number(ptr->ReverseValue(2)));
            ui->m3_4->setText(QString::number(ptr->ReverseValue(3)));
            ui->m3_5->setText(QString::number(ptr->ReverseValue(4)));
            ui->m3_6->setText(QString::number(ptr->ReverseValue(5)));
            ui->m3_7->setText(QString::number(ptr->ReverseValue(6)));
            ui->m3_8->setText(QString::number(ptr->ReverseValue(7)));
            ui->m3_9->setText(QString::number(ptr->ReverseValue(8)));
        }
        else
        {
            ui->m4_1->setText(QString::number(ptr->ReverseValue(0)));
            ui->m4_2->setText(QString::number(ptr->ReverseValue(1)));
            ui->m4_3->setText(QString::number(ptr->ReverseValue(2)));
            ui->m4_4->setText(QString::number(ptr->ReverseValue(3)));
            ui->m4_5->setText(QString::number(ptr->ReverseValue(4)));
            ui->m4_6->setText(QString::number(ptr->ReverseValue(5)));
            ui->m4_7->setText(QString::number(ptr->ReverseValue(6)));
            ui->m4_8->setText(QString::number(ptr->ReverseValue(7)));
            ui->m4_9->setText(QString::number(ptr->ReverseValue(8)));
            ui->m4_10->setText(QString::number(ptr->ReverseValue(9)));
            ui->m4_11->setText(QString::number(ptr->ReverseValue(10)));
            ui->m4_12->setText(QString::number(ptr->ReverseValue(11)));
            ui->m4_13->setText(QString::number(ptr->ReverseValue(12)));
            ui->m4_14->setText(QString::number(ptr->ReverseValue(13)));
            ui->m4_15->setText(QString::number(ptr->ReverseValue(14)));
            ui->m4_16->setText(QString::number(ptr->ReverseValue(15)));
        }
    }


}

//functions
void Calculator::getMatrixVal(cMatrix *ptr,int TabIndex)
{
    std::string *Array;

    if(TabIndex==0)
    {
        Array = new std::string[4];

        QString Val;
        Val = ui->m2_1->text(); Array[0]=Val.toStdString();
        Val = ui->m2_2->text(); Array[1]=Val.toStdString();
        Val = ui->m2_3->text(); Array[2]=Val.toStdString();
        Val = ui->m2_4->text(); Array[3]=Val.toStdString();
        ptr->setValues(Array);


    }
    else if(TabIndex==1)
    {
        Array = new std::string[9];

        QString Val;

        Val = ui->m3_1->text(); Array[0]=Val.toStdString();
        Val = ui->m3_2->text(); Array[1]=Val.toStdString();
        Val = ui->m3_3->text(); Array[2]=Val.toStdString();
        Val = ui->m3_4->text(); Array[3]=Val.toStdString();
        Val = ui->m3_5->text(); Array[4]=Val.toStdString();
        Val = ui->m3_6->text(); Array[5]=Val.toStdString();
        Val = ui->m3_7->text(); Array[6]=Val.toStdString();
        Val = ui->m3_8->text(); Array[7]=Val.toStdString();
        Val = ui->m3_9->text(); Array[8]=Val.toStdString();


        ptr->setValues(Array);

    }
    else
    {
        Array = new std::string[16];

        QString Val;

        Val = ui->m4_1->text(); Array[0]=Val.toStdString();
        Val = ui->m4_2->text(); Array[1]=Val.toStdString();
        Val = ui->m4_3->text(); Array[2]=Val.toStdString();
        Val = ui->m4_4->text(); Array[3]=Val.toStdString();
        Val = ui->m4_5->text(); Array[4]=Val.toStdString();
        Val = ui->m4_6->text(); Array[5]=Val.toStdString();
        Val = ui->m4_7->text(); Array[6]=Val.toStdString();
        Val = ui->m4_8->text(); Array[7]=Val.toStdString();
        Val = ui->m4_9->text(); Array[8]=Val.toStdString();
        Val = ui->m4_10->text(); Array[9]=Val.toStdString();
        Val = ui->m4_11->text(); Array[10]=Val.toStdString();
        Val = ui->m4_12->text(); Array[11]=Val.toStdString();
        Val = ui->m4_13->text(); Array[12]=Val.toStdString();
        Val = ui->m4_14->text(); Array[13]=Val.toStdString();
        Val = ui->m4_15->text(); Array[14]=Val.toStdString();
        Val = ui->m4_16->text(); Array[15]=Val.toStdString();

        ptr->setValues(Array);

    }

    delete [] Array;

}

void Calculator::ClearMatrix()
{
    int TabIndex = ui->tabWidget->currentIndex();

    if(TabIndex==0)
    {
        ui->m2_1->setText("");
        ui->m2_2->setText("");
        ui->m2_3->setText("");
        ui->m2_4->setText("");
        ui->det2->setText("0");
    }
    else if(TabIndex==1)
    {
        ui->m3_1->setText("");
        ui->m3_2->setText("");
        ui->m3_3->setText("");
        ui->m3_4->setText("");
        ui->m3_5->setText("");
        ui->m3_6->setText("");
        ui->m3_7->setText("");
        ui->m3_8->setText("");
        ui->m3_9->setText("");
        ui->det3->setText("0");

    }
    else
    {
        ui->m4_1->setText("");
        ui->m4_2->setText("");
        ui->m4_3->setText("");
        ui->m4_4->setText("");
        ui->m4_5->setText("");
        ui->m4_6->setText("");
        ui->m4_7->setText("");
        ui->m4_8->setText("");
        ui->m4_9->setText("");
        ui->m4_10->setText("");
        ui->m4_11->setText("");
        ui->m4_12->setText("");
        ui->m4_13->setText("");
        ui->m4_14->setText("");
        ui->m4_15->setText("");
        ui->m4_16->setText("");
        ui->det4->setText("0");

    }
}

void Calculator::addMatrix()
{
    int TabIndex = ui->tabWidget->currentIndex();

    if(TabIndex==0){
        ptr = &Matrix_2x2;
    }
    else if(TabIndex==1){
        ptr = &Matrix_3x3;
    }
    else{
        ptr = &Matrix_4x4;
    }

    Calculator::getMatrixVal(ptr,TabIndex);

    Calculator::ClearMatrix();

    matrixMultiplyActive=false;
    ui->ApplyWidget->setVisible(true);
}

void Calculator::multMatrix()
{
    int TabIndex = ui->tabWidget->currentIndex();

    if(TabIndex==0){
        ptr = &Matrix_2x2;
    }
    else if(TabIndex==1){
        ptr = &Matrix_3x3;
    }
    else{
        ptr = &Matrix_4x4;
    }

    Calculator::getMatrixVal(ptr,TabIndex);

    Calculator::ClearMatrix();

    matrixMultiplyActive=true;
    ui->ApplyWidget->setVisible(true);
}



void Calculator::addmultMatrix()
{
    cMatrix *ptr_2;
    cMatrix *ptr_3;
    m2x2 M2;
    m3x3 M3;
    m4x4 M4;

    int TabIndex = ui->tabWidget->currentIndex();

    if(TabIndex==0){
        ptr_2 = &M2;
    }
    else if(TabIndex==1){
        ptr_2 = &M3;
    }
    else{
        ptr_2 = &M4;
    }

    Calculator::getMatrixVal(ptr_2,TabIndex);



    if(TabIndex==0){

        m2x2 wyn2;

        if(matrixMultiplyActive)    wyn2=Matrix_2x2*M2;
        else    wyn2=Matrix_2x2+M2;

        ptr_3 = &wyn2;

        ui->m2_1->setText(QString::number(ptr_3->ReverseValue(0)));
        ui->m2_2->setText(QString::number(ptr_3->ReverseValue(1)));
        ui->m2_3->setText(QString::number(ptr_3->ReverseValue(2)));
        ui->m2_4->setText(QString::number(ptr_3->ReverseValue(3)));
    }
    else if(TabIndex==1){

        m3x3 wyn3;

        if(matrixMultiplyActive)    wyn3=Matrix_3x3*M3;
        else    wyn3=Matrix_3x3+M3;

        ptr_3=&wyn3;

        ui->m3_1->setText(QString::number(ptr_3->ReverseValue(0)));
        ui->m3_2->setText(QString::number(ptr_3->ReverseValue(1)));
        ui->m3_3->setText(QString::number(ptr_3->ReverseValue(2)));
        ui->m3_4->setText(QString::number(ptr_3->ReverseValue(3)));
        ui->m3_5->setText(QString::number(ptr_3->ReverseValue(4)));
        ui->m3_6->setText(QString::number(ptr_3->ReverseValue(5)));
        ui->m3_7->setText(QString::number(ptr_3->ReverseValue(6)));
        ui->m3_8->setText(QString::number(ptr_3->ReverseValue(7)));
        ui->m3_9->setText(QString::number(ptr_3->ReverseValue(8)));
    }
    else{

        m4x4 wyn4;

        if(matrixMultiplyActive)    wyn4=Matrix_4x4*M4;
        else    wyn4=Matrix_4x4+M4;

        ptr_3=&wyn4;

        ui->m4_1->setText(QString::number(ptr_3->ReverseValue(0)));
        ui->m4_2->setText(QString::number(ptr_3->ReverseValue(1)));
        ui->m4_3->setText(QString::number(ptr_3->ReverseValue(2)));
        ui->m4_4->setText(QString::number(ptr_3->ReverseValue(3)));
        ui->m4_5->setText(QString::number(ptr_3->ReverseValue(4)));
        ui->m4_6->setText(QString::number(ptr_3->ReverseValue(5)));
        ui->m4_7->setText(QString::number(ptr_3->ReverseValue(6)));
        ui->m4_8->setText(QString::number(ptr_3->ReverseValue(7)));
        ui->m4_9->setText(QString::number(ptr_3->ReverseValue(8)));
        ui->m4_10->setText(QString::number(ptr_3->ReverseValue(9)));
        ui->m4_11->setText(QString::number(ptr_3->ReverseValue(10)));
        ui->m4_12->setText(QString::number(ptr_3->ReverseValue(11)));
        ui->m4_13->setText(QString::number(ptr_3->ReverseValue(12)));
        ui->m4_14->setText(QString::number(ptr_3->ReverseValue(13)));
        ui->m4_15->setText(QString::number(ptr_3->ReverseValue(14)));
        ui->m4_16->setText(QString::number(ptr_3->ReverseValue(15)));
    }

    ui->ApplyWidget->setVisible(false);

}
