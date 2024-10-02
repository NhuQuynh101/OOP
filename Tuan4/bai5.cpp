#include <bits/stdc++.h>
#include <iostream>
#include<vector>

using namespace std;
static int m, mt1 = 0, mt2 = 0;
static int a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
static int c1 = 0, c2 = 0, c3 = 0, tc1zz = 0, tc2zz = 0, tc3zz = 0;
static int ss = 0, zz = 0, sss = 0, zzz = 0;
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
class Tuong {
public:
        int tc;
        int cs, cz, l;
        virtual void Nhap() {cin >> tc;}
        void Xuat() {
                Tinh();
                if(l == 1) {
                        if(sss > 0 && cs == 3){
                                sss--;
                                cout << Ten() << " - " << tc << endl;
                        }
                
                        else if(sss == 0 && ss > 0 && cs == 2) {
                                ss--;
                                cout << Ten() << " - " << tc << endl;
                        }
                        else if(ss == 0) cout << Ten() << " - " << tc << endl;
                }
                else if(l == 2) {
                        if(zzz > 0 && cz == 3) {
                                zzz--;
                                cout << Ten() << " - " << tc << endl;
                        }
                        else if(zzz == 0 && zz > 0 && cz == 2) {
                                zz--;
                                cout << Ten() << " - " << tc << endl;
                        }
                        else if(zz == 0) cout << Ten() << " - " << tc << endl;
                        }
        }
        virtual void Tinh() {}
        virtual string Ten() {return "";}
        
};
class NhanVien {
public:
        string hoTen;

        virtual void Nhap() {
            cin >> hoTen;
        }

        void Xuat() {
            cout << hoTen << ": " << TinhLuong() << endl;
        }

        virtual float TinhLuong() { 
                return 0;
        }
};

class TuongShaco : public Tuong{
public:
        void Nhap() {
                Tuong::Nhap();
                mt1 = 1;
        }
        void Tinh(){
                int tst = 0;
                l = 1;
                cs = 1;
                if(a1 == 0) a1 = tc;
                else if(a2 == 0) a2 = tc;
                else if(a3 == 0) {
                        cs = 2;
                        a3 = tc;
                        if(b1 == 0){
                                b1 = 2 * (a1 + a2 + a3);
                                tc = b1;
                        }
                        else if(b2 == 0) {
                                b2 = 2 * (a3 + a1 + a2);
                                tc = b2;
                        }
                        else if(b3 == 0) {
                                cs = 3;
                                b3 = 2 * (a3 + a1 + a2);
                                tc = 3 * (b3 + b1 + b2);
                                b3 = b1 = b2 = 0;
                        }
                a1 = a2 = a3 = 0;
                }
                if(mt1 + mt2 == 2) tc += 10;
                for(int i = 0; i < m; i++) tst += tc * 2;
                tc = tst;
        }
        string Ten() {return "Shaco";}
};
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
class TuongZed : public Tuong {
public:
        void Nhap(){
                Tuong::Nhap();
                mt2 = 1;
        }
        void Tinh() {
                int tst = 0;
                l = 2;
                cz = 1;
                if(c1 == 0) c1 = tc;
                else if(c2 == 0) c2 = tc;
                else if(c3 == 0) {
                        cz = 2;
                        c3 = tc;
                        if(tc1zz == 0) {
                                tc1zz = 2 * (c3+c1+c2);
                                tc = tc1zz;
                        }
                        else if(tc2zz == 0) {
                                tc2zz = 2 * (c3+c1+c2);
                                tc = tc2zz;
                }
                else if(tc3zz == 0) {
                        cz = 3;
                        tc3zz = 2 * (c3+c1+c2);
                        tc = 3 * (tc1zz + tc2zz + tc3zz);
                        tc1zz = tc2zz = tc3zz = 0;
                }
                c3 = c1 = c2 = 0;
        }
                if(mt1 + mt2 == 2) tc += 10;
                for(int i = 1; i <= m; i++) {
                        if(i % 3 == 0) tst += tc * 3;
                        else tst += tc;
                }
                tc = tst;
        }
        string Ten() {
                return "Zed";
        }
};
int main()
{
        int count = 0;
        int n; 
        cin >> n ;
        cin >> m;
        Tuong **ds = new Tuong*[n];
        
        for(int i = 0; i < n; i++) {
                int t; cin >> t;
                if(t == 1) {
                        ds[i] = new TuongShaco; 
                        count++;
                }
                else if(t == 2) {
                        ds[i] = new TuongZed;
                }
                ds[i]->Nhap();
        }
        zz = (n - count - zzz * 9) / 3;

        ss = (count - sss * 9) / 3;

        sss = count / 9;
       
        zzz = (n - count) / 9;
        
        for(int i = 0; i < n; i++) ds[i]->Xuat();
        return 0;
}