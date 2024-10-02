#include <bits/stdc++.h>
using namespace std;
class Weapon {
protected:
        int type;
        float st;
        int luotsd;
public:
        virtual void Nhap (){
                cin >> st >> luotsd;
        }
        virtual float SatThuong() = 0;
        int getLuotSD(){
                return luotsd;
        }
        float getST(){
                return st;
        }
        virtual void change() = 0;
        void Xuat(){
                cout <<  luotsd;
        }
};
class Knife : public Weapon{
protected:
        float cdai;
public:
        Knife(){
                type = 1;
        }
        void Nhap (){
                Weapon::Nhap();
                cin >> cdai;
        }
        float SatThuong(){
                return st*cdai;
        }
        void change(){
                luotsd = luotsd-1;
        }

};


class VuKhi
{
    public:
        double satThuong;
        int soLanSuDung;
        VuKhi()
        {}
        
        VuKhi(double satThuong, int soLanSuDung)
        {
            this->satThuong = satThuong;
            this->soLanSuDung = soLanSuDung;
        }


        VuKhi(double satThuong)
        {
            this->satThuong = satThuong;
        }

        virtual double satThuongMoiLuot(){return 1;};
};

class Dao : public VuKhi
{
    public:
        double chieuDai;
        Dao(double satThuong, int soLanSuDung, double chieuDai) : VuKhi(satThuong, soLanSuDung)
        {
            this->chieuDai = chieuDai;
        }
        double satThuongMoiLuot()
        {
            --soLanSuDung;
            return chieuDai * satThuong;
        }
};
class CTen : public Weapon {
protected:
        int soMT;
public:
        CTen(){
                type = 2;
        }
        void Nhap (){
                Weapon::Nhap();
                cin >> soMT;
        }
        float SatThuong(){
                return st*soMT/2.0;
        }
        void change (){
                luotsd = luotsd - 2;
        }
};

class Cung : public VuKhi
{
    public:
        int soMuiTen;
        Cung(double satThuong, int soLanSuDung, int soMuiTen) : VuKhi(satThuong, soLanSuDung)
        {
            this->soMuiTen = soMuiTen;
        }
        double satThuongMoiLuot()
        {
            soLanSuDung -= 2;
            return double((satThuong * soMuiTen) / 2);
        }
};

class TayKhong : public VuKhi
{
    public:
        TayKhong(double hp) : VuKhi(hp * 0.1, 9999)
        {
        }
        double satThuongMoiLuot()
        {
            return satThuong;
        }
};

class A_Phu
{
    public:
        double hp;
        A_Phu(double hp)
        {
            this->hp = hp;
        }
        bool died()
        {
            if (hp <= 0)
            {
                return true;
            }
            return false;
        }
};

class ThuDu
{
    public:
        double hp;
        double satThuong;
        ThuDu(double hp, double satThuong)
        {
            this->hp = hp;
            this->satThuong = satThuong;
        }
        virtual double satThuongMoiLuot(){return 1;};
        virtual void satThuongNhanVao(double satThuong){};
        virtual bool died(){return 1;};
};

class BoTot : public ThuDu
{
    public:
        int soLanChiuDanh;
        BoTot(double hp, double satThuong, int soLanChiuDanh) : ThuDu(hp, satThuong)
        {
            this->soLanChiuDanh = soLanChiuDanh;
        }
        double satThuongMoiLuot()
        {
            return satThuong;
        }
        void satThuongNhanVao(double satThuong)
        {
            hp -= satThuong;
            --soLanChiuDanh;
        }
        bool died()
        {
            if ((soLanChiuDanh == 0) || (hp <= 0))
            {
                return true;
            }
            return false;
        }
};
class WBeast {
protected:
        int type;
        float hp;
        float st;
public:
        virtual void Nhap(){
                cin >> hp >> st;
        }
        virtual bool isDead() = 0;
        virtual float SatThuong() = 0;
        void attack(Weapon *a){
                hp = hp - a->SatThuong();
        }
        int getLoai(){
                return type;
        }
        virtual void change(){
                return;
        }
        void Hand(float p){
                hp = hp - p;
        }
        float getHP(){
                return hp;
        }
        
};
class Ho : public ThuDu
{
    public:
        Ho(double hp, double satThuong) : ThuDu(hp, satThuong)
        {}
        double satThuongMoiLuot()
        {
            return 1.5 * satThuong;
        }
        void satThuongNhanVao(double satThuong)
        {
            hp -= satThuong;
        }
        bool died()
        {
            if (hp <= 0)
            {
                return true;
            }
            return false;
        }
};

void answer(double hp, int soThuDu, int soVuKhi)
{
    if (hp > 0)
    {
        if (soVuKhi <= 0)
        {
            soVuKhi = 0;
        }
        cout << "A Phu chien thang, hp con lai: " << hp << ", so vu khi con lai: " << soVuKhi;
    }
    else
    {
        cout <<  "A Phu that bai, so thu du con lai: " << soThuDu;
    }
}

int main()
{
    double hp_A_Phu;
    cin >> hp_A_Phu;
    A_Phu* warrior = new A_Phu(hp_A_Phu);
    int soVuKhi;
    cin >> soVuKhi;
    vector <VuKhi*> vuKhi(soVuKhi + 1);
    for (int i = 0 ; i < soVuKhi ; i++)
    {
        int loaiVuKhi;
        double satThuong;
        int soLanSuDung;
        double chieuDai_soMuiTen;
        cin >> loaiVuKhi >> satThuong >> soLanSuDung >> chieuDai_soMuiTen;
        if (loaiVuKhi == 1)
        {
            vuKhi[i] = new Dao(satThuong, soLanSuDung, chieuDai_soMuiTen);
        }
        else
        {
            vuKhi[i] = new Cung(satThuong, soLanSuDung, chieuDai_soMuiTen);
        }
    }
    vuKhi[soVuKhi] = new TayKhong(hp_A_Phu);
    int soThuDu;
    cin >> soThuDu;
    vector <ThuDu*> thuDu(soThuDu + 1);
    for (int i = 0 ; i < soThuDu ; i++)
    {
        int loai;
        double hp, satThuong;
        cin >> loai >> hp >> satThuong;
        if (loai == 1)
        {
            int soLanChiuDanh;
            cin >> soLanChiuDanh;
            thuDu[i] = new BoTot(hp, satThuong, soLanChiuDanh);
        }
        else
        {
            thuDu[i] = new Ho(hp, satThuong);
        }
    }

    int vuKhiHienTai = 0;
    for (int i = 0 ; i < soThuDu ; i++)
    {
        while ((vuKhi[vuKhiHienTai]->soLanSuDung <= 0) && (vuKhiHienTai <= soVuKhi))
        {
            ++vuKhiHienTai;
        }
        while(thuDu[i]->hp > 0)
        {
            double satThuong;
            if (vuKhiHienTai == soVuKhi)
            {
                satThuong = vuKhi[soVuKhi]->satThuongMoiLuot();
                warrior->hp -= satThuong;
                if (warrior->died())
                {
                    answer(warrior->hp, soThuDu - i, soVuKhi - vuKhiHienTai);
                    return 0;
                }
            }
            else
            {
                satThuong = vuKhi[vuKhiHienTai]->satThuongMoiLuot();
            }
            thuDu[i]->satThuongNhanVao(satThuong);
            if ((vuKhi[vuKhiHienTai]->soLanSuDung <= 0) && (vuKhiHienTai <= soVuKhi)) ++vuKhiHienTai;
            if (thuDu[i]->died()) break;

            warrior->hp -= thuDu[i]->satThuongMoiLuot();
            if (warrior->died())
            {
                answer(warrior->hp, soThuDu - i, soVuKhi - vuKhiHienTai);
                return 0;
            }
        }
    }
    answer(warrior->hp, 0, soVuKhi - vuKhiHienTai);
}