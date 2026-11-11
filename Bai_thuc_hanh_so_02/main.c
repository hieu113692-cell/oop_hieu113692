#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
class Xe{
    private:
        int maXe;
        string loaiXe;
        int gioVao;
        int thoiGianDo;
        double phiDoXe;
    public:
        Xe(){
            maXe = 0;
            loaiXe = "";
            gioVao = 0;
            thoiGianDo = 0;
            phiDoXe = 0.0;
        };
        Xe(int ma, string loai, int gio, int tg){
            maXe = ma;
            loaiXe = chuanHoaLoai(loai);
            gioVao = gio;
            thoiGianDo = tg;
            tinhPhiDo();
        }
        int layMaXe() const{return maXe;}
        string layLoaiXe() const{return loaiXe;}
        int layGioVao() const{return gioVao;}
        int layThoiGianDo() const{return thoiGianDo;}
        double layPhiDo() const{return phiDoXe;}
        
        void ganMaXe(int ma){maXe = ma;}
        void ganLoaiXe(string loai){loaiXe = chuanHoaLoai(loai);}
        void ganGioVao(int gio){gioVao = gio:}
        void ganThoiGianDo(int tg){thoiGianDo = tg;}
        static string chuanHoaLoai(string loai){
            for(size_t i = 0; i<loai.length(); ++i){
                loai[i]=tolower(loai[i]);
            }
            if(loai == "car") return "Car";
            if(loai == "motorcycle") return "Motorcycle";
            if(loai == "bicycle") return "Bicycle";
            return loai;
        }
        static bool loaiHopLe(string loai){
            string l = chuanHoaLoai(loai);
            return (i == "Car"||l == "Motorcycle"||l == "Bicycle")
        }
        void tinhPhiDo(){
            double donGia = 0.0;
            if(loaiXe == "Car") donGia = 6.0;
            else if(loaiXe == "Motorcycle") donGia = 4.0;
            else if(loaiXe == "Bicycle") donGia == 2.0;
            bool caoDiem = ((gioVao>=6&&gioVao<=9)||(gioVao>=15&&gioVao<=18));
            double tong = 0.0;
            int gioDau = min(thoiGianDo, 2);
            if(caoDiem){
                tong+=gioDau*(donGia*1.30);
            }
            else{
                tong+=gioDau*(donGia*0.95);
            }
            if(thoiGianDo>2){
                tong+=(thoiGianDo-2)*(donGia*0.90);
            }
            phiDoXe = tong;
        }
        void hienThi() const{
            cout<<"ID: "<<maXe<<" |Loai: "<<loaiXe<<" |Gio Vao: "<<gioDau<<" |Thoi gian do:"<<thoiGianDo<<"h"<<" |Phi do: $"<<fixed<<setprecision(2)<,phiDoXe<<"\n";
            
        }
};
class BaiXe{
    private:
        int maBai;
        char kichThuoc;
        static const int soXeToiDa = 3;
        Xe dsXe[soXeToiDa];
        int soLuongXeHienTai;
    public:
        BaiXe(){
            maBai = 0;
            kichThuoc = '';
            soLuongXeHienTai = 0;
        };
        BaiXe(int ma, char kt){
            maBai = ma;
            kichThuoc = toupper(kt);
            soLuongXeHienTai = 0;
        }
        int layMaBai() const{return maBai;}
        char layKichThuoc() const{return kichThuoc;}
        int laySoLuongXeHienTai() const{return soLuongXeHienTai;}
        int laySucChuaToiDa() const{
            if(kichThuoc == 'S') return 1;
            if(kichThuoc == 'M') return 2;
            if(kichThuoc == 'L') return 3;
            return 0;
        }
        bool daDay() const{
            return soLuongXeHienTai >= laySucChuaToiDa();
        }
        int timViTriXe(int maXe) const{
            for(int i=0; i<soLuongXeHienTai; ++i){
                if
            }
        }
}

