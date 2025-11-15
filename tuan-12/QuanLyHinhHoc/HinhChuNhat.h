#pragma once
#include "HinhHoc.h"

class HinhChuNhat : public HinhHoc {
 protected:
  float chieuDai;
  float chieuRong;

 public:
  HinhChuNhat() : chieuDai(0), chieuRong(0) {}

  HinhChuNhat(float d, float r) : chieuDai(d), chieuRong(r) {}

  void nhap() {
    cout << "Nhap hinh chu nhat\n";
    cout << "Nhap chieu dai: ";
    cin >> chieuDai;
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;
  }

  void xuat() const {
    cout << "Chi tiet hinh chu nhat\n";
    cout << "Chieu dai: " << chieuDai << endl;
    cout << "Chieu rong: " << chieuRong << endl;
  }

  double tinhDienTich() const { return chieuDai * chieuRong; }
};