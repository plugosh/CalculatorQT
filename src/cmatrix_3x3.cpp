#include "cmatrix.h"
#include "calculator.h"
#include "ui_calculator.h"


m3x3::m3x3()
{

    for (int i=0;i<Size;++i) {
        Tab[i] = 0;
    }
}

m3x3::~m3x3()
{
}

void m3x3::setValues(std::string Array[])
{
    for (int i=0;i<9;++i)
    {
        Tab[i] = ::atof(Array[i].c_str());
    }
}

double m3x3::getDeterminant()
{
    double D1,D2;
    D1 = (Tab[0]*Tab[4]*Tab[8])+(Tab[3]*Tab[7]*Tab[2])+(Tab[6]*Tab[1]*Tab[5]);
    D2 = (Tab[2]*Tab[4]*Tab[6])+(Tab[5]*Tab[7]*Tab[0])+(Tab[8]*Tab[1]*Tab[3]);
    Determinant = D1-D2;

    return Determinant;
}

void m3x3::fReverse()
{
    double revDet = 1/Determinant;

    double *BuforTab = new double[Size];
    for (int i=0;i<Size;++i)
    {
        BuforTab[i]=Tab[i];
    }

    Tab[0]=BuforTab[4]*BuforTab[8]-BuforTab[5]*BuforTab[7];
    Tab[1]=BuforTab[3]*BuforTab[8]-BuforTab[5]*BuforTab[6]; Tab[1]*=-1;
    Tab[2]=BuforTab[3]*BuforTab[7]-BuforTab[4]*BuforTab[6];
    Tab[3]=BuforTab[1]*BuforTab[8]-BuforTab[2]*BuforTab[7]; Tab[3]*=-1;
    Tab[4]=BuforTab[0]*BuforTab[8]-BuforTab[2]*BuforTab[6];
    Tab[5]=BuforTab[0]*BuforTab[7]-BuforTab[1]*BuforTab[6]; Tab[5]*=-1;
    Tab[6]=BuforTab[1]*BuforTab[5]-BuforTab[2]*BuforTab[4];
    Tab[7]=BuforTab[0]*BuforTab[5]-BuforTab[2]*BuforTab[3]; Tab[7]*=-1;
    Tab[8]=BuforTab[0]*BuforTab[4]-BuforTab[1]*BuforTab[3];

    delete [] BuforTab;

    for (int i=0;i<Size;++i)
    {
        Tab[i]*=revDet;
    }
}

double m3x3::ReverseValue(int i)
{
    return Tab[i];
}

m3x3 m3x3::operator+(const m3x3 &right)
{
    m3x3 newValue;

    for (int i=0;i<Size;++i) {
        newValue.Tab[i]=this->Tab[i]+right.Tab[i];
    }

    return newValue;
}

m3x3 m3x3::operator*(const m3x3 &right)
{
    m3x3 newValue;

    newValue.Tab[0]=this->Tab[0]*right.Tab[0]+this->Tab[1]*right.Tab[3]+this->Tab[2]*right.Tab[6];
    newValue.Tab[1]=this->Tab[0]*right.Tab[1]+this->Tab[1]*right.Tab[4]+this->Tab[2]*right.Tab[7];
    newValue.Tab[2]=this->Tab[0]*right.Tab[2]+this->Tab[1]*right.Tab[5]+this->Tab[2]*right.Tab[8];
    newValue.Tab[3]=this->Tab[3]*right.Tab[0]+this->Tab[4]*right.Tab[3]+this->Tab[5]*right.Tab[6];
    newValue.Tab[4]=this->Tab[3]*right.Tab[1]+this->Tab[4]*right.Tab[4]+this->Tab[5]*right.Tab[7];
    newValue.Tab[5]=this->Tab[3]*right.Tab[2]+this->Tab[4]*right.Tab[5]+this->Tab[5]*right.Tab[8];
    newValue.Tab[6]=this->Tab[6]*right.Tab[0]+this->Tab[7]*right.Tab[3]+this->Tab[8]*right.Tab[6];
    newValue.Tab[7]=this->Tab[6]*right.Tab[1]+this->Tab[7]*right.Tab[4]+this->Tab[8]*right.Tab[7];
    newValue.Tab[8]=this->Tab[6]*right.Tab[2]+this->Tab[7]*right.Tab[5]+this->Tab[8]*right.Tab[8];

    return newValue;
}

m3x3& m3x3::operator=(const m3x3 matrix)
{
    for (int i=0;i<Size;++i) {
        this->Tab[i]=matrix.Tab[i];
    }
    return *this;
}
