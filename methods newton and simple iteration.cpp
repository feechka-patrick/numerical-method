#include <iostream>
#include <cmath>

using namespace std;
float f1(float x, float y) {
    return sin(x - 1) - 1.3 - y;
}
float f2(float x, float y) {
    return 0.8 - sin(y + 1) - x;
}
float dx(float x, float y) {
    float d = -cos(x - 1) * cos(y + 1) - 1;
    float d1 = f1(x, y) * cos(y + 1) - f2(x, y);
    return d1 / d;
}
float dy(float x, float y) {
    float d = -cos(x - 1) * cos(y + 1) - 1;
    float d2 = -f2(x, y) * cos(x - 1) - f1(x, y);
    return d2 / d;
}
void S(float e) {
    cout << "\nМетод простых итераций\n";
    float x0 = 1, y0 = -1;
    float x = f2(x0,y0) + x0;
    float y = f1(x0, y0) + y0;
    int count = 1;
    while (abs(x0 - x) > e && abs(y0 - y) > e) {
        x0 = x; y0 = y;
        x = f2(x0, y0) + x0; y = f1(x0, y0) + y0;
        count++;
    }
    cout << "Корни: x = " << x << " y = " << y << endl;
    cout << "Количество итераций: " << count << endl;
}
void N(float e) {
    cout << "\nМетод Ньютона\n";
    int count = 1;
    float x0 = 1, y0 = -1;
    float x = x0 + dx(x0,y0);
    float y = y0 + dy(x0,y0);
    while (abs(dx(x0,y0)) > e && abs(dy(x0, y0)) > e) {
        x0 = x; y0 = y;
        x = x0 + dx(x0, y0);
        y = y0 + dy(x0, y0);
        count++;
    }
    cout << "Корни: x = " << x << " y = " << y << endl;
    cout << "Количество итераций: " << count << endl;
}
int main()
{
    // y = sin(x-1) - 1.3
    // x = 0.8 - sin(y+1)
    setlocale(LC_ALL, "Russian");
    float e = 0.0001;
    cout << "Введите точность: " << e;
    N(e);
    S(e);
    }

