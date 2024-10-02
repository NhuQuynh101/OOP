#include <iostream>
#include <vector>
#include <string>
using namespace std;
class room {
protected: 
        int type;
        string name;
        int floor;
        int maso;
        int succhua;
public: 
        virtual void Nhap (){
                cin >> name;
                cin >> floor >> maso >> succhua;
        }
        int getLoai (){
                return type;
        }
        string getName(){
                return name;
        }
        int getFloor(){
                return floor;
        }
        int getsc(){
                return succhua;
        }
        int getMS(){
                return maso;
        }
};
class TheoryRoom : public room {
protected:
        int check;
public: 
        TheoryRoom(){
                type = 1;
        }
        void Nhap (){
                room::Nhap();
                cin >> check;
        }
};
class PracticalRoom : public room {
protected:
        int count;
public:
        PracticalRoom(){
                type = 2;
        }
        void Nhap (){
                room::Nhap();
                cin >> count;
        }
};
class GD : public room{
        int mc;
public:
        GD(){
                type = 3;
        }
        void Nhap (){
                room::Nhap();
                cin >> mc;
        }
};
class ListRoom {
protected:
        vector <room*> a;
public:
        void Nhap(){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
                int type;
                cin >> type;
                if (type == 1) {
                        room *s = new TheoryRoom;
            ((TheoryRoom*)s)->Nhap() ;
            a.push_back(s);
                }
                else if (type == 2) {
                        room *s = new PracticalRoom;
            ((PracticalRoom*)s)->Nhap() ;
            a.push_back(s);
                }
                else if (type == 3){
                        room *s = new GD;
            ((GD*)s)->Nhap() ;
            a.push_back(s);
                }
        }
        }
        int findTongSC (){
                int total = 0;
                for (int i = 0; i < a.size(); i++){
                        total += a[i]->getsc();
                }
                return total;
        }
        void find(int k){
                room* m = new room;
                m = NULL;
                int temp = 0;
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->getsc() >= k) {
                                m = a[i];
                                temp = 1;
                                break;
                        }
                }
                if (temp == 0) {
                        cout << "NULL";
                        return;
                }
                else {
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->getsc() == m->getsc()){
                                if (a[i]->getFloor() < m->getFloor()){
                                        m = a[i];
                                }
                                else if (a[i]->getFloor() == m->getFloor()){
                                        if (a[i]->getMS() < m->getMS()) m = a[i];
                                }
                        }
                }
                cout << m->getName();
                }
                
        }

};
int main (){
        
        ListRoom l;
        l.Nhap();
        int k;
        cin >> k;
        cout << l.findTongSC() << endl;
        l.find(k);
}
