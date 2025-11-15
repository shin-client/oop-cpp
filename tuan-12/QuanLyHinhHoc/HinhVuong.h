#pragma once
#include "HinhChuNhat.h"

class HinhVuong : public HinhChuNhat {
 public:
  HinhVuong() : HinhChuNhat() {}

  HinhVuong(float canh) : HinhChuNhat(canh, canh) {}

  void nhap() {
    cout << "Nhap hinh vuong\n";
    cout << "Nhap canh: ";
    cin >> chieuDai;
    chieuRong = chieuDai;
  }

  void xuat() const {
    cout << "Chi tiet hinh vuong\n";
    cout << "Canh: " << chieuDai << endl;
  }
};