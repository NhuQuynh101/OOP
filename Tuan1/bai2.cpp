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

int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
int lcm (int a, int b){
        
        return (a * b)/gcd(a,b);
       
}

void nhap (int &n, phanso a[]){
        cin >> n;
        for (int i = 0; i < n; i++){
                cin >> a[i].tuso >> a[i].mauso;
                while (a[i].mauso == 0){
                cin >> a[i].mauso;
        }
        }
}
void found (int n, phanso a[], double b[]){
        int m = 0;
        int k = 0;
       
        for (int i = 0; i < n; i++){
                b[i] = (double)a[i].tuso/a[i].mauso;
        }
         double maxx = b[0];;
        double minx = b[0];;
        for (int j = 0; j < n; j++){
                if (b[j] > maxx){
                        maxx = b[j];
                        m = j;
                }
        
                if (b[j] < minx) {
                        minx = b[j];
                        k = j;
                }
        }
        
        cout << a[k].tuso << "/" << a[k].mauso << endl;
        cout << a[m].tuso << "/" << a[m].mauso ;
}

int main()
{
  int n;
  phanso a[100];
  double b[100];
  nhap(n,a);
  found(n,a,b);
}