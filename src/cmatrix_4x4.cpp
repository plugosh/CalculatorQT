#include "cmatrix.h"
#include "calculator.h"
#include "ui_calculator.h"


m4x4::m4x4()
{
    for (int i=0;i<Size;++i) {
        Tab[i] = 0;
    }
}

m4x4::~m4x4()
{
}

void m4x4::setValues(std::string Array[])
{
    for (int i=0;i<16;++i)
    {
        Tab[i] = ::atof(Array[i].c_str());
    }
}

double m4x4::getDeterminant()
{
    double det1,det2,det3,det4;
    double d1,d2;

    d1=(Tab[5]*Tab[10]*Tab[15])+(Tab[9]*Tab[14]*Tab[7])+(Tab[13]*Tab[6]*Tab[11]);
    d2=(Tab[7]*Tab[10]*Tab[13])+(Tab[11]*Tab[14]*Tab[5])+(Tab[15]*Tab[6]*Tab[9]);

    det1 = d1 - d2;

    d1=(Tab[1]*Tab[10]*Tab[15])+(Tab[9]*Tab[14]*Tab[3])+(Tab[13]*Tab[2]*Tab[11]);
    d2=(Tab[3]*Tab[10]*Tab[13])+(Tab[11]*Tab[14]*Tab[1])+(Tab[15]*Tab[2]*Tab[9]);

    det2  = d1 - d2;

    d1=(Tab[1]*Tab[6]*Tab[15])+(Tab[5]*Tab[14]*Tab[3])+(Tab[13]*Tab[2]*Tab[7]);
    d2=(Tab[3]*Tab[6]*Tab[13])+(Tab[7]*Tab[14]*Tab[1])+(Tab[15]*Tab[2]*Tab[5]);

    det3  = d1 - d2;

    d1=(Tab[1]*Tab[6]*Tab[11])+(Tab[5]*Tab[10]*Tab[3])+(Tab[9]*Tab[2]*Tab[7]);
    d2=(Tab[3]*Tab[6]*Tab[9])+(Tab[7]*Tab[10]*Tab[1])+(Tab[11]*Tab[2]*Tab[5]);

    det4  = d1 - d2;

    Determinant = det1 * Tab[0] - det2 * Tab[4] + det3 * Tab[8] - det4 * Tab[12];

    return Determinant;
}

void m4x4::fReverse()
{
    double revDet = 1/Determinant;

    double *BuforTab = new double[Size];
    for (int i=0;i<Size;++i)
    {
        BuforTab[i]=Tab[i];
    }

    double D1,D2;

    D1 = BuforTab[5]*BuforTab[10]*BuforTab[15] + BuforTab[9]*BuforTab[14]*BuforTab[7] + BuforTab[13]*BuforTab[6]*BuforTab[11];
    D2 = BuforTab[7]*BuforTab[10]*BuforTab[13] + BuforTab[11]*BuforTab[14]*BuforTab[5] + BuforTab[15]*BuforTab[6]*BuforTab[9];

    Tab[0] = D1-D2;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    D1 = BuforTab[4]*BuforTab[10]*BuforTab[15] + BuforTab[8]*BuforTab[14]*BuforTab[7] + BuforTab[12]*BuforTab[6]*BuforTab[11];
    D2 = BuforTab[7]*BuforTab[10]*BuforTab[12] + BuforTab[11]*BuforTab[14]*BuforTab[4] + BuforTab[15]*BuforTab[6]*BuforTab[8];

    Tab[1] = -1*(D1-D2);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    D1 = BuforTab[4]*BuforTab[9]*BuforTab[15] + BuforTab[8]*BuforTab[13]*BuforTab[7] + BuforTab[12]*BuforTab[5]*BuforTab[11];
    D2 = BuforTab[7]*BuforTab[9]*BuforTab[12] + BuforTab[11]*BuforTab[13]*BuforTab[4] + BuforTab[15]*BuforTab[5]*BuforTab[8];

    Tab[2] = D1-D2;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    D1 = BuforTab[4]*BuforTab[9]*BuforTab[14] + BuforTab[8]*BuforTab[13]*BuforTab[6] + BuforTab[12]*BuforTab[5]*BuforTab[10];
    D2 = BuforTab[6]*BuforTab[9]*BuforTab[12] + BuforTab[10]*BuforTab[13]*BuforTab[4] + BuforTab[14]*BuforTab[5]*BuforTab[8];//6/9/12

    Tab[3] = -1*(D1-D2);

    D1 = BuforTab[1]*BuforTab[10]*BuforTab[15] + BuforTab[9]*BuforTab[14]*BuforTab[3] + BuforTab[13]*BuforTab[2]*BuforTab[11];
    D2 = BuforTab[3]*BuforTab[10]*BuforTab[13] + BuforTab[11]*BuforTab[14]*BuforTab[1] + BuforTab[15]*BuforTab[2]*BuforTab[9];

    Tab[4] = -1*(D1-D2);

    D1 = BuforTab[0]*BuforTab[10]*BuforTab[15] + BuforTab[8]*BuforTab[14]*BuforTab[3] + BuforTab[12]*BuforTab[2]*BuforTab[11];
    D2 = BuforTab[3]*BuforTab[10]*BuforTab[12] + BuforTab[11]*BuforTab[14]*BuforTab[0] + BuforTab[15]*BuforTab[2]*BuforTab[8];

    Tab[5] = D1-D2;/////

    D1 = BuforTab[0]*BuforTab[9]*BuforTab[15] + BuforTab[8]*BuforTab[13]*BuforTab[3] + BuforTab[12]*BuforTab[1]*BuforTab[11];
    D2 = BuforTab[3]*BuforTab[9]*BuforTab[12] + BuforTab[11]*BuforTab[13]*BuforTab[0] + BuforTab[15]*BuforTab[1]*BuforTab[8];

    Tab[6] = -1*(D1-D2);

    D1 = BuforTab[0]*BuforTab[9]*BuforTab[14] + BuforTab[8]*BuforTab[13]*BuforTab[2] + BuforTab[12]*BuforTab[1]*BuforTab[10];
    D2 = BuforTab[2]*BuforTab[9]*BuforTab[12] + BuforTab[10]*BuforTab[13]*BuforTab[0] + BuforTab[14]*BuforTab[1]*BuforTab[8];

    Tab[7] = D1-D2;//////////////

    D1 = BuforTab[1]*BuforTab[6]*BuforTab[15] + BuforTab[5]*BuforTab[14]*BuforTab[3] + BuforTab[13]*BuforTab[2]*BuforTab[7];
    D2 = BuforTab[3]*BuforTab[6]*BuforTab[13] + BuforTab[7]*BuforTab[14]*BuforTab[1] + BuforTab[15]*BuforTab[2]*BuforTab[5];

    Tab[8] = D1-D2;//////////

    D1 = BuforTab[0]*BuforTab[6]*BuforTab[15] + BuforTab[4]*BuforTab[14]*BuforTab[3] + BuforTab[12]*BuforTab[2]*BuforTab[7];
    D2 = BuforTab[3]*BuforTab[6]*BuforTab[12] + BuforTab[7]*BuforTab[14]*BuforTab[0] + BuforTab[15]*BuforTab[2]*BuforTab[4];

    Tab[9] = -1*(D1-D2);

    D1 = BuforTab[0]*BuforTab[5]*BuforTab[15] + BuforTab[4]*BuforTab[13]*BuforTab[3] + BuforTab[12]*BuforTab[1]*BuforTab[7];
    D2 = BuforTab[3]*BuforTab[5]*BuforTab[12] + BuforTab[7]*BuforTab[13]*BuforTab[0] + BuforTab[15]*BuforTab[1]*BuforTab[4];

    Tab[10] = D1-D2;//////////

    D1 = BuforTab[0]*BuforTab[5]*BuforTab[14] + BuforTab[4]*BuforTab[13]*BuforTab[2] + BuforTab[12]*BuforTab[1]*BuforTab[6];
    D2 = BuforTab[2]*BuforTab[5]*BuforTab[12] + BuforTab[6]*BuforTab[13]*BuforTab[0] + BuforTab[14]*BuforTab[1]*BuforTab[4];

    Tab[11] = -1*(D1-D2);

    D1 = BuforTab[1]*BuforTab[6]*BuforTab[11] + BuforTab[5]*BuforTab[10]*BuforTab[3] + BuforTab[9]*BuforTab[2]*BuforTab[7];
    D2 = BuforTab[3]*BuforTab[6]*BuforTab[9] + BuforTab[7]*BuforTab[10]*BuforTab[1] + BuforTab[11]*BuforTab[2]*BuforTab[5];

    Tab[12] = -1*(D1-D2);///

    D1 = BuforTab[0]*BuforTab[6]*BuforTab[11] + BuforTab[4]*BuforTab[10]*BuforTab[3] + BuforTab[8]*BuforTab[2]*BuforTab[7];
    D2 = BuforTab[3]*BuforTab[6]*BuforTab[8] + BuforTab[7]*BuforTab[10]*BuforTab[0] + BuforTab[11]*BuforTab[2]*BuforTab[4];

    Tab[13] = D1-D2;//////

    D1 = BuforTab[0]*BuforTab[5]*BuforTab[11] + BuforTab[4]*BuforTab[9]*BuforTab[3] + BuforTab[8]*BuforTab[1]*BuforTab[7];
    D2 = BuforTab[3]*BuforTab[5]*BuforTab[8] + BuforTab[7]*BuforTab[9]*BuforTab[0] + BuforTab[11]*BuforTab[1]*BuforTab[4];

    Tab[14] = -1*(D1-D2);

    D1 = BuforTab[0]*BuforTab[5]*BuforTab[10] + BuforTab[4]*BuforTab[9]*BuforTab[2] + BuforTab[8]*BuforTab[1]*BuforTab[6];
    D2 = BuforTab[2]*BuforTab[5]*BuforTab[8] + BuforTab[6]*BuforTab[9]*BuforTab[0] + BuforTab[10]*BuforTab[1]*BuforTab[4];

    Tab[15] = D1-D2;


    delete [] BuforTab;

    for (int i=0;i<Size;++i)
    {
        Tab[i]*=revDet;
    }
}

double m4x4::ReverseValue(int i)
{
    return Tab[i];
}

m4x4 m4x4::operator+(const m4x4 &right)
{
    m4x4 newValue;

    for (int i=0;i<Size;++i) {
        newValue.Tab[i]=this->Tab[i]+right.Tab[i];
    }


    return newValue;
}

m4x4 m4x4::operator*(const m4x4 &right)
{
    m4x4 newValue;

    newValue.Tab[0]=    this->Tab[0]*right.Tab[0]+this->Tab[1]*right.Tab[4]+this->Tab[2]*right.Tab[8]+this->Tab[3]*right.Tab[12];
    newValue.Tab[1]=    this->Tab[0]*right.Tab[1]+this->Tab[1]*right.Tab[5]+this->Tab[2]*right.Tab[9]+this->Tab[3]*right.Tab[13];
    newValue.Tab[2]=    this->Tab[0]*right.Tab[2]+this->Tab[1]*right.Tab[6]+this->Tab[2]*right.Tab[10]+this->Tab[3]*right.Tab[14];
    newValue.Tab[3]=    this->Tab[0]*right.Tab[3]+this->Tab[1]*right.Tab[7]+this->Tab[2]*right.Tab[11]+this->Tab[3]*right.Tab[15];
    newValue.Tab[4]=    this->Tab[4]*right.Tab[0]+this->Tab[5]*right.Tab[4]+this->Tab[6]*right.Tab[8]+this->Tab[7]*right.Tab[11];
    newValue.Tab[5]=    this->Tab[4]*right.Tab[1]+this->Tab[5]*right.Tab[5]+this->Tab[6]*right.Tab[9]+this->Tab[7]*right.Tab[12];
    newValue.Tab[6]=    this->Tab[4]*right.Tab[2]+this->Tab[5]*right.Tab[6]+this->Tab[6]*right.Tab[10]+this->Tab[7]*right.Tab[13];
    newValue.Tab[7]=    this->Tab[4]*right.Tab[3]+this->Tab[5]*right.Tab[7]+this->Tab[6]*right.Tab[11]+this->Tab[7]*right.Tab[14];
    newValue.Tab[8]=    this->Tab[8]*right.Tab[0]+this->Tab[9]*right.Tab[4]+this->Tab[10]*right.Tab[8]+this->Tab[11]*right.Tab[12];
    newValue.Tab[9]=    this->Tab[8]*right.Tab[1]+this->Tab[9]*right.Tab[5]+this->Tab[10]*right.Tab[9]+this->Tab[11]*right.Tab[13];
    newValue.Tab[10]=   this->Tab[8]*right.Tab[2]+this->Tab[9]*right.Tab[6]+this->Tab[10]*right.Tab[10]+this->Tab[11]*right.Tab[14];
    newValue.Tab[11]=   this->Tab[8]*right.Tab[3]+this->Tab[9]*right.Tab[7]+this->Tab[10]*right.Tab[11]+this->Tab[11]*right.Tab[15];
    newValue.Tab[12]=   this->Tab[12]*right.Tab[0]+this->Tab[13]*right.Tab[4]+this->Tab[14]*right.Tab[8]+this->Tab[15]*right.Tab[12];
    newValue.Tab[13]=   this->Tab[12]*right.Tab[1]+this->Tab[13]*right.Tab[5]+this->Tab[14]*right.Tab[9]+this->Tab[15]*right.Tab[13];
    newValue.Tab[14]=   this->Tab[12]*right.Tab[2]+this->Tab[13]*right.Tab[6]+this->Tab[14]*right.Tab[10]+this->Tab[15]*right.Tab[14];
    newValue.Tab[15]=   this->Tab[12]*right.Tab[3]+this->Tab[13]*right.Tab[7]+this->Tab[14]*right.Tab[11]+this->Tab[15]*right.Tab[15];


    return newValue;
}

m4x4& m4x4::operator=(const m4x4 matrix)
{
    for (int i=0;i<Size;++i) {
        this->Tab[i]=matrix.Tab[i];
    }
    return *this;
}
