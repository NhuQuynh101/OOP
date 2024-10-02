#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class DaThuc {
public:
    vector <int> heso;

    DaThuc() {}

    DaThuc (int n) {
        heso.resize( n + 1, 0);
    }

    void nhap() {
        int k;
        cin >> k;
        heso.resize(k + 1);
        for (int i = 0; i <= k; i++) {
            cin >> heso[i];
        }
    }

    DaThuc operator+(const DaThuc & p) const {
        DaThuc sum ( max(heso.size(), p.heso.size()) - 1);
        for (int i = 0; i < sum.heso.size(); i++) {
            
            if (i < p.heso.size()) {
                sum.heso[i] += p.heso[i];
            }
            if (i < heso.size()) {
                sum.heso[i] += heso[i];
            }
        }
        return sum;
    }

    DaThuc operator- (const DaThuc& p) const {
        int n = heso.size();
        int m = p.heso.size();
        DaThuc sum (max(m,n) - 1);
        for (int i = 0; i < sum.heso.size(); i++) {
            
            if (i < m)  sum.heso[i] -= p.heso[i];
            
            if (i < n) sum.heso[i] += heso[i];
            
        }
        return sum;
        
    }

    DaThuc operator*(const DaThuc& a) const {
        int n = heso.size() + a.heso.size() - 2;
        int m = heso.size();
        int t = a.heso.size();
        DaThuc p(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < t; j++) {
                p.heso[i + j] += heso[i] * a.heso[j];
            }
        }
        return p;
    }

    string chuanhoa() const {
        bool check = true;

        stringstream ss;
        
        int m = heso.size();
        
        for (int i = 0; i < m ; i++) {
            if (heso[i] == 0) continue;
            
            if (!check) {
                if (heso[i] > 0) ss << "+";
            }
                
            
            else check = false;
            if (i == 1) ss << heso[i] << "x^" << 1;
            else if (i == 0) ss << heso[i] << "x^" << 0;
            
            
            else  ss << heso[i] << "x^" << i;
            
        }
        if (check) ss << "0";
        
        return ss.str();
}

};

int main() {
    DaThuc p1, p2, p3;
    
    p1.nhap();
    p2.nhap();
    
    char s;
    cin >> s;
    if (s == '-') p3 = p1 - p2;
    
    else if (s == '*') p3 = p1 * p2;
    
    else if (s == '+')  p3 = p1 + p2;
    
    cout << p3.chuanhoa() << endl;
    
}
