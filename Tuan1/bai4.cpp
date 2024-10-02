#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int day,month,year;
    cin >> day >> month >> year;
    if ( year >0 && year%4==0) {
        if (month == 2){
            if (day < 0 || day > 29) cout <<"ERROR";
            else if (day == 29) cout << 1 << "/" << 3 << "/" << year;
            else cout << day+1 << "/" << month << "/" << year;
            }
            else if (month==4 || month==6 || month==9 || month==11){
                if (day<0 || day>30)  cout << "ERROR"; 
                else if (day == 30) cout << 1 << "/" << month+1 <<"/" << year;
                else cout << day+1 << "/" << month << "/" << year;
                }
            else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10) {
                if (day<0 || day>31)      cout << "ERROR";
                else if (day == 31) cout << 1 << "/" << month+1 <<"/" << year;
                else cout << day+1 << "/" << month << "/" << year;
                }
                else if (month == 12){
                        if (day<0 || day>31)      cout << "ERROR";
                        else if (day == 31) cout << 1 << "/" << 1 << "/" << year+1;
                        else cout << day+1 << "/" << month << "/" << year;
                }        
                else cout << "ERROR";
                    }
        else if (year>0 && year%4!=0) {
        if (month == 2){
            if (day<0 || day>28) cout << "ERROR"; 
            else if (day == 28) cout << 1 << "/" << 3 << "/" << year;
            else cout << day+1 << "/" << month << "/" << year;
        }
            else if (month==4 || month==6 || month==9 || month==11){
                if (day<0 || day>30)  cout << "ERROR"; 
                else if (day == 30) cout << 1 << "/" << month+1 << "/" << year;
                else cout << day+1 << "/" << month << "/" << year;
                }
        else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 ) {
                if (day<0 || day>31) cout << "ERROR";
                else if (day == 31) cout << 1 << "/" << month+1 << "/"<< year;
                else cout << day+1 << "/" << month << "/" << year;
                }
                else if (month == 12){
                        if (day<0 || day>31)      cout << "ERROR";
                        else if (day == 31) cout << 1 << "/" << 1 << "/" << year+1;   
                        else cout << day+1 << "/" << month << "/" << year;
                }

        

        else  cout << "ERROR";
        }
        else cout << "ERROR";
}