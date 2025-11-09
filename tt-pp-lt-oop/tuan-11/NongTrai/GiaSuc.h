#pragma once
#include <iostream>

using namespace std;

class GiaSuc {
 protected:
  string maSo;
  float  canNang;
  int    tuoi;

 public:
  GiaSuc() : maSo("N/A"), canNang(0.0), tuoi(0) {}

  GiaSuc(const string &ms, const float &cn, const int &t)
      : maSo(ms), canNang(cn), tuoi(t) {}

  virtual ~GiaSuc() {}

  string getMaSo() const { return maSo; }

  float getCanNang() const { return canNang; }

  int getTuoi() const { return tuoi; }

  void setMaSo(const string &ms) { maSo = ms; }

  void setCanNang(const float &cn) { canNang = cn; }

  void setTuoi(const int &t) { tuoi = t; }

  void nhap() {
    cout << "Nhap ma so: ";
    cin >> maSo;
    cout << "Nhap can nang: ";
    cin >> canNang;
    cout << "Nhap tuoi: ";
    cin >> tuoi;
  }

  void xuat() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Can nang: " << canNang << "KG\n";
    cout << "Tuoi: " << tuoi << " nam\n";
  }

  virtual float tinhLuongSua() = 0;
};
