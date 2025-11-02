#pragma once
#include "NhanVien.h"

const int DON_GIA_1_SAN_PHAM = 1000;

class NhanVienSanXuat : public NhanVien {
private:
	int soSanPham;
public:
	void nhap() {
		NhanVien::nhap();
		cout << "Nhap so san pham: ";
		cin >> soSanPham;
	}

	void xuat() {
		NhanVien::xuat();
		cout << "So san pham: " << soSanPham << endl;
	}

	float tinhLuong() {
		return soSanPham * DON_GIA_1_SAN_PHAM;
	}
};
