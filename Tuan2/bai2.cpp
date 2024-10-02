#include <iostream>
#include <math.h>
using namespace std;

class tamgiac {
private:
        float x;
        float y;
public: 
        void nhap (){
                cin >> x >> y;
        }
        
        
        void xuat (){
                cout << "(" << x << "," << y << ")";
        }
        void tinhtien (float rad, int d){
                x = x + cos(rad)*d;
                y = y + sin(rad)*d;
        }
};
int main (){
        float k,d;
        tamgiac a,b,c;
        a.nhap();
        b.nhap();
        c.nhap();
        cin >> k >> d;
        float rad = k*3.14/180;
        a.tinhtien(rad,d);
        b.tinhtien(rad,d);
        c.tinhtien(rad,d);
        a.xuat();
        cout << endl;
        b.xuat();
        cout << endl;
        c.xuat ();

}
