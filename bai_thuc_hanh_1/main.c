#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cctype>
using namespace std;
class Xe{
	private:
		int maXe;
		string loaiXe;
		int gioVao;
		int thoiGianDo;
		double phiDoXe;
		bool dangChiemCho;
	public:
		Xe(){
			maXe=0; loaiXe=""; gioVao=0; thoiGianDo=0; phiDoXe=0.0; dangChiemCho=false;
		};
		Xe(int ma, const string& loai, int gio, int thoiLuong){
			maXe = ma;
			loaiXe = chuanHoaLoaiXe(loai);
			gioVao = gio;
			thoiGianDo = thoiLuong;
			dangChiemCho = true;
			phiDoXe = 0.0;
		}
		int layMaXe() const{return maXe;}
		string layLoaiXe() const{return loaiXe;}
		int layGioVao() const{return gioVao;}
		int layThoiGianDo() const{return thoiGianDo;}
		double layPhiDoXe() const{return phiDoXe;}
		bool LayDangChiemCho() const{return dangChiemCho;}
		void ganMaXe(int ma){
			maXe = ma;
		}
		void ganLoaiXe(const string& loai){
			loaiXe = loai;
		}
		void ganGioVao(int gio){
			gioVao = gio;
		}
		void ganThoiLuongDo(int thoiLuong){
			thoiGianDo = thoiLuong;
		}
		void ganPhiDoXe(double phi){
			phiDoXe = phi;
		}
		void ganDangChiemCho(bool trangThai){
			dangChiemCho = trangThai;
		}
		static string chuanHoaLoaiXe(const string& loai){
			string a = loai;
			for(size_t i =0; i<a.length(); i++){
				a[i] = tolower(a[i]);
			}
			if(a == "car"){
				return "Car";
			}
			if(a == "motorcycle"){
				return "Motorcycle";
			}
			if(a == "bicycle"){
				return "Bicycle";
			}
			return "";
		}
		static bool laLoaiXeHopLe(const string& loai){
			return !chuanHoaLoaiXe(loai).empty();
		}
		void tinhPhiDoXe(){
			if(!dangChiemCho){
				phiDoXe = 0.0;
				return;
			}
			double donGia = 0.0;
			if(loaiXe == "Car"){
				donGia = 6.00;
			}
			else if(loaiXe == "Motorcycle"){
				donGia = 4.00;
			}
			else if(loaiXe == "Bicycle"){
				donGia = 2.00;
			}
			bool gioCaoDiem = ((gioVao>=6&&gioVao<=9)||(gioVao>=15&&gioVao<=18));
			double tongTien = 0.0;
			int gioDau = min(thoiGianDo, 2);
			if(gioCaoDiem){
				tongTien=gioDau*(donGia*1.30);
			}
			else{
				tongTien=gioDau*(donGia*0.95);
			}
			if(thoiGianDo>=3){
				tongTien+=(thoiGianDo-2)*(donGia*0.90);
			}
			phiDoXe = tongTien;
		}
		void hienThi() const {
			cout<<"-Xe "<<maXe<<"["<<loaiXe<<"] vao "<<gioVao<<"h "<<"do duoc "<<thoiGianDo<<" h."<<" Phi do xe: "<<phiDoXe<<"\n";
		}
};

class bai_xe{
	private:
		int ma_bai;
		char kich_thuoc;
		Xe pt1, pt2, pt3;
		bool co1, co2, co3;
	public:
		bai_xe(){
			ma_bai=0; kich_thuoc=' ', co1=false, co2=false, co3=false;
		}
		bai_xe(int ma, char kt){
			ma_bai = ma; kich_thuoc = kt; co1=false; co2=false; co3=false;
		}
		int lay_ma() const{return ma_bai;}
		char lay_kich_thuoc() const{return kich_thuoc;}
		bool them(Xe v);
		bool xoa(int ma_xe);
		bool chua(int ma_xe) const;
		void hienThi() const;
		bool co_loai(string loai, int& dem,double& tong) const;
};
bool bai_xe::them(Xe v){
	int cap = (kich_thuoc == 'S')?1:(kich_thuoc == 'M')?2:3;
	if(cap>=1&&!co1){
		pt1 =v; co1=true; return true;
	}
	if(cap>=2&&!co2){
		pt2 =v; co2=true; return true;
	}
	if(cap>=3&&!co3){
		pt3 =v; co3=true; return true;
	}
	return false;
}
bool bai_xe::xoa(int ma_xe){
	if(co1&&pt1.layMaXe() == ma_xe){
		if(co2){
			pt1 = pt2;
			if(co3){
				pt2 = pt3; co3 = false;
			}
			else{
			co2 = false;
			}
		}
		else{
		co1 =false;
		}
		return true;
	}
	if(co2&&pt2.layMaXe() == ma_xe){
		if(co3){
			pt2 = pt3; co3 = false;
		}
		else{
			co2 = false;
		}
		return true;
	}
	if(co3&&pt3.layMaXe() == ma_xe){
		co3 = false;
		return true;
	}
	return false;
}
bool bai_xe::chua(int ma_xe) const{
	if(co1&&pt1.layMaXe() == ma_xe) return true;
	if(co2&&pt2.layMaXe() == ma_xe) return true;
	if(co3&&pt3.layMaXe() == ma_xe) return true;
	return false;
}
void bai_xe::hienThi() const {
	int cap = (kich_thuoc == 'S')?1:(kich_thuoc == 'M')?2:3;
	int so_xe = co1+co2+co3;
	cout<<"Bai "<<ma_bai<<" ["<<kich_thuoc<<"] "<<so_xe<<"/"<<cap<<"xe\n";
	if(co1) pt1.hienThi();
	if(co2) pt2.hienThi();
	if(co3) pt3.hienThi();
}
bool bai_xe::co_loai(string loai, int& dem,double& tong) const {
	dem = 0; tong = 0;
	string loai_chuan = Xe::chuanHoaLoaiXe(loai);
	if(co1&&pt1.layLoaiXe() == loai_chuan){
		++dem; tong += pt1.layPhiDoXe();
	}
	if(co2&&pt2.layLoaiXe() == loai_chuan){
		++dem; tong += pt2.layPhiDoXe();
	}
	if(co3&&pt3.layLoaiXe() == loai_chuan){
		++dem; tong += pt3.layPhiDoXe();
	}
	return dem > 0;
}
class SystemInterface{
	private:
		bai_xe bai1, bai2, bai3;
		bool co1, co2, co3;
	public:
		SystemInterface(){
			co1=false, co2=false, co3=false;
		}
	void runMenu();
};
void SystemInterface::runMenu(){
	int chon;
	while(true){
		cout<<"\n===== QUAN LY BAI DO XE =====\n";
		cout<<"1. Tao bai do\n";
		cout<<"2. Them xe\n";
		cout<<"3. Xoa bai do\n";
		cout<<"4. Lay xe ra\n";
		cout<<"5. Hien thi tat ca bai do\n";
		cout<<"6. Hien thi xe theo bai\n";
		cout<<"7. Liet ke xe theo loai\n";
		cout<<"8. Bao cao phi trung binh\n";
		cout<<"9. Thoat\n";
		cout<<"Chon: ";
		cin>>chon;
		switch(chon){
			case 1:{
				if(co1&&co2&&co3){
				cout<<"Da dat gioi han 3 bai do\n";
				continue;
				}
				int ma; char kt;
				cout<<"Nhap ma bai do: "; cin>>ma;
				if((co1 && bai1.lay_ma() == ma) ||
                   (co2 && bai2.lay_ma() == ma) ||
                   (co3 && bai3.lay_ma() == ma)){
                    cout<<"Ma bai do da ton tai\n";
                    break;
                }
				cout<<"Nhap kich thuoc(S/M/L): "; cin>>kt;
				kt = toupper(kt);
                if(kt!='S' && kt!='M' && kt!='L'){
                    cout<<"Kich thuoc bai khong hop le\n";
                    break;
                }
				if(!co1){
				bai1 = bai_xe(ma, kt); co1 = true;
				}
				else if(!co2){
				bai2 = bai_xe(ma, kt); co2 = true;
				}
				else{
				bai3 = bai_xe(ma, kt); co3 = true;
				}
				cout<<"Tao bai do thanh cong\n";
				break;}
			case 2:{
		        int ma, gio, tg;
		        string loai;
					cout<<"Nhap ma xe: "; cin>>ma;
					if((co1 && bai1.chua(ma)) ||
                       (co2 && bai2.chua(ma)) ||
                       (co3 && bai3.chua(ma))){
                        cout<<"Ma xe da ton tai\n";
                        break;
                    }
					cout<<"Nhap loai xe: "; cin>>loai;
					cout<<"Nhap gio vao: "; cin>>gio;
					if(gio < 0 || gio > 23 || tg <= 0){
                        cout<<"Gio vao hoac thoi gian do khong hop le\n";
                        break;
                    }
					cout<<"Nhap thoi gian do: "	; cin>>tg;
					Xe v(ma, loai, gio, tg);
                    if(!Xe::laLoaiXeHopLe(loai)){
                        cout<<"Loai xe khong hop le\n";
                        break;
                    }
                    v.tinhPhiDoXe();
					bool da_them = false;
					if(co1&& bai1.them(v)) da_them = true;
					else if(co2&& bai2.them(v)) da_them = true;
					else if(co3&& bai3.them(v)) da_them = true;
					if(da_them) cout<<"Them xe thanh cong\n";
					else cout<<"Khong the them xe(bai day hoac khong co bai)\n";
				break;}
			case 3:{
				int ma;
				cout<<"Nhap ma bai do can xoa: ";cin>>ma;
				if(co1&& bai1.lay_ma()==ma){
					co1 = false;
					cout<<"Da xoa bai do\n";
				}
				else if(co2&& bai2.lay_ma()==ma){
					co2 = false;
					cout<<"Da xoa bai do\n";
				}
				else if(co3&& bai3.lay_ma()==ma){
					co3 = false;
					cout<<"Da xoa bai do\n";
				}
				else cout<<"Khong tim thay bai do\n";
				break;}
			case 4:{
				int ma;
				cout<<"Nhap ma xe can lay ra: "; cin>>ma;
				bool da_xoa = false;
				if(co1&& bai1.xoa(ma)) da_xoa  = true;
				else if(co2&& bai2.xoa(ma)) da_xoa  = true;
				else if(co3&& bai3.xoa(ma)) da_xoa  = true;
				if(da_xoa) cout<<"Da lay xe ra khoi bai\n";
				else cout<<"Khong tim thay ma xe\n";
				break;}
			case 5:
				cout<<"\n---DANH SACH BAI DO---\n";
				if(co1) bai1.hienThi();
				if(co2) bai2.hienThi();
				if(co3) bai3.hienThi();
				if(!co1&&!co2&&!co3) cout<<"Chua co bai do nao\n";
				break;
			case 6:{
				int ma;
				cout<<"Nhap ma bai do: "; cin>>ma;
				if(co1&& bai1.lay_ma()==ma){
					bai1.hienThi();
				}
				else if(co2&& bai2.lay_ma()==ma){
					bai2.hienThi();
				}
				else if(co3&& bai3.lay_ma()==ma){
					bai3.hienThi();
				}
				else cout<<"Khong tim thay bai do\n";
				break;}
			case 7:{
				string loai;
				cout<<"Nhap loai xe: "; cin>>loai;
				if(!Xe::laLoaiXeHopLe(loai)){
                    cout<<"Loai xe khong hop le\n";
                    break;
                }
				int dem = 0;
				double phi = 0;
				int d;
				double t;
				if(co1&& bai1.co_loai(loai, d, t)){
					dem += d;
					phi += t;
				}
				if(co2&& bai2.co_loai(loai, d, t)){
					dem += d;
					phi += t;
				}
				if(co3&& bai3.co_loai(loai, d, t)){
					dem += d;
					phi += t;
				}
				cout<<"Tim thay "<<dem<<" xe loai "<<loai<<"\n";
				break;}
			case 8:{
				string ds_loai[3] = {"Car", "Motorcycle", "Bicycle"};
				for(int i=0; i<3; i++){
					int dem = 0;
					double phi = 0;
					int d;
					double t;
					if(co1&& bai1.co_loai(ds_loai[i], d, t)){
						dem += d;
						phi += t;
					}
					if(co2&& bai2.co_loai(ds_loai[i], d, t)){
						dem += d;
						phi += t;
					}
					if(co3&& bai3.co_loai(ds_loai[i], d, t)){
						dem += d;
						phi += t;
					}
					cout<<"loai "<<ds_loai[i]<<": ";
					if(dem > 0) cout<<"Trung binh phi = $"<<fixed<<setprecision(2)<<(phi/dem)<<"\n";
					else cout<<"Khong co xe trong he thong\n";
					}break;
				}
			case 9:
				cout<<"Thoat chuong trinh\n";
				return;
			default:
				cout<<"Lua chon khong hop le";
				break;
		}
	}
}
int main(){
	SystemInterface app;
	app.runMenu();
	return 0;
}
