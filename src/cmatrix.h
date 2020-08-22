#ifndef CMATRIX_H
#define CMATRIX_H

#include <QObject>

class cMatrix
{
    double Determinant;
    double Tab[1];
    int Size = 1;

public:
    cMatrix();
    virtual ~cMatrix();
    virtual void setValues(std::string Array[])=0;
    virtual double getDeterminant()=0;
    virtual void fReverse()=0;
    virtual double ReverseValue(int i=0)=0;
};

class m2x2 : public cMatrix
{
    double Determinant;
    double Tab[4];
    int Size = 4;
public:
    m2x2();
    virtual ~m2x2();
    virtual void setValues(std::string Array[]);
    virtual double getDeterminant();
    virtual void fReverse();
    virtual double ReverseValue(int i);
    m2x2 operator+(const m2x2 &right);
    m2x2 operator*(const m2x2 &right);
    m2x2& operator=(const m2x2 right);
};

class m3x3 : public cMatrix
{
    double Determinant;
    double Tab[9];
    int Size = 9;

public:
    m3x3();
    virtual ~m3x3();
    virtual void setValues(std::string Array[]);
    virtual double getDeterminant();
    virtual void fReverse();
    virtual double ReverseValue(int i);
    m3x3 operator+(const m3x3 &right);
    m3x3 operator*(const m3x3 &right);
    m3x3& operator=(const m3x3 matrix);
};

class m4x4 : public cMatrix
{
    double Determinant;
    double Tab[16];
    int Size = 16;

public:
    m4x4();
    virtual ~m4x4();
    virtual void setValues(std::string Array[]);
    virtual double getDeterminant();
    virtual void fReverse();
    virtual double ReverseValue(int i);
    m4x4 operator+(const m4x4 &right);
    m4x4 operator*(const m4x4 &right);
    m4x4& operator=(const m4x4 matrix);
};
#endif // CMATRIX_H
