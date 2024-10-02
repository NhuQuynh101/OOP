#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct phanso{
    int tuso;
    int mauso;
};
phanso a,b,kq;
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}


void nhap (int &n, phanso a[]){
        cin >> n;
        int i = 0;
        for (i = 0; i < n; i++){
                cin >> a[i].tuso >>  a[i].mauso;
        while (a[i].mauso == 0){
                cin >> a[i].mauso;
        }
        }
}
void rutgon (int n, phanso a[]){
        for (int i = 0; i < n; i++){
                int g = gcd(a[i].tuso, a[i].mauso);
                
                a[i].tuso /= g;
                a[i].mauso /= g;
        
                cout << a[i].tuso << "/" << a[i].mauso << endl;
                }
        }


int main()
{
  int n;
  phanso a[100];
  nhap(n,a);
  rutgon(n,a);
}