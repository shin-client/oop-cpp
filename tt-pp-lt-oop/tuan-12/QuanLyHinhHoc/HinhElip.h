#pragma once
#include "HinhHoc.h"

class HinhElip : public HinhHoc {
 protected:
  float banKinhLon;
  float banKinhBe;

 public:
  HinhElip() : banKinhLon(0), banKinhBe(0) {}

  HinhElip(double rLon, double rNho) : banKinhLon(rLon), banKinhBe(rNho) {}

  void nhap() {
    cout << "Nhap hinh Elip\n";
    cout << "Nhap ban kinh lon: ";
    cin >> banKinhLon;
    cout << "Nhap ban kinh be: ";
    cin >> banKinhBe;
  }

  void xuat() const {
    cout << "Chi tiet hinh Elip\n";
    cout << "Ban kinh lon: " << banKinhLon << endl;
    cout << "Ban kinh be: " << banKinhBe << endl;
  }

  double tinhDienTich() const { return PI * banKinhLon * banKinhBe; }
};