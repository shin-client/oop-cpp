#pragma once
#include <iostream>

using namespace std;

class HinhChuNhat {
 private:
  float chieuDai;
  float chieuRong;

 public:
  HinhChuNhat() : chieuDai(0), chieuRong(0) {}

  HinhChuNhat(float chieuDai, float chieuRong) : chieuDai(chieuDai), chieuRong(chieuRong) {}

  ~HinhChuNhat() { cout << "Ham huy da duoc goi!\n"; }

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

  friend istream& operator>>(istream& in, HinhChuNhat& hcn) {
    cout << "Nhap chieu dai: ";
    in >> hcn.chieuDai;
    cout << "Nhap chieu rong: ";
    in >> hcn.chieuRong;
    return in;
  }

  friend ostream& operator<<(ostream& out, const HinhChuNhat& hcn) {
    cout << "Chieu dai: " << hcn.chieuDai << endl;
    cout << "Chieu rong: " << hcn.chieuRong << endl;
    return out;
  }

  float tinhChuVi() const { return (chieuDai + chieuRong) * 2; }

  float tinhDienTich() const { return chieuDai * chieuRong; }
};