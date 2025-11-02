#pragma once
#include "NhanVien.h"

const int GIA_1_NGAY = 200;

class NhanVienVanPhong : public NhanVien {
private:
	int soNgayCong;
public:
	void nhap() {
		NhanVien::nhap();
		cout << "Nhap so ngay cong: ";
		cin >> soNgayCong;
	}

	void xuat() {
		NhanVien::xuat();
		cout << "So ngay cong: " << soNgayCong << endl;
	}

	float tinhLuong() {
		return soNgayCong * GIA_1_NGAY;
	}
};
