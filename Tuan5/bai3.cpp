#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Guild {
protected:
        string name;
        float hp;
        float atk;
        float def;
public:
        virtual void Nhap(){
                cin >> name >> hp >> atk >> def;
        }
        float getDef() {
                return def;
        }
        float getHP() {
                return hp;
        }
        float getATK() {
                return atk;
        }
        bool isDead() {
                return hp <= 0;
        }
        void attack(Guild *a){
                if (atk > a->def){
                        a->hp = a->hp - (atk - a->def);
                }
        }
        virtual void change() {} 
        string getName(){
                return name;
        }
};
class Boss : public Guild {};
int countNL = 0;
class HumanKind : public Guild{
protected:
        string jobclass ;
public: 
        void Nhap (){
                Guild::Nhap();
                countNL++;
                cin >> jobclass;
        }

};
class Human : public HumanKind {};
class Elf : public HumanKind {
public:
        void change(){
                def = def*1.5;
        }
};
class DemiHuman : public Guild{
protected:
        string racialclass;
public:
        void Nhap(){
                Guild::Nhap();
                cin >> racialclass;
        }
};
class Orc : public DemiHuman {
public:
        void change(){
                hp = hp + 0.5*hp;
        }
};
class Goblin : public DemiHuman {
public:
        void change(){
                atk = atk + 0.1*atk;
        }
};
class DiHinh : public Guild {};
class Vampire : public DiHinh {
public:
        void change(){
                hp = hp + 0.1*hp*countNL;
        }
};
int countDV = 0;
class Devil : public DiHinh {
public:
        void Nhap(){
                Guild::Nhap();
                countDV++;
        }
        void change() {
                def = def + 0.1*def*countDV;
                atk = atk + 0.1*atk*countDV;
        }
};
class ListGuild {
protected:
        vector <Guild*> a;
public:
        void Nhap(){
                int n;
                cin >> n;
                for (int i = 0; i < n; i++){
                        int type;
                        cin >> type;
                        if (type == 1){
                                Guild *s = new Human;
                                ((Human*)s)->Nhap() ;
                                a.push_back(s);
                        }
                        else if (type == 2){
                                Guild *s = new Elf;
                                ((Elf*)s)->Nhap() ;
                                a.push_back(s);
                        }
                        else if (type == 3){
                                Guild *s = new Orc;
                                ((Orc*)s)->Nhap() ;
                                a.push_back(s);
                        }
                        else if (type == 4){
                                Guild *s = new Goblin ;
                                ((Goblin*)s)->Nhap() ;
                                a.push_back(s);
                        }
                        else if (type == 5){
                                Guild *s = new Vampire ;
                                ((Vampire*)s)->Nhap() ;
                                a.push_back(s);
                        }
                        else if (type == 6){
                                Guild *s = new Devil ;
                                ((Devil*)s)->Nhap() ;
                                a.push_back(s);
                        }
                }
                for (int i = 0; i < a.size(); i++){
                        a[i]->change();
                }
        }
        void solving(Guild *b){
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->isDead() == false){
                                a[i]->attack(b);
                        }
                }
        }
        void Xuat(){
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->isDead() == false){
                                cout << a[i]->getName() << " " << a[i]->getHP() << endl;
                        }
                }
        }
        bool isLose(){
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->isDead() == false) return false;
                }
                return true;
        }
        Guild* findMinHP(){
                Guild *z = new Guild;
                z = NULL;
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->isDead() == false){
                                z = a[i];
                                break;
                        }
                }
                if (z != NULL){
                for (int i = 0; i < a.size(); i++){
                        if (a[i]->isDead() == false && a[i]->getHP() < z->getHP()){
                                z = a[i];
                        }
                }
                }
                return z;
        }
        void ListHP(){
                for (int i = 0; i < a.size()-1; i++){
                        for (int j = i+1; j < a.size(); j++){
                                if (a[j]->getHP() < a[i]->getHP()) swap(a[i],a[j]);
                        }
                }
        }
};
int main(){
        ListGuild l;
        l.Nhap();
        Boss m;
        m.Nhap();
        do {
                l.solving(&m);
                if(m.isDead()) break;
                if(l.findMinHP() != NULL) m.attack(l.findMinHP());
        }
        while (l.isLose() == false);
        if (m.isDead() == false) cout << m.getName() << " " << m.getHP() << endl;
        else {
                l.ListHP();
                l.Xuat();
        }
}