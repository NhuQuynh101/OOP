#include <iostream>
#include <string>
using namespace std;
class clockk {
private:
        int gio,phut,giay;
        int n;
public: 
        clockk (int x = 0, int y = 0, int z = 0){
                gio = x;
                phut = y;
                giay = z;
        }
        clockk operator++(){
                clockk k;
                k.gio = gio;
                k.phut = phut;
                k.giay = giay + 1;
                return k;
        }
        clockk operator--(){
                clockk k;
                k.gio = gio;
                k.phut = phut;
                k.giay = giay - 1;
                return k;
        }
        clockk operator+ (const int &x){
                clockk k;
                k.gio = gio;
                k.phut = phut;
                k.giay = giay + x;
                return k;
        }
        clockk operator- (const int &y){
                clockk k;
                k.gio = gio;
                k.phut = phut;
                k.giay = giay - y;
                return k;
        }
        void timgio (){
                if (giay < 0){
                        giay = giay + 60;
                        phut = phut - 1;
                        gio = gio;
                }
                if (phut < 0){
                        phut = phut + 60;
                        giay = giay ;
                        gio = gio - 1;

                }
                if (gio < 0){
                        gio = gio + 24;
                        phut = phut;
                        giay = giay;
                }

        }
        void xuat (){
                cout << gio << " " << phut << " " << giay;
        }

};
int main (){
        int n;
        int x,y,z;
        cin >> x >> y >> z;
        if (x > 24) x = x % 24;
        if (y > 60) y = y % 60;
        if (z > 60) z = z % 60;
        cin >> n;
       
        clockk a (x,y,z);
        string s;
        int t;
        for (int i = 0; i < n; i++){
                cin >> s;
                if (s == "++") {
                        a = a + 1;
                        a.timgio();
                }
                if (s == "--") {
                        a = a - 1;
                        a.timgio();
                }
                if (s == "+"){
                        cin >> t;
                        a = a + t;
                        a.timgio();
                }
                if (s == "-") {
                        cin >> t;
                        a = a - t;
                        a.timgio ();
                }
        }
        a.xuat();
}