/*
//очень неудачная попытка сделать экспоненту... 

#include <iostream>
#include <cmath>
#include <iomanip>

double step(double x, int i)
{
    double res=1.;
    for (int k=1; k<=i; ++k)
    {
        res*=x;
    }
    return res;
}

double function(double x)
{
    double exp = 0;
    for (int i=0; i<100; ++i)
    {
        double fctrl = 1;
        for (int j=1; j<=i; ++j)
            fctrl*=j;
        exp+=step(x,i)/fctrl;
    }
    return exp;
}

int main()
{
    double x;
    std::cin >> x;
    std::cout << std::setprecision(16);
    std::cout << function(x) << std::endl;
    std::cout << std::exp(x) << std::endl;
}
*/



//косинус

#include <iostream>
#include <cmath>
#include <iomanip>
#include <numbers>


double fact(double x)                                             //факториал числа
{
    double res;
    if (x==0)
        res=1;
    else
    {
        res=1;
        for (int i=1; i<=x; ++i)
            res*=i;
    }
    return res;
}

double step(double x, int i)                                      //возведение в степень
{
    double res=1.;
    for (int k=1; k<=i; ++k)
    {
        res*=x;
    }
    return res;
}

//const double pi = std::numbers::pi;                           --- почему-то ругается на numbers
const double pi = 3.141592653589793238462;

double Cos1(double x)                                            //без использовния функций
{
    x = x - int(x / (2 * pi)) * 2 * pi;
    double cos = 1;
    double slug = 1;
    for (int i = 1; i < 100; ++i)
    {
        slug *= (-1 * x * x) / ((2 * i) * (2 * i - 1));
        cos += slug;
    }
    return cos;
}


double Cos2(double x)                                           //через вызов функций = долго
{
    x = x - int(x / (2 * pi)) * 2 * pi;
    double cos = 1;
    double slug = 1;
    for (int i = 1; i < 100; ++i)
    {
        cos += step(-1, i) * step(x, i * 2) / fact(2 * i);
    }
    return cos;
}

int main()
{
    double x;
    std::cin >> x;
    std::cout << std::setprecision(16);
    std::cout << "Cos1  " << Cos1(x) << std::endl;
    std::cout << "Cos2  " << Cos2(x) << std::endl;
    std::cout << "cos   " << std::cos(x) << std::endl;
}
