#include <iostream>
#include <vector>
#include <string>
using namespace std;

class XeTang {
protected:
        int type;
        float weight;
        int crew;
        int SLdan;
        float SoLX;
public:
        virtual void Nhap (){
                cin >> weight >> crew >> SLdan >> SoLX;
        }
        int getNum(){
                return SLdan;
        }
        int getCrew(){
                return crew;
        }
        int getLoai(){
                return type;
        }
        int getSLDan(){
                return SLdan;
        }
        float getSoLX(){
                return SoLX;
        }
        virtual float HieuSuat(int k, float t) = 0;
        
        virtual void Xuat(int k, float t,float x, float y) = 0;
        virtual float satThuong(int k) = 0;
};
class SU152 : public XeTang {
protected: 
        float size;
        int hp;
public:
        SU152(){
                type = 1;
                size = 152;
                hp = 600;
        }

        void Nhap(){
                XeTang::Nhap();
        }
        float satThuong(int k){
                return ((float)getCrew()/4)*size*(getSLDan()-k);
        }
        float HieuSuat(int k, float t){
                return ((float)(SLdan-k))/((float)SLdan)*100;
        }
        void Xuat(int k, float t, float m, float n){
                cout << "SU152, " << "weight: " << weight << ", number of crews: " << crew << ", damage: " << m << ", performance: " << n << "%" << endl;
        }

};
class KV2 : public XeTang {
protected:
        float size;
        int hp;
public: 
        KV2(){
                type = 2;
                size = 76.2;
                hp = 500;
        }
        void Nhap(){
                XeTang::Nhap();
        }
        float satThuong(int k){
                return 3*size*(getSLDan()-k);
        }
        float HieuSuat(int k, float t){
                return ((float)(SLdan-k))/((float)SLdan)*100;
        }
        void Xuat(int k, float t, float m, float n){
                cout << "KV2, " << "weight: " << weight << ", number of crews: " << crew << ", damage: " << satThuong(k) << ", performance: " << HieuSuat(k,t) << "%" << endl;
        }
};
class IS : public XeTang {
protected:
        float size;
        int hp;
public: 
        IS(){
                type = 3;
                size = 122;
                hp = 600;
        }
        void Nhap(){
                XeTang::Nhap();
        }
        float satThuong(int k){
                return 3*size*(getSLDan()-k);
        }
        float HieuSuat(int k, float t){
                return ((float)(SoLX-(450/weight/100*t)))/(float)SoLX*100;
        }
        void Xuat(int k, float t, float m, float n){
                cout << "IS, " << "weight: " << weight << ", number of crews: " << crew << ", damage: " << satThuong(k) << ", performance: " << HieuSuat(k,t) << "%" << endl;
        }
};
class Object279 : public XeTang {
protected:
        float size;
        int hp;
public:
        Object279(){
                type = 4;
                size = 130;
                hp = 1000;
        }
        void Nhap(){
                XeTang::Nhap();
        }
        float satThuong(int k){
                return ((float)getCrew()/4)*size*(getSLDan()-k);
        }
        float HieuSuat(int k, float t){
                return (float)crew/(float)4*100;
        }
        void Xuat(int k, float t, float m, float n){
                cout << "Object279, " << "weight: " << weight << ", number of crews: " << crew << ", damage: " << satThuong(k) << ", performance: " << HieuSuat(k,t) << "%" << endl;
        }
};
class ListXT {
protected:
        vector <XeTang*> a;
public:
        void Nhap(){
                int n;
                cin >> n;
                for (int i = 0; i < n; i++){
                        int type;
                        cin >> type;
                        if (type == 1){
                                XeTang *s = new SU152;
                    ((SU152*)s)->Nhap() ;
                    a.push_back(s);
                        }
                        else if (type == 2){
                                XeTang *s = new KV2;
                    ((KV2*)s)->Nhap() ;
                    a.push_back(s);
                        }
                        else if (type == 3){
                                XeTang *s = new IS;
                    ((IS*)s)->Nhap() ;
                    a.push_back(s);
                        }
                        else if (type == 4){
                                XeTang *s = new Object279 ;
                    ((Object279*)s)->Nhap() ;
                    a.push_back(s);
                        }
                }
        }
        void Solving(){
                float SoKM;
                int DanDaBan;
                cin >> SoKM >> DanDaBan;
                // for (int i = 0; i < a.size(); i++){
                //         if (a[i]->getLoai() == 1){
                //                 float damage = a[i]->satThuong(DanDaBan);
                //                 float per = a[i]->HieuSuat(DanDaBan,SoKM);
                //                 a[i]->Xuat(DanDaBan,SoKM,damage,per);
                                
                //         }
                //         else if (a[i]->getLoai() == 2){
                //                 float damage = a[i]->satThuong(DanDaBan);
                //                 float per = a[i]->HieuSuat(DanDaBan,SoKM);
                //                 a[i]->Xuat(DanDaBan,SoKM,damage,per);
                //         }
                //         else if (a[i]->getLoai() == 3){
                //                 float damage = a[i]->satThuong(DanDaBan);
                //                 float per = a[i]->HieuSuat(DanDaBan,SoKM);
                //                 a[i]->Xuat(DanDaBan,SoKM,damage,per);
                //         }
                //         else if (a[i]->getLoai() == 4){
                //                 float damage = a[i]->satThuong(DanDaBan);
                //                 float per = a[i]->HieuSuat(DanDaBan,SoKM);
                //                 a[i]->Xuat(DanDaBan,SoKM,damage,per);
                //         }
                // }
                int q = a.size();
                for (int i = 0; i < q; i++){
                        a[i]->Xuat(DanDaBan, SoKM, a[i]->satThuong(DanDaBan),a[i]->HieuSuat(DanDaBan,SoKM));
                } 
                // cout << a[1]->getCrew() << endl;
                // cout << a[1]->getSLDan()-DanDaBan << endl;
                // cout << a[1]->getNum() << endl;
                
        }
};
int main(){
        ListXT l;
        l.Nhap();
        l.Solving();
}