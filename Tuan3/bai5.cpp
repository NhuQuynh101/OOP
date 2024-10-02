#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class DiemHS{
    friend class HocSinh;
private:
    float gk;
    float ck;
    float last;
public:
    void nhap();
    bool checkscore();
    void acc_last();
    bool checktp();
    
};
class NgaySinh{
    friend class HocSinh;
private:
    int ngay;
    int thang;
    int nam;
public:
    bool check();
    void nhapntn();
    bool checknamnhuan(int y);
    int khoangcach(int y, int m, int d);
    bool checkage();
    
};


class HocSinh{
private:
    string name;
    NgaySinh sn;
    DiemHS toan;

    DiemHS van;
    DiemHS anh;
    float tb;
public:
    void nhap();
    
    float getdtb();
    
    
    bool checktbtren7();
    bool checktptren5();
    
    void outputdk();
    bool checkdk();
    friend int count(HocSinh s[], HocSinh dat[], int n,  int& m);
};

bool NgaySinh::checknamnhuan(int y){
    if (y % 400 ==0 || (y % 4==0 && y % 100 != 0)) return 1;
    return 0;
}

bool NgaySinh::check(){
     if (thang == 4 || thang == 6 || thang == 9 || thang == 11){
        if (ngay <= 30 && 1 <= ngay ) return 1;
    }
     else if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
        if (1 <= ngay && ngay <= 31 ) return 1;
    }
    
    else if (thang == 2){
        if ( checknamnhuan(nam) == 0){
            if ( ngay <=28 && 1 <= ngay ) return 1;
        }
        else {
            if (1 <= ngay && ngay <=29 ) return 1;
        }
    }
    return 0;
}
void NgaySinh::nhapntn(){
    while(1){
        string s;
        cin >> s;
        
        sscanf(s.c_str(), "%d/%d/%d", &ngay, &thang, &nam);
        if (check() == 1) break;
    }
    
}


int NgaySinh::khoangcach(int nam, int thang, int ngay) {
    if (thang < 3) {
        thang = thang + 12;
        nam--;
        
    }

    return 365*nam + nam/4 - nam/100 + nam/400 + (153*thang - 457)/5 + ngay - 306;
}

bool NgaySinh::checkage(){
    if (2023 - nam > 17) return 1;
    int m = khoangcach(2006,1,1) - khoangcach(nam, thang, ngay);
    if (m < 0) return 0;
    return 1;
}

void DiemHS::nhap(){
    cin >> gk;
    cin >> ck;
    acc_last();
}
void DiemHS::acc_last(){
    last = 0.3 * gk + 0.7 * ck;
}

bool DiemHS::checktp(){
    if (gk >= 5 &&  ck >= 5) return 1;
    return 0;
}
bool DiemHS::checkscore(){
    if ((gk > 10 || gk < 0) || (ck > 10 || ck < 0)) return 0;
    return 1;
}
void HocSinh::nhap(){
    cin.ignore();
    getline(cin, this->name);
    sn.nhapntn();
    while(1){
        toan.nhap();
        van.nhap();
        anh.nhap();
        if (toan.checkscore() == 1 && van.checkscore() == 1 && anh.checkscore() == 1)
            break;
    }
}

bool HocSinh::checktptren5(){
    if (toan.checktp() != 1 || van.checktp() != 1 || anh.checktp() != 1) return 0;
    return 1;
}

bool HocSinh::checktbtren7(){
    if (van.last > 7 && toan.last > 7 &&  anh.last > 7) return 1;
    return 0;
}

bool HocSinh::checkdk(){
    if (sn.checkage() == 0) return 0;
    tb = (van.last + toan.last + anh.last)/3.0;
    
    if (checktbtren7() == 0) return 0;
    if (checktptren5() == 0) return 0;
    if (tb <= 8) return 0;
    return 1;
}
float HocSinh::getdtb(){
    return tb;
}

void HocSinh::outputdk(){
    cout <<"Ho ten: " << name << " - Diem trung binh: " <<setprecision(3) << tb << endl;
}

int count(HocSinh a[], HocSinh dat[], int n,  int& x){
    int m = 0;

    for(int i = 0; i < n; i++){

        if (a[i].checkdk() == 1){

            dat[x++] = a[i];

            m++;
        }
    }
    return m;
}

void sapxep(HocSinh a[], int n){
    for (int i = 0; i < n-1; i++){
        int  max = i;
        for (int j = i+1; j < n; j++){
            if (a[j].getdtb() > a[max].getdtb()) {

            max = j;

        }
        }
        swap(a[i], a[max]);

    }
}
int main(){
    HocSinh dat[500];

    HocSinh A[500];
   
    int n, t;
    int m = 0;
    cin >> n;
    cin >> t;
    
    for (int i = 0; i < n; i++){
        A[i].nhap();
    }
    
    int dem = count(A, dat, n, m);
    
    if (dem != t){

        sapxep (dat, m);

    }
    for (int i = 0; i < m && i < t; i++){
        dat[i].outputdk();
    }

}