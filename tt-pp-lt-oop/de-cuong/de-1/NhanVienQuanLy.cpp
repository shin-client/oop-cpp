#include "NhanVienQuanLy.h"

NhanVienQuanLy::NhanVienQuanLy() : NhanVien(), heSoLuong(0) {}

NhanVienQuanLy::~NhanVienQuanLy() {}

void NhanVienQuanLy::setLuongCoBan(const int &lcb) { luongCoBan = lcb; }

void NhanVienQuanLy::nhap() {
  NhanVien::nhap();
  cout << "Nhap he so luong: ";
  cin >> heSoLuong;
}

void NhanVienQuanLy::xuat() {
  NhanVien::xuat();
  cout << "He so luong: " << heSoLuong << endl;
}

double NhanVienQuanLy::tinhLuong() { return luongCoBan * heSoLuong; }
