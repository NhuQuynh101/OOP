#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <bits/stdc++.h>


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

void nhap (int n, phanso a[]){
       
        for (int i = 0; i < n; i++){
                cin >> a[i].tuso >> a[i].mauso;
                while (a[i].mauso == 0){
                cin >> a[i].mauso;
        }
        }
}
void found (int n, phanso a[], double b[], double c[], int k){
        int m = 0;
        int p = 0;
       
        for (int q = 0; q < n; q++){
                b[q] = (double)a[q].tuso/a[q].mauso;
                c[q] = (double)a[q].tuso/a[q].mauso;
        }
        
        sort (b,b+n); 
        double max = b[n-k];
        double min = b[k-1];
        for (int i = 0; i < n; i++){
                if (c[i] == max) m = i;
                if (c[i] == min) p = i;
        }
        if (n == 0);
        else if (k > n);
        else {
        cout << a[m].tuso << "/" << a[m].mauso << endl;
        cout << a[p].tuso << "/" << a[p].mauso ;
        }
        
}

int main()
{
  int n,k;
  cin >> n >> k;
  phanso a[100];
  double b[100];
  double c[100];
  nhap(n,a);
  found(n,a,b,c,k);
}
