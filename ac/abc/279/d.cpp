#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b;
    cin >> a >> b;
    double x = cbrt((a*a)/(4*b*b));
    double x_1 = floor(x);
    double x_2 = ceil(x);
    double ans_1 = b*(x_1-1)+a/(sqrt(x_1));
    double ans_2 = b*(x_2-1)+a/(sqrt(x_2));
    cout << fixed << setprecision(10) << min(ans_1, ans_2) << '\n';
    return 0;
}
