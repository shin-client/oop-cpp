#pragma once
#include <iostream>

using namespace std;

const double PI = 3.14;

class HinhTron {
 private:
  float banKinh;

 public:
  void nhap() {
    cout << "Nhap ban kinh: ";
    cin >> banKinh;
  }

  void xuat() const {
    cout << "Ban kinh: " << banKinh << endl;
    cout << "Chu vi: " << tinhChuVi() << endl;
    cout << "Dien tich: " << tinhDienTich() << endl;
  }

  float tinhChuVi() const { return 2 * PI * banKinh; }

  float tinhDienTich() const { return PI * (banKinh * banKinh); }
};
