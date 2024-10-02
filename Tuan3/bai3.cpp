#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class dayofyear {
private:
    int day;
    int month;
    int year;
    int n;
public:

    dayofyear ();
    dayofyear (int,int,int);
    
    void check();
    int CheckDayOfmonth();
    long checkday();
    dayofyear operator- (int);
    dayofyear operator+ (int);
    
    int operator- (dayofyear);

    friend ostream& operator<<(ostream& os,dayofyear ngay);
};

ostream& operator<<(ostream& os, dayofyear ngay) {
    return os << ngay.day << " " << ngay.month << " " << ngay.year;
}

int dayofyear::CheckDayOfmonth() {
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;

    else if (month == 1 || month == 3|| month == 5 || month == 7 || month == 8 || month == 10|| month == 12) return 31;
    
    if ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0 && year % 100 == 0)){
         n = 2;
         return 29;
        }
    else return 28;
}

void dayofyear::check() {
    this->month=(this->month)%12; if (this->month == 0) this->month = 12;
    if (this->day > CheckDayOfmonth()) this->day = 1;
}

dayofyear::dayofyear() {
    this->month = 1;

    this->day = 1;
    
    this->year = 1;
    this->n = 0;
}



dayofyear::dayofyear ( int x, int y, int z) {
    this->n = 0;
    this->day = abs(x);
    this->year = abs(z);
    this->month = abs(y);
    
    
}

long dayofyear::checkday() {
    int nam = year-1;

    int t = month-1;
    int ng = 0;
    
    while(t)
    {
        if (t == 4 || t == 6|| t == 9||t == 11) ng = ng + 30;
        else if (t == 1 || t == 3|| t == 5|| t == 7|| t == 8 || t == 10|| t == 12) ng = ng + 31;
        
        if (t == 2 && n == 2) {
            ng = ng + 29;
        }
        if (t == 2 && n == 0) ng = ng + 28;
        t--;
    }
    return year*365 + year/4 + year/400 -year/100 + day + ng;
        

}

dayofyear dayofyear::operator+ (int x) {

    return dayofyear (day + x, month, year);
}

int dayofyear::operator- (dayofyear x) {
    
    return abs(this->checkday()- x.checkday());
}

dayofyear dayofyear::operator- (int x) {
    
    return dayofyear(day - x, month, year);
}



int main() {

    int n,k;
    int d,m,y;
    
    cin >> d >> m >> y;

    dayofyear dd(d ,m, y);
    
    
    dd.check();
    while(true)
    {
        cin>>n;
        if (n == 2) {
            cin >> k;
            
            dd = dd - k;
        }
        else if (n == 1) {
            cin >> k;
            
            dd = dd + k;
        }
        else if (n == 2) {
            cin >> k;

            dd = dd - k;
        }
        else if(n == 3) {
            int a, b, c;
            
            cin >> a >> b >> c;
            
            dayofyear d1(a, b, c);
            
            d1.check();
            
            cout <<dd - d1 << endl;
            break;
        }
    }
    return 0;
}