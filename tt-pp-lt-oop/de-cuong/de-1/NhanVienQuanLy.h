#pragma once
#include "NhanVien.h"

class NhanVienQuanLy : public NhanVien {
 private:
  float      heSoLuong;
  static int luongCoBan;

 public:
  NhanVienQuanLy();
  ~NhanVienQuanLy();
  static void setLuongCoBan(const int &lcb);
  void        nhap();
  void        xuat();
  double      tinhLuong();
};
