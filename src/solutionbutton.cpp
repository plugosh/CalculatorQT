#include "calculator.h"
#include "ui_calculator.h"
#include <QtMath>
#include <string>

void Calculator::SetBracketNumber(QString &displayValue)
{
    displayValue=ui->Display->text();
    std::string DisVal=displayValue.toStdString();

    int LB=0;
    int RB=0;

    for (int i=0;i<DisVal.size();++i)
    {
        if(DisVal[i]=='(')
        {
            LB++;
        }
        if(DisVal[i]==')')
        {
            RB++;
        }
    }

    while(LB!=RB)
    {
        DisVal+=")";
    }
    displayValue = QString::fromStdString(DisVal);

    ui->Display->setText(displayValue);

    brackets=LB;
}

void Calculator::CalculatingProcess_Brackets(std::string &equation,const bool Minus,double &FinalSolution,std::string &DisVal,
                        const int leftBracketPos,const int rightBracketPos,std::string &FSol)
{
    int eqSize = equation.size();

    if(DisVal[leftBracketPos-1]=='!')
    {

        equation.erase(equation.size()-1,1);

        if(leftBracketPos==0)
        {
            DisVal.insert(0,"0+");
        }

        int DV = ::atof(equation.c_str());
        long long Fact = 1;

        for (int i=1;i<=DV;++i)
        {
            Fact*=i;
        }

        std::string nv = std::to_string(Fact);

        if(leftBracketPos==0)
        {
            DisVal.erase(2,rightBracketPos+2);
            DisVal.insert(2,nv);
        }
        else
        {

            DisVal.erase(leftBracketPos,rightBracketPos-2);
            DisVal.insert(leftBracketPos,nv);
        }
    }

    else
    {

        if(Minus)
        {
            equation.erase(0,1);
            eqSize--;
        }


        int counter=1;

        for(int j=0;j<eqSize;++j)
        {

            if(equation[j]=='+'||equation[j]=='-'||equation[j]=='/'||equation[j]=='*')
            {
                counter++;
            }
        }

        if(counter>1)
            {
                int *signSlot = new int[counter-1];
                std::string *Num = new std::string[counter];

                int m=0;


            for(int j=0;j<eqSize;++j)
            {
                if(equation[j]=='+'||equation[j]=='-'||equation[j]=='/'||equation[j]=='*')
                {
                    signSlot[m]=j;
                   m++;
                }
            }

                Num[0].insert(0,equation,0,signSlot[0]);


                for(int j=1;j<counter;++j)
                {
                    Num[j].insert(0,equation,signSlot[j-1]+1,signSlot[j]-signSlot[j-1]-1);
                }

                for(int j=0;j<counter-1;++j)
                {
                  if(equation[signSlot[j]]=='-')
                   {
                        Num[j+1]="-"+Num[j+1];
                    }
                }


                double *Tab = new double[counter];

                double p=M_PI;
                double e=M_E;

                for (int j=0;j<counter;++j)
                {
                    if(Num[j]=="e")
                    {
                        Tab[j] = e;
                    }
                    if(Num[j]=="p")
                    {
                        Tab[j] = p;
                    }
                    else
                    {
                        Tab[j] = ::atof(Num[j].c_str());
                    }

                    }

                if(Minus)
                {
                    Tab[0]=-Tab[0];
                }

                int counter_2=0;

                double *mdSolutions = new double [counter];


                if(equation[signSlot[0]]=='*'||equation[signSlot[0]]=='/')
                {
                    mdSolutions[0]=Tab[0];
                    counter_2++;
                }


                for (int j=1;j<counter-1;++j)
                {
                    if(equation[signSlot[j]]=='*'||equation[signSlot[j]]=='/')
                    {
                        if(equation[signSlot[j-1]]=='+'||equation[signSlot[j-1]]=='-')
                        {
                        mdSolutions[counter_2]=Tab[j];
                        counter_2++;
                        }
                    }
               }

                counter_2=0;

                for (int j=0;j<counter-1;++j)
                {
                    if(equation[signSlot[j]]=='*'||equation[signSlot[j]]=='/')
                    {
                        while(equation[signSlot[j]]=='*'||equation[signSlot[j]]=='/')
                        {
                            if(equation[signSlot[j]]=='*')
                            {
                            mdSolutions[counter_2]*=Tab[j+1];
                            }

                            if(equation[signSlot[j]]=='/')
                            {
                            mdSolutions[counter_2]/=Tab[j+1];
                            }
                            if(j<counter-2)
                            {
                                j++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        counter_2++;
                    }
              }

                bool *noMD = new bool[counter];
                for (int j=0;j<counter;++j)
                {
                    noMD[j]=false;
                }

                if(equation[signSlot[0]]!='*'&&equation[signSlot[0]]!='/')
                {
                    noMD[0]=true;
                }

                if(equation[signSlot[counter-2]]!='*'&&equation[signSlot[counter-2]]!='/')
                {
                    noMD[counter-1]=true;
                }

                for(int j=0;j<counter-2;++j)
                {
                    if(equation[signSlot[j]]!='*'&&equation[signSlot[j]]!='/')
                    {
                        if(equation[signSlot[j+1]]!='*'&&equation[signSlot[j+1]]!='/')
                        {
                            noMD[j+1]=true;
                        }
                    }
                }


                double S1 = 0;
                double S2 = 0;

                for(int j=0;j<counter;++j)
                {
                    if(noMD[j])
                    {
                        S1+=Tab[j];
                    }
                }
                for(int j=0;j<counter_2;++j)
                {
                    S2+=mdSolutions[j];
                }

                FinalSolution = S1 + S2;

                delete [] mdSolutions;
                delete [] Tab;
                delete [] Num;
                delete [] signSlot;



            }
        else
        {
               if(equation=="e"){
                   FinalSolution = M_E;
               }
               else if(equation=="p"){
                   FinalSolution = M_PI;
               }
               else {
                   FinalSolution = ::atof(equation.c_str());
               }


        }

    }
        FSol = std::to_string(FinalSolution);

        DisVal.erase(leftBracketPos+1,rightBracketPos-leftBracketPos-1);
        DisVal.insert(leftBracketPos+1,FSol,0,FSol.size()+1);

}

void Calculator::CalculatingProcess_NoBrackets(std::string &equation,const bool Minus,double &FinalSolution,std::string &DisVal,std::string &FSol)
{
    int eqSize = equation.size();


        if(Minus)
        {
            equation.erase(0,1);
            eqSize--;
        }


        int counter=1;

        for(int j=0;j<eqSize;++j)
        {

            if(equation[j]=='+'||equation[j]=='-'||equation[j]=='/'||equation[j]=='*')
            {
                counter++;
            }
        }

        if(counter>1)
            {



                int *signSlot = new int[counter-1];
                std::string *Num = new std::string[counter];

                int m=0;


            for(int j=0;j<eqSize;++j)
            {
                if(equation[j]=='+'||equation[j]=='-'||equation[j]=='/'||equation[j]=='*')
                {
                    signSlot[m]=j;
                   m++;
                }
            }

                Num[0].insert(0,equation,0,signSlot[0]);


                for(int j=1;j<counter;++j)
                {
                    Num[j].insert(0,equation,signSlot[j-1]+1,signSlot[j]-signSlot[j-1]-1);
                }

                for(int j=0;j<counter-1;++j)
                {
                  if(equation[signSlot[j]]=='-')
                   {
                        Num[j+1]="-"+Num[j+1];
                    }
                }


                double *Tab = new double[counter];

                double p=M_PI;
                double e=M_E;

                for (int j=0;j<counter;++j)
                {
                    if(Num[j]=="e")
                    {
                        Tab[j] = e;
                    }
                    if(Num[j]=="p")
                    {
                        Tab[j] = p;
                    }
                    else
                    {
                        Tab[j] = ::atof(Num[j].c_str());
                    }

                    }

                if(Minus)
                {
                    Tab[0]=-Tab[0];
                }

                int counter_2=0;

                double *mdSolutions = new double [counter];


                if(equation[signSlot[0]]=='*'||equation[signSlot[0]]=='/')
                {
                    mdSolutions[0]=Tab[0];
                    counter_2++;
                }


                for (int j=1;j<counter-1;++j)
                {
                    if(equation[signSlot[j]]=='*'||equation[signSlot[j]]=='/')
                    {
                        if(equation[signSlot[j-1]]=='+'||equation[signSlot[j-1]]=='-')
                        {
                        mdSolutions[counter_2]=Tab[j];
                        counter_2++;
                        }
                    }
               }

                counter_2=0;

                for (int j=0;j<counter-1;++j)
                {
                    if(equation[signSlot[j]]=='*'||equation[signSlot[j]]=='/')
                    {
                        while(equation[signSlot[j]]=='*'||equation[signSlot[j]]=='/')
                        {
                            if(equation[signSlot[j]]=='*')
                            {
                            mdSolutions[counter_2]*=Tab[j+1];
                            }

                            if(equation[signSlot[j]]=='/')
                            {
                            mdSolutions[counter_2]/=Tab[j+1];
                            }
                            if(j<counter-2)
                            {
                                j++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        counter_2++;
                    }
              }

                bool *noMD = new bool[counter];
                for (int j=0;j<counter;++j)
                {
                    noMD[j]=false;
                }

                if(equation[signSlot[0]]!='*'&&equation[signSlot[0]]!='/')
                {
                    noMD[0]=true;
                }

                if(equation[signSlot[counter-2]]!='*'&&equation[signSlot[counter-2]]!='/')
                {
                    noMD[counter-1]=true;
                }

                for(int j=0;j<counter-2;++j)
                {
                    if(equation[signSlot[j]]!='*'&&equation[signSlot[j]]!='/')
                    {
                        if(equation[signSlot[j+1]]!='*'&&equation[signSlot[j+1]]!='/')
                        {
                            noMD[j+1]=true;
                        }
                    }
                }


                double S1 = 0;
                double S2 = 0;

                for(int j=0;j<counter;++j)
                {
                    if(noMD[j])
                    {
                        S1+=Tab[j];
                    }
                }
                for(int j=0;j<counter_2;++j)
                {
                    S2+=mdSolutions[j];
                }

                FinalSolution = S1 + S2;

                delete [] mdSolutions;
                delete [] Tab;
                delete [] Num;
                delete [] signSlot;




            }
        else
        {
               if(equation=="e"){
                   FinalSolution = M_E;
               }
               else if(equation=="p"){
                   FinalSolution = M_PI;
               }
               else {
                   FinalSolution = ::atof(equation.c_str());
               }


        }

        QString FinalSol = QString::number(FinalSolution);
        FSol = FinalSol.toStdString();

        DisVal = FSol;

}

void Calculator::PowerFunctions(std::string &DisVal,const double FinalSolution,const int leftBracketPos,const int rightBracketPos)
{
    double NewValue;
    int Sign=-1;

    for (int i=leftBracketPos-1;i>=0;--i)
    {
        //13+12^(122)
        if(DisVal[i]=='+'||DisVal[i]=='-'||DisVal[i]=='/'||DisVal[i]=='*'||DisVal[i]=='(')
        {
            Sign = i;
            break;
        }
    }


    if(DisVal[leftBracketPos-2]=='e')
    {
        Sign = leftBracketPos-3;
        NewValue = pow(M_E,FinalSolution);
    }
    else if(DisVal[leftBracketPos-2]=='p')
    {
        Sign = leftBracketPos-3;
        NewValue = pow(M_PI,FinalSolution);
    }
    else if(DisVal[leftBracketPos-2]>47&&DisVal[leftBracketPos-2]<58)
    {
        //3+(2+(10^(5)))
        //012345678901
        std::string newNumber;

        newNumber.insert(0,DisVal,Sign+1,leftBracketPos-Sign-2);

        double x = ::atof(newNumber.c_str());

        NewValue = pow(x,FinalSolution);
    }

    std::string DV = std::to_string(NewValue);

    if(Sign<0)
    {
        DisVal = DV;
    }
    else if(DisVal[Sign]=='(')
    {
        //2+(2^(5))
        //012345678
        DisVal.erase(Sign+1,rightBracketPos-Sign);
        DisVal.insert(Sign+1,DV);
    }
    else
    {
       DisVal.erase(Sign+1,rightBracketPos-Sign);
       DisVal.insert(Sign+1,DV);
    }

}

std::string Calculator::SinAndTan(std::string &DisVal,double FinalSolution,const int leftBracketPos,const int rightBracketPos)
{
    bool arcus = false;
    double newValue=-2;

    if(!isRadius)
    {
        FinalSolution = FinalSolution * 2 * M_PI / 360;
    }


    if(DisVal[leftBracketPos-3]=='s')
    {
        newValue = sin(FinalSolution);

        if(leftBracketPos-4>0)
        {
            if(DisVal[leftBracketPos-4]=='c')
            {
                newValue = asin(FinalSolution);
                arcus = true;
            }
        }
    }
    else
    {
        if(leftBracketPos-4!=-1)
        {
         newValue = tan(FinalSolution);
            if(DisVal[leftBracketPos-4]=='c')
            {
                newValue = atan(FinalSolution);
                arcus = true;
            }
        }
    }

    std::string DV = std::to_string(newValue);

    if(arcus)
    {
        DisVal.erase(leftBracketPos-6,rightBracketPos-leftBracketPos+7);
        DisVal.insert(leftBracketPos-6,DV);
    }
    else
    {
        DisVal.erase(leftBracketPos-3,rightBracketPos-leftBracketPos+4);
        DisVal.insert(leftBracketPos-3,DV);

    }

    //displayValue = QString::fromStdString(DisVal);
    return DisVal;
}

std::string Calculator::CosAndCtg(std::string &DisVal,double FinalSolution,const int leftBracketPos,const int rightBracketPos)
{
    bool arcus = false;
    double newValue=-2;

    if(!isRadius)
    {
        FinalSolution = FinalSolution * 2 * M_PI / 360;
    }

    if(DisVal[leftBracketPos-2]=='o')
    {
        newValue = cos(FinalSolution);

        if(leftBracketPos-4>0)
        {
            if(DisVal[leftBracketPos-4]=='c')
            {
                newValue = acos(FinalSolution);
                arcus = true;
            }
        }
    }
    else
    {
        if(leftBracketPos-4!=-1)
        {
         newValue = tan(1/FinalSolution);
            if(DisVal[leftBracketPos-4]=='c')
            {
                newValue = atan(1/FinalSolution);
                arcus = true;
            }
        }
    }

    std::string DV = std::to_string(newValue);

    if(arcus)
    {
        DisVal.erase(leftBracketPos-6,rightBracketPos-leftBracketPos+7);
        DisVal.insert(leftBracketPos-6,DV);
    }
    else
    {
        DisVal.erase(leftBracketPos-3,rightBracketPos-leftBracketPos+4);
        DisVal.insert(leftBracketPos-3,DV);

    }

    //displayValue = QString::fromStdString(DisVal);
    return DisVal;
}

void Calculator::SOLUTION()
{

    QString displayValue = ui->Display->text();

    Calculator::SetBracketNumber(displayValue);


    std::string DisVal = displayValue.toStdString();

    if(DisVal[0]=='(')  DisVal = "0+"+DisVal;

    int Counting = 0;
    std::string FSol;


    for (int w=0;w<=brackets;++w)
    {
        if(Counting!=brackets)
        {
            //2+(2*(1+3))-(2-3)

            int leftBracketPos;
            int rightBracketPos;
            int ValSize = DisVal.size();
            /*for(int i=0;i<ValSize;++i)
            {
                if(DisVal[i]=='(')
                    {
                        leftBracketPos=i;
                    }
            }
            for(int i=leftBracketPos+1;i<ValSize;++i)
            {
                if(DisVal[i]==')')
                {
                    rightBracketPos=i;
                    break;
                }
            }*/

            for(int i=ValSize-1;i>=0;--i)
            {
                if(DisVal[i]==')')
                    {
                        rightBracketPos=i;
                    }
            }
            for(int i=rightBracketPos-1;i>=0;--i)
            {
                if(DisVal[i]=='(')
                {
                    leftBracketPos=i;
                    break;
                }
            }


            std::string equation;
            equation.insert(0,DisVal,leftBracketPos+1,rightBracketPos-leftBracketPos-1);
            int eqSize=equation.size();
            bool Minus;
            double FinalSolution=1;


            if(equation[0]=='-')    Minus = true;
            else                    Minus = false;

            /*if(DisVal[rightBracketPos-1]=='!')
            {
                equation.erase(equation.find('!'));

                int DV = ::atof(equation.c_str());
                long long Fact = 1;

                for (int i=1;i<=DV;++i)
                {
                    Fact*=i;
                }

                std::string nv = std::to_string(Fact);

                    DisVal.erase(leftBracketPos,rightBracketPos-leftBracketPos+1);
                    DisVal.insert(leftBracketPos,nv);
                    DisVal = equation;
                    //silnia nie dziala nie wiem dlaczego, poza glownym projektem dziala jak powinna
            }
            else
            {*/
                Calculator::CalculatingProcess_Brackets(equation,Minus,FinalSolution,DisVal,leftBracketPos,rightBracketPos,FSol);
            //}
                    if(DisVal[leftBracketPos-1]=='+'||DisVal[leftBracketPos-1]=='-'||DisVal[leftBracketPos-1]=='*'||DisVal[leftBracketPos-1]=='/')//normalne dzialania
                    {
                        //2+(3+(12))
                        //0123456789
                        DisVal.erase(leftBracketPos,rightBracketPos-leftBracketPos+1);
                        DisVal.insert(leftBracketPos,FSol);
                    }
                    else if(DisVal[leftBracketPos-1]=='V')//squareroot
                    {
                        //2*V(433)
                        //01234567
                        DisVal.erase(leftBracketPos-1,rightBracketPos-leftBracketPos+2);
                        double NV = sqrt(FinalSolution);
                        DisVal.insert(leftBracketPos-1,std::to_string(NV));
                    }
                    else if(DisVal[leftBracketPos-1]=='^')
                    {
                        Calculator::PowerFunctions(DisVal,FinalSolution,leftBracketPos,rightBracketPos);
                    }
                    else if(DisVal[leftBracketPos-1]=='n')
                    {
                        if(DisVal[leftBracketPos-2]=='i'||DisVal[leftBracketPos-2]=='a')//sin tan arcsin arctan
                        {
                            DisVal = Calculator::SinAndTan(DisVal,FinalSolution,leftBracketPos,rightBracketPos);
                        }
                        if(DisVal[leftBracketPos-2]=='L')
                        {
                            //2*Ln(2)
                            //0123456
                            DisVal.erase(leftBracketPos-2,rightBracketPos-leftBracketPos+3);
                            double NV = log(FinalSolution);
                            DisVal.insert(leftBracketPos-2,std::to_string(NV));
                        }
                    }//(1)
                    else if(DisVal[leftBracketPos-3]=='c')
                    {
                        DisVal = Calculator::CosAndCtg(DisVal,FinalSolution,leftBracketPos,rightBracketPos);
                    }
                    else if(DisVal[leftBracketPos-3]=='L')
                    {
                        DisVal.erase(leftBracketPos-3,rightBracketPos-leftBracketPos+4);
                        double NV = log10(FinalSolution);
                        DisVal.insert(leftBracketPos-3,std::to_string(NV));
                    }



                    displayValue = QString::fromStdString(DisVal);

                    Counting++;

        }

        else
        {
            std::string equation = DisVal;
            bool Minus;

            if(equation[0]=='-')    Minus = true;
            else                    Minus = false;

            double FinalSolution;

            Calculator::CalculatingProcess_NoBrackets(equation,Minus,FinalSolution,DisVal,FSol);


        }

    }
    displayValue = QString::fromStdString(DisVal);

    ui->Display->setText(displayValue);
    ui->AnswerLine->setText(displayValue);
}

//dodaj opcje ANS i zacznij macierze

