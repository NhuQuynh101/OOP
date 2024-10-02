#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const double pi = 3.14;
class bottle {
public: 
        float dodai;
        
        virtual void Nhap (){
                cin >> dodai;
        }
        virtual float TinhdienTich() {
                return 0;
        }
        virtual float TinhluongH20() {
                return 0;
        }
        
};
class truTron : public bottle {
public :
        float r;
        void Nhap (){
                bottle::Nhap();
                cin >> r;
        }
        float TinhdienTich() {
                return 2*pi*r*dodai;
        }
        float TinhluongH20 (){
                return 0.1*pi*pow(r,2)*dodai;
        }
};
class HCN : public bottle {
public: 
        float dai, rong;
        void Nhap (){
                bottle::Nhap();
                cin >> dai >> rong;
        }
        float TinhdienTich (){
                return 2*dodai*(dai+rong) + 2*dai*rong;
        }
        float TinhluongH20 (){
                return 0.1*dodai*dai*rong;
        }
};
class KLP:public bottle {
public:
        void Nhap(){
                bottle::Nhap();
        }
        float TinhdienTich(){
                return 6*pow(dodai,2);
        }
        float TinhluongH20(){
                return 0.1*pow(dodai,3);
        }
};
int main (){
        int n;
        cin >> n;
        double TongDT = 0, TongH20 = 0;
        bottle** dsbottle = new bottle*[n];

        for (int i = 0; i < n; i++) {
                int loai; 
                cin >> loai;
                if (loai == 1) dsbottle[i] = new truTron;
                if (loai == 2) dsbottle[i] = new HCN;
                if (loai == 3) dsbottle[i] = new KLP;
                dsbottle[i]->Nhap();
                TongDT += dsbottle[i]->TinhdienTich();
                TongH20 += dsbottle[i]->TinhluongH20();
        }
        cout << "Dien tich chai vo: " << TongDT << endl;
        cout << "Luong nuoc tren mat dat: " << TongH20 << endl;
        
}