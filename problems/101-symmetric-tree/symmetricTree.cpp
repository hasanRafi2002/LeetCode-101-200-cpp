#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a1, b1, c1;
    double a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    // Convert equations to: a*x + b*y = -c
    // So c becomes negative of what was input
    c1 = -c1;
    c2 = -c2;

    // Calculate determinants
    double D  = a1 * b2 - a2 * b1;
    double Dx = c1 * b2 - c2 * b1;
    double Dy = a1 * c2 - a2 * c1;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << fixed << setprecision(6) << x << " " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0)
            cout << "Infinite Intersections" << endl;
        else
            cout << "Never Intersect" << endl;
    }

    return 0;
}
