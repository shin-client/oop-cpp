#pragma once
#include "HinhElip.h"

class HinhTron : public HinhElip {
 public:
  HinhTron() : HinhElip() {}

  HinhTron(double banKinh) : HinhElip(banKinh, banKinh) {}

  void nhap() {
    cout << "Nhap hinh tron\n";
    cout << "Nhap ban kinh: ";
    cin >> banKinhLon;
    banKinhBe = banKinhLon;
  }

  void xuat() const {
    cout << "Chi tiet hinh tron\n";
    cout << "Ban kinh: " << banKinhLon << endl;
  }

  double tinhDienTich() const { return PI * banKinhLon * banKinhBe; }
};