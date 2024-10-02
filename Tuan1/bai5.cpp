#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check (int a[][100], int n){
        int k = a[0][0];
        for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                        if (k != a[i][j]) return false;
                }
        }
        return true;
}
int catmap(int a[][100], int n){
        if (check(a,n)) return 0;
        else {
        int b[100][100];
        
        for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                        b[i][j] = a[i][j];
                }
        }
        int k = 0;
        while (true){
                int c[100][100];
                
                for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                                int x = (2*i + j) % n;
                                int y = (i + j) % n;
                                c[x][y] = a[i][j];
                        }
                }
                for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                                a[i][j] = c[i][j];
                        }
                }
                k++;
                bool cat = true;
                for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                                if (a[i][j] != b[i][j]) {
                                        cat = false;
                                        break;      
                                }
                        }
                        if (!cat) break;
                }
                if (cat) break;
        }
        return k;
        }
}
int main() {
        int a[100][100];
        int n;
        cin  >> n;
        for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                        cin >> a[i][j];
                }
        }
        int result = catmap(a,n);
        cout << result;
        return 0;
}
