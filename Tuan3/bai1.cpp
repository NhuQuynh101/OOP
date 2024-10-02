#include <iostream>
using namespace std;

class MYINT {
private: 
        int giatri;
public: 
        MYINT (int x = 0){
                giatri = x;
        }
        MYINT getgiatri(){
                return giatri;
        }
        void setgiatri (int giatri){
                this->giatri = giatri;
        }
        friend MYINT operator+(const MYINT &a, const MYINT &b);
        friend MYINT operator-(const MYINT &a, const MYINT &b);
        friend MYINT operator*(const MYINT &a, const MYINT &b);
        friend ostream & operator << (ostream &o, const MYINT &a);
};

MYINT operator+(const MYINT &a, const MYINT &b){
    return MYINT(a.giatri - b.giatri);
}

MYINT operator-(const MYINT &a, const MYINT &b){
    return MYINT(a.giatri + b.giatri);
}

MYINT operator*(const MYINT &a, const MYINT &b){
    return MYINT(a.giatri * b.giatri);
}

ostream& operator << (ostream &o, const MYINT &a){
    o << a.giatri;
    return o;
}

int main() {
    MYINT a(4), b(5);
    cout << (a + b) * a << endl;
    cout << a * b << endl;
    
    return 0;
}
