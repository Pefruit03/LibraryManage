#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
#define MAX 100
string getName(string name);
struct Sach
{
	string ms;
	string ten;
	string tacgia;
	string nhaxb;
	int namxb;
};
struct QLSach
{
	Sach a[MAX];
	int n = 0;
	void Input()
	{
		ifstream inFile;
		inFile.open("DanhSach.txt");
		if (inFile.is_open())
		{
			while (!inFile.eof())
			{
				getline(inFile, a[n].ms, '-');
				getline(inFile, a[n].ten, '-');
				getline(inFile, a[n].tacgia, '-');
				getline(inFile, a[n].nhaxb, '-');
				//getline(inFile, a[n].namxb, '-');
				inFile >> a[n].namxb;
				inFile.ignore();
				n++;
			}
		}
	}
	void Output()
	{
		//cout << "=========================================================================================================" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << left << setw(7) << a[i].ms << setw(49) << a[i].ten << setw(20) << a[i].tacgia << setw(25) << a[i].nhaxb << setw(15) << a[i].namxb << endl;
		}
	}
	void search_TS(string ten)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i].ten == ten)
				cout << left << setw(7) << a[i].ms << setw(49) << a[i].ten << setw(20) << a[i].tacgia << setw(25) << a[i].nhaxb << setw(15) << a[i].namxb << endl;
		}
	}
	void search_MS(string ms)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i].ms == ms)
				cout << left << setw(7) << a[i].ms << setw(49) << a[i].ten << setw(20) << a[i].tacgia << setw(25) << a[i].nhaxb << setw(15) << a[i].namxb << endl;
		}
	}
	// Sap xep theo ten
	void sortTheoTen(Sach a[], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				// Lay ho ten tac gia de hoan vi
				string tentg1 = getName(a[i].tacgia);
				string tentg2 = getName(a[j].tacgia);
				if (tentg1 > tentg2)
					swap(a[i], a[j]);
			}
	}
	void sortTheoNXB(Sach a[], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].nhaxb > a[j].nhaxb)
					swap(a[i], a[j]);
			}
	}
	void themVaoFile(Sach s)
	{
		ofstream outFile;
		outFile.open("List.txt", ios::app);
		if (outFile.is_open())
		{
			outFile << "\n" << s.ms << "-" << s.ten << "-" << s.tacgia << "-" << s.nhaxb << "-" << s.namxb;
		}
	}
	/*void xoaHangCuoi(Sach s)
	{
		ofstream outFile;
		outFile.open("List.txt", ios::app);
		
	}*/
	void themSach()
	{
		Sach sach;
		bool check = false;
		while (check == false)
		{
			cout << "Ma sach: ";
			getline(cin, sach.ms);
			for (int i = 0; i < n; i++)
			{
				if (sach.ms == a[i].ms)
				{
					cout << "Trung ma sach!\nNhap lai!\n";
					check = false;
					break;
				}
				else
				{
					check = true;
				}
			}
		}
		cout << "Ten sach: ";
		getline(cin, sach.ten);
		cout << "Tac gia: ";
		getline(cin, sach.tacgia);
		cout << "Nha xuat ban: ";
		getline(cin, sach.nhaxb);
		cout << "Nam xuat ban: ";
		cin >> sach.namxb;
		a[n] = sach;
		n++;
		themVaoFile(sach);
	}
	void sortTheoTenSach(Sach a[], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].ten > a[j].ten)
					swap(a[i], a[j]);
			}
	}
	void sortTheoNamGiam(Sach a[], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].namxb < a[j].namxb)
					swap(a[i], a[j]);
			}
	}
	void replaceText()
	{
		ofstream outFile;
		outFile.open("List.txt");
		if (outFile.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				outFile << a[i].ms << "-" << a[i].ten << "-" << a[i].tacgia << "-" << a[i].nhaxb << "-" << a[i].namxb;
				if (i < n - 1)
				{
					outFile << "\n";
				}
			}
		}
	}
	bool xoaTheoMaSach(string ms)
	{
		if (n == 0) return false;
		else
		{
			int vitri = 0;
			bool found = false;
			for (int i = 0; i < n; i++)
			{
				if (ms == a[i].ms)
				{
					vitri = i;
					found = true;
					break;
				}
			}
			if (!found)
			{
				return false;
			}
			for (int i = vitri; i < n; i++)
			{
				a[i].ms = a[i + 1].ms;
				a[i].ten = a[i + 1].ten;
				a[i].tacgia = a[i + 1].tacgia;
				a[i].nhaxb = a[i + 1].nhaxb;
				a[i].namxb = a[i + 1].namxb;
			}
			n--;
			replaceText();
			return true;
		}
	}
	void xoaAllByAuthorName(string tg)
	{
		for (int i = 0; i < n; i++)
		{
			while (tg == a[i].tacgia)
			{
				xoaTheoMaSach(a[i].ms);
			}
		}
	}
	void inSLGiamDanTheoNhaXB()
	{
		// khoi tao 2 mang song song 
		// mang arrNXB chua ten cac nha xuat ban
		string arrNXB[MAX];
		// mang arrDem chua so luong sach cong dan tuong ung voi vi tri nha xuat ban
		int arrDem[MAX] = { 0 };
		int arrS = 0;
		for (int i = 0; i < n; i++)
		{
			bool found = false;
			string nxb = a[i].nhaxb;
			for (int j = 0; j < arrS; j++)
			{
				// neu nxb co trong mang arrNXB
				if (nxb == arrNXB[j])
				{
					found = true;
					arrDem[j]++;
					break;
				}
			}
			// neu ko tim duoc nxb trong mang arrNXB thi them phan tu moi vao mang arrNXB
			if (!found)
			{
				arrNXB[arrS] = nxb;
				arrDem[arrS]++;
				arrS++;
			}
			
		}
		bool sorted = false; // mang chua sap xep xong
		int startPos = 0;
		while (!sorted)
		{
			int maxPos = 0;
			int max = arrDem[0];
			for (int i = 0; i < arrS; i++) // tim gia tri lon nhat trong mang arrDem
			{
				
				if (max < arrDem[i])
				{
					max = arrDem[i];
					maxPos = i;
				}
			}
			arrDem[maxPos] = 0;
			
			if (max == 0) // Khi arrDem toan bo la 0 thi dung sap xep
			{
				sorted = true;
				continue;
			}
			for (int i = startPos; i < n; i++) //sap xep phan tu
			{
				if (arrNXB[maxPos] == a[i].nhaxb )
				{
					swap(a[startPos], a[i]);
					startPos++;
				}
			}
		}
	}
};
void swap(Sach& a, Sach& b)
{
	Sach temp = a;
	a = b;
	b = temp;
}
// ham lay ten tu ho ten
string getName(string name) 
{
	// khoi tao stack
	string arr[10];
	int n = -1;
	// khoi tao string kieu c va lay du lieu tu param
	char* c_name  = new char;
	strcpy(c_name, name.c_str());
	// cat chuoi thanh chu cach nhau boi dau cach
	char* token = strtok(c_name, " ");
	while (token != NULL)
	{
		arr[++n] = token;
		token = strtok(NULL, " ");
	}
	// n la phan tu dau stack -> ten tac gia
	return arr[n];
}