#include "NhanVienCongNhat.h"

NhanVienCongNhat::NhanVienCongNhat() : NhanVien(), soTienCong(0) {}

NhanVienCongNhat::~NhanVienCongNhat() {}

void NhanVienCongNhat::setTienCongNgay(const int &tcn) { tienCongNgay = tcn; }

void NhanVienCongNhat::nhap() {
  NhanVien::nhap();
  cout << "Nhap so tien cong: ";
  cin >> soTienCong;
}

void NhanVienCongNhat::xuat() {
  NhanVien::xuat();
  cout << "So tien cong: " << soTienCong << endl;
}

double NhanVienCongNhat::tinhLuong() { return soTienCong * tienCongNgay; }
