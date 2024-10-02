#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class sophuc {
private:
    double a;
    double b;
public:
    sophuc (double r, double i) {
        a = r;
        b = i;
    }
    double geta() {
        return a;
    }
    double getb() {
        return b;
    }
    sophuc getNthmu(int n, int k) {
        double r = pow(sqrt(pow(a, 2) + pow(b, 2)), 1.0/n);
        double theta = atan2(b, a);
        double new_theta = (theta + 2*k*M_PI)/n;
        double thuc = r*cos(new_theta);
        double ao = r*sin(new_theta);
        sophuc z(thuc, ao);
        return z;
    }
};

int main() {
    double r, i;
    int n;
    cin >> r;
    cin >> i;
    cin >> n;
    if (r == 0 && i == 0) {
        for (int i = 0; i < n; i++){
                cout << "0 0" << endl;
        }
    }
    else {
    sophuc z(r, i);
    for (int k = 0; k < n; k++) {
        sophuc z_nthmu = z.getNthmu(n, k);
        cout <<round(z_nthmu.geta()*100)/100 << " " << round(z_nthmu.getb()*100)/100 << endl;
    }
    }
    return 0;
}