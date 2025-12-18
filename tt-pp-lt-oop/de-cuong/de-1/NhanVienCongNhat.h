#pragma once
#include "NhanVien.h"

class NhanVienCongNhat : public NhanVien {
 private:
  int        soTienCong;
  static int tienCongNgay;

 public:
  NhanVienCongNhat();
  ~NhanVienCongNhat();
  static void setTienCongNgay(const int& tcn);
  void        nhap();
  void        xuat();
  double      tinhLuong();
};
