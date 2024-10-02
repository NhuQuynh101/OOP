#include <iostream>
using namespace std;
class point {
private:
        float t;
        float h;
        int n;
        int x;
public: 
        void nhap (){
                cin >> h >> t;
                cin >> n;
        }
        void solve (int x, int &k, int &d){
                
                if (x == 1) {
                        t = 2.0*t;
                        h = 2.0*h;
                }
                if (x == 2) {
                        t = 0;
                        h = 0;
                }
                if (x == 3){
                        cin >> k >> d;
                        if (k == 0) h = h + d;
                        else t = t + d;
                }
                else ;
        }
        void xuat (){
                cout << "(" << h << "," << t << ")";
        }
        void tinhtien (int x, int k, int d){
                for (int i = 0; i < n; i++){
                cin >> x;
                solve(x,k,d);
        }
        }
};
int main (){
        int x,k,d;
       
        point a;
        a.nhap();
        a.tinhtien(x,k,d);
        a.xuat();
}