#include<iostream>
#include<iomanip>
#include"DanhSach.h"
using namespace std;

void Menu();

int main()
{
	//system("color 0B");
	Menu();
	return 0;
}

void Menu()
{
	QLSach ds;
	char choose;

	do {
		cout << "=============================================MENU================================================" << endl;
		cout << "**	a. Nhap muc sach tu file du lieu                                                         **" << endl;
		cout << "**	b. Tim kiem, in thong tin mot quyen sach theo ma sach, ten sach                          **" << endl;
		cout << "**	c. In danh muc sach theo ten tac gia                                                     **" << endl;
		cout << "**	d. In danh muc sach theo nha xuat ban                                                    **" << endl;
		cout << "**	e. Them mot quyen sach (co kiem tra ma sach khong duoc trung)                            **" << endl;
		cout << "**	f. Xoa mot quyen sach theo ma sach                                                       **" << endl;
		cout << "**	g. Xoa tat ca cac quyen sach cua mot tac gia                                             **" << endl;
		cout << "**	h. In danh muc sach theo ten sach tang dan                                               **" << endl;
		cout << "**	i. In danh muc sach theo nam xuat ban giam dan                                           **" << endl;
		cout << "**	j. In danh sach                                                                          **" << endl;
		cout << "**	k. In danh sach thong ke so luong sach theo tung nha xuat ban voi so luong giam dan      **" << endl;
		cout << "**	l. Thoat                                                                                 **" << endl;
		cout << "=================================================================================================" << endl;
		cout << "\nChon: ";
		choose = 'l';
		cin >> choose;
		switch (choose)
		{
		case 'a':
			ds.Input();
			cout << "Nhap du lieu sach thanh cong!\n";
			ds.Output();
			break;
		case 'b':
			int c;
			do {
				cout << "Chon tim theo ten sach hoac tim theo ma sach:\n";
				cout << "1.Ten sach\n";
				cout << "2.Ma sach\n";
				cout << "Chon: ";
				cin >> c;
				cin.ignore();
				if (c == 1)
				{
					string ten;
					cout << "Nhap ten sach: ";
					getline(cin, ten);
					ds.search_TS(ten);
				}
				else if (c == 2)
				{
					string masach;
					cout << "Nhap ma sach: ";
					getline(cin, masach);
					ds.search_MS(masach);
				}
				else
					cout << "Lua chon khong hop le!\n";
			} while (c != 1 && c!= 2);
			break;
		case 'c':
			cout << "In danh sach theo ten tac gia: \n";
			ds.sortTheoTen(ds.a, ds.n);
			ds.Output();
			break;
		case 'd':
			cout << "In danh sach theo nha xuat ban: \n";
			ds.sortTheoNXB(ds.a, ds.n);
			ds.Output();
			break;
		case 'e':
			cin.ignore();
			cout << "Nhap thong tin sach moi: \n";
			ds.themSach();
			ds.Output();
			break;
		case 'f':
		{
			cin.ignore();
			string ms;
			cout << "Ma sach muon xoa: ";
			getline(cin, ms);
			if (ds.xoaTheoMaSach(ms))
				cout << "Xoa thanh cong!\n";
			else
				cout << "Xoa khong thanh cong!\n";
			ds.Output();
			break;
		}
		case 'g':
		{
			cin.ignore();
			string tg;
			cout << "Nhap ten tac gia: ";
			getline(cin, tg);
			ds.xoaAllByAuthorName(tg);
			ds.Output();
		}
			break;
		case 'h':
			cout << "In danh sach theo ten sach tang dan: \n";
			ds.sortTheoTenSach(ds.a, ds.n);
			ds.Output();
			break;
		case 'i':
			cout << "In danh sach theo nam xuat ban giam dan: \n";
			ds.sortTheoNamGiam(ds.a, ds.n);
			ds.Output();
			break;
		case 'j':
			
			ds.Output();
			break;
		case 'k':
			ds.inSLGiamDanTheoNhaXB();
			ds.Output();
			break;
		case 'l':
			return;
		default:
			cout << "Ko ton tai chuc nang nay!\n";
			choose = 'l';
			break;
		}
		system("pause");
		system("cls");
	} while (choose >= 'a' && choose < 'm');
}