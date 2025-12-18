#pragma once
#include <iostream>
#include <string>

using namespace std;

class NhanVien {
  protected:
  string hoTen;
  int namSinh;
  string diaChi;
  string sdt;

  public:
  NhanVien();
  virtual ~NhanVien();
  virtual void nhap();
  virtual void xuat();
  virtual double tinhLuong() = 0;
};
