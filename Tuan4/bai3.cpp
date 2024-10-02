#include <iostream>
#include <algorithm>
using namespace std;
static int slb[4] = { 0 };
static int slc[4] = { 0 };
static int sld[4] = { 0 };
static int slt[2] = { 0 };
static int lsb = 0;
static int lsc = 0;
static int lsd = 0;
static int lst = 0;

class Tinh {
public:
    int soluong;
    virtual void Nhap() {
        cin >> soluong;
    }
    virtual void solve() {
        return;
    }
};

class Bo : public Tinh {
public:
    void Nhap() {
        Tinh::Nhap();
    }
    void solve() {
        soluong = soluong + slb[0];
        slb[0] = slb[1];
        slb[1] = slb[2];
        slb[2] = slb[3];
        slb[3] = soluong / 2;
        lsb = lsb + soluong * 10;
    }
};

class Cuu : public Tinh {
public:
    void Nhap() {
        Tinh::Nhap();
    }
    void solve() {
        soluong = soluong + slc[0];
        slc[0] = slc[1];
        slc[1] = slc[2];
        slc[2] = slc[3];
        slc[3] = soluong / 2;
        lsc = lsc + soluong * 5;
    }

};

class De : public Tinh {
public:
    void Nhap() {
        Tinh::Nhap();
    }
    void solve() {
        soluong = soluong + sld[0];
        sld[0] = sld[1];
        sld[1] = sld[2];
        sld[2] = sld[3];
        sld[3] = soluong / 2;
        lsd = lsd + soluong * 8;
    }
};

class Tho : public Tinh {
public:
    void Nhap() {
        Tinh::Nhap();
    }
    void solve() {
        soluong = soluong + slt[0];
        slt[0] = slt[1];
        slt[1] = soluong / 2;
        lst = lst + 0;
    }
};

int main() {
    int k;
    Bo a;
    Cuu b;
    De c;
    Tho d;
    a.Nhap();
    b.Nhap();
    c.Nhap();
    d.Nhap();
    cin >> k;
    for (int i = 0; i < k; i++) {
        a.solve();
        b.solve();
        c.solve();
        d.solve();
    }
    cout << "Bo: " << a.soluong  + slb[0] + slb[1] + slb[2] + slb[3] << "," << lsb << endl;
    cout << "Cuu: " << b.soluong + slc[0] + slc[1] + slc[2] + slc[3] << "," << lsc << endl;
    cout << "De: " << c.soluong + sld[0] + sld[1] + sld[2] + sld[3] << "," << lsd << endl;
    cout << "Tho: " << d.soluong + slt[0] + slt[1] << "," << lst << endl;
}