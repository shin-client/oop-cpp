#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"

int main() {
	NhanVien* nv = nullptr;

	int loaiNhanVien;
	cout << "Nhap loai nhan vien: 0:Van phong, 1: San xuat\n";
	cin >> loaiNhanVien;

	if (loaiNhanVien == 0) nv = new NhanVienVanPhong();
	else if (loaiNhanVien == 1) nv = new NhanVienSanXuat();

	nv->nhap();
	nv->xuat();

	float luong = nv->tinhLuong();
	cout << "Luong: " << luong << endl;

	return 0;
}
