#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ThiSinh{
private:
	int sbd, dut;
	string hoten, diachi;
public:
	ThiSinh(int sbd = 0, int dut = 0, string hoten = "", string diachi = ""):
		sbd(sbd), dut(dut), hoten(hoten), diachi(diachi) {}
	void Nhap(){
		cout << "Nhap so bao danh: "; cin >> sbd;
		cout << "Nhap ho va ten: "; cin >> ws; getline(cin, hoten);
		cout << "Nhap dia chi: "; cin >> ws; getline(cin, diachi);
		cout << "Nhap dien uu tien khu vuc: "; cin >> dut;
	}
	void Xuat(){
		cout << "SBD: " << sbd;
		cout << "Ho ten: " << hoten;
		cout << "Dia chi: " << diachi;
		cout << "Dien uu tien khu vuc: " << dut;
	}
};

class KhoiA : public ThiSinh{
private:
	float toan, ly, hoa;
public:
	void Nhap(){
		ThiSinh::Nhap();
		cout << "Nhap diem Toan: "; cin >> toan;
		cout << "Nhap diem Ly: "; cin >> ly;
		cout << "Nhap diem Hoa: "; cin >> hoa;
	}
	void Xuat(){
		ThiSinh::Xuat();
		cout << "Toan: " << toan;
		cout << "Ly: " << ly;
		cout << "Hoa: " << hoa;
	}
};

class KhoiB : public ThiSinh{
private:
	float toan, hoa, sinh;
public:
	void Nhap(){
		ThiSinh::Nhap();
		cout << "Nhap diem Toan: "; cin >> toan;
		cout << "Nhap diem Hoa: "; cin >> hoa;
		cout << "Nhap diem Sinh: "; cin >> sinh;
	}
	void Xuat(){
		ThiSinh::Xuat();
		cout << "Toan: " << toan;
		cout << "Hoa: " << hoa;
		cout << "Sinh: " << sinh;
	}
};

class KhoiC : public ThiSinh{
private:
	float van, su, dia;
public:
	void Nhap(){
		ThiSinh::Nhap();
		cout << "Nhap diem Van: "; cin >> van;
		cout << "Nhap diem Su: "; cin >> su;
		cout << "Nhap diem Dia: "; cin >> dia;
	}
	void Xuat(){
		ThiSinh::Xuat();
		cout << "Van: " << van;
		cout << "Su: " << su;
		cout << "Dia: " << dia;
	}
};

class TuyenSinh{
private:
	vector<ThiSinh*> ts;
	int n;
public:
	void Nhap(){
		cout << "Nhap khoi cua thi sinh/nKhoi A nhap so 1/nKhoi B nhap so 2/nKhoi C nhap so 3";
		cin >> n;
		if(n == '1'){
			ts = new KhoiA;
		}
	}
};

int main(){
	return 0;
}
