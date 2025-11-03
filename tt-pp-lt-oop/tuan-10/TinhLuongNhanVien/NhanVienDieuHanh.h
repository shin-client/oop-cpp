#pragma once
#include "NhanVienVanPhong.h"

class NhanVienDieuHanh : public NhanVienVanPhong {
 private:
  float phuCap;

 public:
  void nhap() {
    NhanVienVanPhong::nhap();
    cout << "Nhap phu cap: ";
    cin >> phuCap;
  }

  void xuat() {
    NhanVienVanPhong::xuat();
    cout << "Phu cap: " << phuCap << endl;
  }

  float tinhLuong() { return NhanVienVanPhong::tinhLuong() + phuCap; }
};
