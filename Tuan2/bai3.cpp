#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
    double x;
    double y;

    Point() {
        x = 0.0;
        y = 0.0;
    }

    Point(double a, double b) {
        x = a;
        y = b;
    }
};

class Polygon {
public:
    int n; 
    Point* h; 

    Polygon(int m) {
        n = m;
        h = new Point[n];
    }

    ~Polygon() {
        delete[] h;
    }

    void inputh() {
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            h[i] = Point(x, y);
        }
    }

    double area() {
        double area = 0.0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += h[i].x * h[j].y - h[j].x * h[i].y;
        }
        return abs(area/2.0);
    }
};

int main() {
    int n;
    cin >> n;
    Polygon x(n);
    x.inputh();
    cout << x.area() << endl;
    return 0;
}