#pragma once
#include <iostream>
#include <string>

using namespace std;

class NhanVien {
protected:
	string maNhanVien;
	string hoTen;
public:
	virtual void nhap() {
		cin.ignore();
		cout << "Nhap ma nhan vien: ";
		getline(cin, maNhanVien);
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
	}

	virtual void xuat() {
		cout << "Ma: " << maNhanVien << endl;
		cout << "Ho ten: " << hoTen << endl;
	}

	virtual float tinhLuong() = 0;
};
