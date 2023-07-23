#include <iostream>
#include <vector>

using namespace std;

class SV{
private:
	int MSSV;
	string Ten;
	float DTB, LG, OOP, KTMT;
public:
	SV(int MSSV = 0, string Ten = "", float DTB = -1, float LG = -1, float OOP = -1, float KTMT = -1):
		MSSV(MSSV), Ten(Ten), DTB(DTB), LG(LG), OOP(OOP), KTMT(KTMT) {
		}
	virtual void Nhap(){
		cout << "Nhap MSSV: "; cin >> MSSV;
		cout << "Nhap Ho va ten: "; cin >> ws; getline(cin, Ten);
		cout << "Nhap diem Logic: "; cin >> LG;
		cout << "Nhap diem OOP: "; cin >> OOP;
		cout << "Nhap diem KTMT: "; cin >> KTMT;
		DTB = DiemTB();
	}
	virtual void Xuat(){
		cout << "MSSV: " << MSSV << endl;
		cout << "Ho va ten: " << Ten << endl;
		cout << "Logic: " << LG << endl;
		cout << "OOP: " << OOP << endl;
		cout << "KTMT: " << KTMT << endl;
		cout << "Diem trung binh: " << DTB << endl;
	}
	float DiemTB (){
		return (LG+OOP+KTMT)/3;
	}
//===================================================================================
	int getOOP (){
		return this->OOP;
	}
	int getLG (){
		return this->LG;
	}
	int getKTMT (){
		return this->KTMT;
	}
	void setOOP (float OOP){
		this->OOP = OOP;
	}
	void setLG (float LG){
		this->LG = LG;
	}
	void setKTMT (float KTMT){
		this->KTMT = KTMT;
	}
	
//===================================================================================
//Nap chong toan tu
	friend istream& operator >> (istream &is, SV &sv){
		sv.Nhap();
		return is;
	}
	friend ostream& operator << (ostream &os, SV &sv){
		sv.Xuat();
		return os;
	}
};

//===================================================================================
class SVDT: public SV{
private:
	float DTB, PPT, BUS, VLSI;
public:
	void Nhap(){
		SV::Nhap();
		cout << "Nhap diem PPT: "; cin >> PPT;
		cout << "Nhap diem BUS: "; cin >> BUS;
		cout << "Nhap diem VLSI: "; cin >> VLSI;
		DTB = DiemTB();
	}
	void Xuat(){
		SV::Xuat();
		cout << "Diem PPT: " << PPT << endl;
		cout << "Diem BUS: " << BUS << endl;
		cout << "Diem VLSI: " << VLSI << endl;
	}
	float DiemTB(){
		return (getOOP()+getLG()+getKTMT()+PPT+BUS+VLSI)/6;
	}
};

class SVCLC: public SV{
private:
	float DTB, DSP, NANO;
public:
	void Nhap(){
		SV::Nhap();
		cout << "Nhap diem DSP: "; cin >> DSP;
		cout << "Nhap diem NANO: "; cin >> NANO;
		DTB = DiemTB();
	}
	void Xuat(){
		SV::Xuat();
		cout << "Diem DSP: " << DSP << endl;
		cout << "Diem NANO: " << NANO << endl;
	}
	float DiemTB(){
		return (getOOP()+getLG()+getKTMT()+(DSP*2)+(NANO*2))/7;
	}
};

//===================================================================================
class MENU{
private:
	vector <SV *> sv;
	int SS, SSDT, SSCLC;
public:
	void NhapDS(){
		cout << "Nhap si so SV dai tra: "; cin >> SSDT;
		cout << "Nhap si so SV clc: "; cin >> SSCLC;
		SS = SSDT + SSCLC;
		sv.resize(SS);
		
		for(int i = 0; i < SSCLC; i++) sv[i] = new SVDT;
		for(int i = SSCLC; i < SS; i++) sv[i] = new SVCLC;
		
		for(int i = 0; i < SS; i++) sv[i]->Nhap();
	}
	void XuatDS(){
		for(int i = 0; i < sv.size(); i++){
			sv[i]->Xuat();
			cout << "\n";
		}
		cout << "\n\n";
		cout << "\n\n\n";
		system("pause");
	}	 
	void inMENU(){
		char op;
		do{
			system("cls");
			cout << "\n===== MENU =====";
			cout << "\n1. Nhap danh sach";
			cout << "\n2. Xuat danh sach";
			cout << "\n3. Thoat";
			cout << "\nNhap lua chon:";
			cin >> op;
			switch (op){
				case '1': NhapDS(); break;
				case '2': XuatDS(); break;
			}
		} while(op != '3');
	}
};

int main(){
	MENU a;
	a.inMENU();
	return 0;
}
