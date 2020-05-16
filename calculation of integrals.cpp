#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float a = 1, b = 100, step = 2;
float f(float x)
{
    return pow(log(5 * x), 2);
}
void rectangle() 
{
    float result = 0.0, h = (b - a) / step;
    for (float x = a; x < b; x += h)
    {
        result += (h * f(x));
    }
    cout << setw(13) << result << " |";
}
void trapezoid()
{
    float result = 0.0, h = (b - a) / step;
    for (float x = a; x < b; x += h)
    {
        result += (h * (f(x) + f(x + h)) / 2);
    }
    cout << setw(13) << result << " |";
}
void simpson()
{
    float result = 0.0, h = (b - a) / step;
    int i = 2;
    for (float x = a + h; x < b; x += h, i++)
    {
        if (i % 2 == 0) result += (2 * f(x));
        else result += f(x);
    }
    result = (result * 2 + f(a) + f(b)) * h / 3;
    cout << setw(13) << result << " |";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << setw(8) << " Шаг |" << setw(15) << "М. прямоуг. |" <<
        setw(15) << "М. трапец. |" << setw(15) << "М. Симпсона |"<<
         "\n------------------------------------------------------\n";
    for (step = 2; step < 1025; step *= 2) {
        cout << " " << setw(5) << step << " |";
        rectangle();
        trapezoid();
        simpson();
        cout << endl;
    }
}
