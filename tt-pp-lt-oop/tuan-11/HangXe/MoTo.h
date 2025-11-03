#pragma once

#include <iostream>

using namespace std;

class MoTo {
 private:
  string soMay;
  string nhaSanXuat;
  int    phanKhoi;

 public:
  MoTo() : soMay(""), nhaSanXuat(""), phanKhoi(0) {}

  MoTo(const string& sm, const string& nsx, const int& pk)
  : soMay(sm), nhaSanXuat(nsx), phanKhoi(pk) {}

  ~MoTo() {}

  string getSoMay() const { return soMay; }

  string getNhaSanXuat() const { return nhaSanXuat; }

  int getPhanKhoi() const { return phanKhoi; }

  void setSoMay(const string& sm) { soMay = sm; }

  void setNhaSanXuat(const string& nsx) { nhaSanXuat = nsx; }

  void setPhanKhoi(const int& pk) { phanKhoi = pk; }

  friend istream& operator>>(istream& in, MoTo& mt) {
    cout << "Nhap so may: ";
    in >> mt.soMay;
    cout << "Nhap nha san xuat: ";
    in >> mt.nhaSanXuat;
    cout << "Nhap phan khoi: ";
    in >> mt.phanKhoi;

    return in;
  }

  friend ostream& operator<<(ostream& out, MoTo& mt) {
    cout << "So may: " << mt.soMay << endl;
    cout << "Nha san xuat: " << mt.nhaSanXuat << endl;
    cout << "Phan khoi: " << mt.phanKhoi << endl;

    return out;
  }

  bool operator>(MoTo mt) { return phanKhoi > mt.phanKhoi; }

  bool operator>=(MoTo mt) { return phanKhoi >= mt.phanKhoi; }

  bool operator<(MoTo mt) { return phanKhoi < mt.phanKhoi; }

  bool operator<=(MoTo mt) { return phanKhoi <= mt.phanKhoi; }
};