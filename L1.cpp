//косинус

#include <iostream>
#include <cmath>
#include <iomanip>
#include <numbers>

const double pi = std::numbers::pi;


double fact(double x)                                             //факториал числа
{
    double res;
    if (x == 0)
        res = 1;
    else
    {
        res = 1;
        for (int i = 1; i <= x; ++i)
            res *= i;
    }
    return res;
}


double step(double x, int i)                                      //возведение в степень
{
    double res = 1.;
    for (int k = 1; k <= i; ++k)
    {
        res *= x;
    }
    return res;
}


double Cos1(double x)                                            //без использовния функций
{
    x = x - int(x / (2 * pi)) * 2 * pi;
    double cos = 1;
    double slug = 1;
    for (int i = 1; i < 100; ++i)
    {
        if (cos + slug != slug)
        {
            slug *= (-1 * x * x) / ((2 * i) * (2 * i - 1));
            cos += slug;
        }
        else
            break;
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
