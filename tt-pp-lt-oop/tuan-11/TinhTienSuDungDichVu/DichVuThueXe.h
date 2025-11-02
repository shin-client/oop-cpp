#pragma once
#include "DichVu.h"

class DichVuThueXe : public DichVu {
private:
	string loaiThue;
	int thoiGianSuDung;
	const double GIA_THUE_GIO = 100000;
	const double GIA_THUE_NGAY = 800000;
public:
	DichVuThueXe(int thoiGian, string loai) : DichVu("Thue xe"), thoiGianSuDung(thoiGian), loaiThue(loai) {}

	void xuat() const {
		DichVu::xuat();
		cout << "Loai thue: " << loaiThue << endl;
		cout << "Thoi gian su dung: " << thoiGianSuDung << endl;
	}

	float tinhTien() const {
		if (loaiThue == "gio") return thoiGianSuDung * GIA_THUE_GIO;
		else if (loaiThue == "ngay") return thoiGianSuDung * GIA_THUE_NGAY;
	}
};

