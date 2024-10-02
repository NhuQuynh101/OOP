#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Prince {
private:
        int type;
public:
        Prince(int _type) : type(_type) {}

        virtual void Nhap() = 0;
        virtual int KetQua() = 0;

        int GetType() {
                return type;
        }
};

class BusinessGate : public Prince {
private:
        int price;
        int amount;
public:
        BusinessGate() : Prince(1) {}

        void Nhap() {
                cin >> price >> amount;
        }

        int KetQua() {
                return amount * price;
        }
};

class PowerGate : public Prince {
private:
        int power;
public:
        PowerGate() : Prince(3) {}

        void Nhap() {
                cin >> power;
        }

        int KetQua() {
                return power;
        }
};

class AcadamicGate : public Prince {
private:
        int brainpower;
public:
        AcadamicGate() : Prince(2) {}

        void Nhap() {
                cin >> brainpower;
         }   

        int KetQua() {
                return brainpower;
        }
};



int main() {
        int n;
        cin >> n;
        Prince** ds = new Prince*[n];
        for (int i = 0; i < n; i++) {
                int k;
                cin >> k;
                if (k == 1) ds[i] = new BusinessGate();
                if (k == 2) ds[i] = new AcadamicGate();
                if (k == 3) ds[i] = new PowerGate();
                ds[i]->Nhap();
        }
        int x, y, z;
        cin >> x >> y >> z;
        int i = 0;
        int count = 0;
        while (x > 0 && y > 0 && z > 0 && i < n) {
                if (ds[i]->GetType() == 1) {
                x -= ds[i]->KetQua();
                if (x < 0) {
                        count++;
                        cout << -1;
                        break;
                }
                }
                if (ds[i]->GetType() == 2) {
                        if (ds[i]->KetQua() > y){
                            count++;
                            cout << -1;
                            break;
                        }
            
                }
                if (ds[i]->GetType() == 3) {
                        z -= ds[i]->KetQua();
                        if (z < 0) {
                                count++;
                                cout << -1;
                                break;
                        }
                }
        i++;
        }

        if (count == 0) cout << x << " " << y << " " << z;
        for (int i = 0; i < n; i++) delete ds[i];
    
        delete[] ds;

}
