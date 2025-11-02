#pragma once
#include "DichVu.h"

class DichVuDienThoai : public DichVu {
private:
	int soPhutGoi;
	string loaiCuocGoi;
	const double GIA_TRONG_NUOC = 1000;
	const double GIA_NGOAI_NUOC = 10000;
public:
    DichVuDienThoai(int phut, string loai)
        : DichVu("Dien thoai"), soPhutGoi(phut), loaiCuocGoi(loai) {}

	void xuat() const {
		DichVu::xuat();
		cout << "Loai cuoc goi: " << loaiCuocGoi << endl;
		cout << "So phut goi: " << soPhutGoi << endl;
	}

	float tinhTien() const {
		if (loaiCuocGoi == "trong nuoc") return soPhutGoi * GIA_TRONG_NUOC;
		else if (loaiCuocGoi == "ngoai nuoc") return soPhutGoi * GIA_NGOAI_NUOC;
	}
};
