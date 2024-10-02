#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class P;
class MH;
class VP;
class CPU;

class CPU
{
        string mcpu;
        int sc;
        string name;
        float xn;
        int lcpu;
        
public:
        int gn;
        void Nhap(){
                cin >> lcpu; 
                cin >> mcpu;
        }
        void Tinh(){
                if(lcpu == 3){
                        sc = 4;
                        xn = 2.6;
                        gn = 600;
                        
                        name = "White";
                }
                else if(lcpu == 1){
                        sc = 2;
                        xn = 1.8;
                        gn = 200;
                        
                        name = "Black";
                }
                else if(lcpu == 2){
                        sc = 4;
                        xn = 2.46;
                        gn = 400;
                        
                        name = "Black";
                }
                
        }
        void Xuat(){
                cout << "CPU: " << mcpu << " ";
                if(lcpu == 3) cout << "Gamma White 4 2.6 600" << endl;
                else if(lcpu == 1) cout << "Alpha Black 2 1.8 200" << endl;
                else if(lcpu == 2) cout << "Beta Black 4 2.46 400" << endl;
                
        }
};
class MH {
        string mmh;

        int n;
        float m;
        string hsx;
public:
        int gn, cl;
        void Nhap() {
                cin >> mmh >> hsx >> n;
        }
        void Xuat(){
                cout << "Man hinh: " << mmh << " " << hsx << " ";

                if (n != 1) {

                        cout << "Full HD ";
                        if(cl == 1) cout << "Chong loa" << endl;
                }
                else cout << "HD 200" << endl;
                
        }

        void Tinh(){
                m = 4.7;
                if(n == 2) {
                        cin >> cl;

                        if(cl == 1) gn = 500;
                        else gn = 300;
                }

                else if(n == 1) gn = 200;
                
                
        }
        
};
class VP {
        string mv, name;
        int lv, ms;
public:
        int gn;
        void Nhap(){
                cin >> lv >> mv >> ms;
        }
        void Tinh() {
                if(lv == 1) {
                        gn = 400;
                        name = "Black";
                }
                else if(lv == 2) {
                        gn = 200;
                        name = "White";
                }
        }
        void Xuat() {
                cout << "Vo smartphone: " << mv << " ";
                if(lv == 1) {
                        cout << "Nhom Black ";
                        if (ms == 1) cout << "Do";
                        else if (ms == 2) cout << "Den";
                        cout << " 400" << endl;
                }
                else if(lv == 2) {
                        cout << "Sat White ";
                        if (ms == 1) cout << "Do";
                        else if (ms == 2) cout << "Den";
                        else if (ms == 3) cout << "Xanh";
                        cout << " 200" << endl;
                }
        }
};
class P : public CPU, public MH, public VP {
        string mp;
        int dp, gb;
public:
        void Nhap() {
                cin >> dp >> mp;
                CPU::Nhap();
                MH::Nhap();
                VP::Nhap();
        }
        void Tinh() {
                CPU::Tinh();
                MH::Tinh();
                VP::Tinh();
                int x = CPU::gn + MH::gn + VP::gn;
                if(dp == 3) gb =  1.8*x;
                else if(dp == 1) gb = 1.3*x;

                else if(dp == 2) gb = x * 1.5;
                
        }
        void Xuat() {
                Tinh();
                cout << "Smartphone: ";
                cout << mp << " ";
                if(dp == 1) cout << "Venus ";
                else if(dp == 2) cout << "Mars ";
                else if(dp == 3) cout << "Jupiter ";
                cout << gb << endl;
                CPU::Xuat();
                MH::Xuat();
                VP::Xuat();
        }
};
int main()
{
        int n; 
        cin >> n;
        P *ds = new P[n];
        for(int i = 0; i < n; i++) {
                ds[i].Nhap();
        }
        for(int i = 0; i < n; i++) {
                ds[i].Xuat();
        }
       
}