#include "cmatrix.h"
#include "calculator.h"
#include "ui_calculator.h"
#include <vector>

m2x2::m2x2()
{
    for (int i=0;i<Size;++i) {
        Tab[i] = 0;
    }

}

m2x2::~m2x2()
{
}


void m2x2::setValues(std::string Array[])
{
    for (int i=0;i<4;++i)
    {
        Tab[i] = ::atof(Array[i].c_str());
    }    
}

double m2x2::getDeterminant()
{
    Determinant = (Tab[0]*Tab[3])-(Tab[1]*Tab[2]);

    return Determinant;
}

void m2x2::fReverse()
{
    double revDet = 1/Determinant;

    double *BuforTab = new double[Size];
    for (int i=0;i<Size;++i)
    {
        BuforTab[i]=Tab[i];
    }

    Tab[0] = BuforTab[3];
    Tab[1] = -1*BuforTab[2];
    Tab[2] = -1*BuforTab[1];
    Tab[3] = BuforTab[0];

    delete [] BuforTab;

    for (int i=0;i<Size;++i)
    {
        Tab[i]*=revDet;
    }
}

double m2x2::ReverseValue(int i)
{
    return Tab[i];
}

m2x2 m2x2::operator+(const m2x2 &right)
{
    m2x2 newValue;

    for (int i=0;i<Size;++i) {
        newValue.Tab[i]=this->Tab[i]+right.Tab[i];
    }

    return newValue;
}

m2x2 m2x2::operator*(const m2x2 &right)
{
    m2x2 newValue;

    newValue.Tab[0]=this->Tab[0]*right.Tab[0]+this->Tab[1]*right.Tab[2];
    newValue.Tab[1]=this->Tab[0]*right.Tab[1]+this->Tab[1]*right.Tab[3];
    newValue.Tab[2]=this->Tab[2]*right.Tab[0]+this->Tab[3]*right.Tab[2];
    newValue.Tab[3]=this->Tab[2]*right.Tab[1]+this->Tab[3]*right.Tab[3];

    return newValue;
}

m2x2& m2x2::operator=(const m2x2 matrix)
{
    for (int i=0;i<Size;++i) {
        this->Tab[i]=matrix.Tab[i];
    }

    return *this;

}
