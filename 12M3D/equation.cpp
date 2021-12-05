#include <iostream>

using namespace std;

double a, b, c, d;

double func(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    cin >> a >> b >> c >> d;
    int count = 0;
    for (int i = -100; i < 100; i++) {
        if (count >= 3) {
            break;
        }
        double left = i;
        double right = i + 1;
        double x1 = func(left);
        double x2 = func(right);
        if (x1 == 0) {
            printf("%.2lf ", left);
            count++;
        }
        if (x1 * x2 < 0) {
            while (right - left >= 0.001) {
                double mid = (left + right) / 2;
                if (func(mid) * func(right) <= 0) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            count++;
            printf("%.2lf ", left);
        }
    }
}