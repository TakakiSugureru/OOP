#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class SinhVien
{
public:
	int MaSo;
	string HoTen;
	float TKLG, LTHDT, KTMT;
	float DTB;

public:
	SinhVien(int MaSo,string HoTen,float TKLG,float LTHDT, float KTMT)
	{
		this->MaSo= MaSo;
		this->HoTen=HoTen;
		this->TKLG=TKLG;
		this->LTHDT=LTHDT;
		this->KTMT=KTMT;
		this->DTB = TinhTrungBinh();
	}

	SinhVien()
	{
		this->MaSo=0;
		this->HoTen="";
		this->TKLG=-1;
		this->LTHDT=-1;
		this->KTMT=-1;
		this->DTB = TinhTrungBinh();
	}
//*******************************************************************************************************************************************************************

	void nhap() 
	{
		cout << "Ma so sinh vien:";
		cin >> MaSo;
		cout << "Ho va Ten:";
		cin.ignore();
		getline(cin, HoTen);
		cout << "Thiet ke logic:";
		cin >> TKLG;
		cout << "Lap trinh huong doi tuong:";
		cin >> LTHDT;
		cout << "Kien truc may tinh:";
		cin >> KTMT;
		DTB = TinhTrungBinh();
	}

	void xuat() 
	{
		cout << "\n\nMa so sinh vien:" << MaSo;
		cout << "\nHo va Ten:" << HoTen;
		cout << "\nThiet ke logic:" << TKLG;
		cout << "\nLap trinh huong doi tuong:" << LTHDT;
		cout << "\nKien truc may tinh:" << KTMT;
		cout << "\nDiem trung binh:" << DTB;
	}

	float TinhTrungBinh()
	{
		return (LTHDT+TKLG+KTMT)/3;
	}

//*******************************************************************************************************************************************************************

	void xuatfile(ofstream &file)
	{
		file << MaSo << "\n";
		file << HoTen << "\n";
		file << TKLG << "\n";
		file << LTHDT << "\n";
		file << KTMT << "\n";
		file << DTB << "\n";
	}

	void docfile(ifstream &file)
	{
		file >> MaSo;
		file.ignore();
		getline(file,HoTen);
		file >> TKLG ;
		file >> LTHDT ;
		file >> KTMT;
		file >> DTB;
	}

		
	friend istream& operator >> (istream& is, SinhVien &sv)
	{
		sv.nhap();
		return is;
	}

	friend ostream& operator << (ostream& os, SinhVien &sv)
	{
		sv.xuat();
		return os;
	}
};

//*******************************************************************************************************************************************************************

class SinhVienDaiTra : public SinhVien
{
public:
	float PPTinh, Bus, VLSI;
	float DTB;

public:
	void nhap() 
	{
		SinhVien::nhap();
		cout << "Phuong phap tinh:";
		cin >> PPTinh;
		cout << "Kien truc bus:";
		cin >> Bus;
		cout << "Thiet ke VLSI:";
		cin >> VLSI;
		DTB = TinhTrungBinh();
	}

	void xuat() 
	{
		cout << MaSo <<"\t" <<HoTen<<"\t"<<TKLG<<"\t"<<LTHDT<<"\t"<<KTMT<<"\t"<<PPTinh<<"\t"<<Bus<<"\t"<<VLSI<<"\t"<<DTB;
	}

	float TinhTrungBinh()
	{
		return (LTHDT+TKLG+KTMT+PPTinh+Bus+VLSI)/6;
	}

	void xuatfile(ofstream &file)
	{
		file << MaSo << "\n";
		file << HoTen << "\n";
		file << TKLG << "\n";
		file << LTHDT << "\n";
		file << KTMT << "\n";
		file << PPTinh << "\n";
		file << Bus << "\n";
		file << VLSI << "\n";
		file << DTB << "\n";
	}

	void docfile(ifstream &file)
	{
		file >> MaSo;
		file.ignore();
		getline(file,HoTen);
		file >> TKLG ;
		file >> LTHDT ;
		file >> KTMT;
		file >> PPTinh;
		file >> Bus;
		file >> VLSI;
		file >> DTB;
		//DTB = TinhTrungBinh();
	}

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class SinhVienCLC : public SinhVien
{
public:
	float DSP, Nano;
	float DTB;

public:
	void nhap() 
	{
		SinhVien::nhap();
		cout << "DSP:";
		cin >> DSP;
		cout << "Cong nghe Nano:";
		cin >> Nano;
		DTB = TinhTrungBinh();
	}

	void xuat() 
	{
		cout << MaSo <<"\t" <<HoTen<<"\t"<<TKLG<<"\t"<<LTHDT<<"\t"<<KTMT<<"\t"<<DSP<<"\t"<<Nano<<"\t"<<DTB;
	}

	float TinhTrungBinh()
	{
		return (LTHDT+TKLG+KTMT+(DSP*2)+(Nano*2))/7;
	}

	void xuatfile(ofstream &file)
	{
		file << MaSo << "\n";
		file << HoTen << "\n";
		file << TKLG << "\n";
		file << LTHDT << "\n";
		file << KTMT << "\n";
		file << DSP << "\n";
		file << Nano << "\n";
		file << DTB << "\n";
	}

	void docfile(ifstream &file)
	{
		file >> MaSo;
		file.ignore();
		getline(file,HoTen);
		file >> TKLG ;
		file >> LTHDT ;
		file >> KTMT;
		file >> DSP;
		file >> Nano;
		file >> DTB;
		//DTB = TinhTrungBinh();
	}
};

//*******************************************************************************************************************************************************************
class MENU
{
public:
	vector <SinhVien *> sv;
	int SiSo, SiSoCLC, SiSoDaiTra;

public:
	void nhapDS()
	{
		cout << "Nhap so sv CLC:";
		cin >> SiSoCLC;
		cout << "Nhap so sv dai tra:";
		cin >> SiSoDaiTra;
		SiSo = SiSoCLC + SiSoDaiTra;
		sv.resize(SiSo);
		
		for (int i=0; i<SiSoCLC; i++)  sv[i] = new SinhVienCLC;
		for (int i=SiSoCLC; i<SiSo; i++)  sv[i] = new SinhVienDaiTra;
		
		for (int i=0; i<SiSo; i++)  sv[i]->nhap();
	}

	void xuatDS()
	{
		for (int i=0; i<sv.size(); i++)
		{
			sv[i]->xuat();
			cout << "\n";
		}
		cout << "\n\n";
		cout << "\n\n\n";
		system("pause");
	}

	void inMenu()
	{
		char option;
		do
		{
			system("cls");
			cout << "\n===== MENU =====";
			cout << "\n1. Nhap danh sach";
			cout << "\n2. Xuat danh sach";
			cout << "\n3. Ghi danh sach ra file";
			cout << "\n4. Doc danh sach tu file";
			cout << "\n5. Thoat";
			cout << "\nNhap lua chon:";
			cin >> option;
			switch (option)
			{
				case '1':  nhapDS();   break;
				case '2':  xuatDS();   break;
				case '3':  GhiDS();   break;
				case '4':  DocDS();   break;		
			}
		} while(option!='5');
	}

	void GhiDS()
	{
		ofstream file;
		file.open("d:\\danhsach.txt");
		if (file.is_open())
		{
			file << sv.size() << "\n";

			for(int i=0; i<sv.size(); i++)
			{ 
				sv[i]->xuatfile(file);
			}
			cout<<"Da ghi xong!!!\n";
			file.close();
		}
		else cout << "Khong mo duoc file!!!\n";
		system("pause");
	}

	void DocDS()
	{
		ifstream file; int n_sv;
		file.open("d:\\danhsach.txt");
		if (file.is_open())
		{
			file >> n_sv;
			sv.resize(n_sv);
			for(int i=0; i<n_sv; i++)
			{ 
				sv[i]->docfile(file);
			}
			cout<<"Da doc xong!!!\n";
			file.close();
		}
		else cout << "Khong mo duoc file!!!\n";
		system("pause");
	}
};

//*******************************************************************************************************************************************************************

int main()
{
	MENU menu1;
	menu1.inMenu();
	return 0;
}
