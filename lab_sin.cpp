#include <iostream>
#include <cmath>

using namespace std;

double sinus(double x, double eps) {
    int count = 0;
    double sum = 0;
    double el = x;
    while (fabs(el) >= eps) {
        sum += el;
        el = el * (-1.0*x*x / ((2.0*count + 2) * (2.0*count + 3)));
        count += 1;
    } return sum;
}

int main() {
    double x, eps;
    cin >> x >> eps;
    double teylor = sinus(x, eps);
    double sinx = sin(x);
    cout << "Значение sin(" << x << ") через ряд Тейлора с точностью " << eps << ": "
    << teylor << endl;
    cout << "Значение sin(" << x << ") в модуле math: "<< sinx << endl;
    cout << "Погрешность: " << fabs(teylor - sinx) << endl;
}
