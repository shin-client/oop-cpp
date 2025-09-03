#pragma once
#include <iostream>

using namespace std;

class HinhChuNhat {
 private:
  float chieuDai;
  float chieuRong;

 public:
  void nhap() {
    cout << "Nhap chieu dai: ";
    cin >> chieuDai;
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;
  }

  void xuat() const {
    cout << "Chieu dai: " << chieuDai << endl;
    cout << "Chieu rong: " << chieuRong << endl;
    cout << "Chu vi: " << tinhChuVi() << endl;
    cout << "Dien tich: " << tinhDienTich() << endl;
  }

  float tinhChuVi() const { return (chieuDai + chieuRong) * 2; }

  float tinhDienTich() const { return chieuDai * chieuRong; }
};
