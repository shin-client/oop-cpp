#pragma once
#include <iostream>
#include <string>

using namespace std;

class BaoVe {
 protected:
  string maBaoVe;
  string hoTen;
  string diaChi;

 public:
  BaoVe() : maBaoVe(""), hoTen(""), diaChi("") {}

  BaoVe(const string &mabv, const string &ht, const string &dc)
      : maBaoVe(mabv), hoTen(ht), diaChi(dc) {}

  virtual ~BaoVe() {}

  string getMaBaoVe() const { return maBaoVe; }

  string getHoTen() const { return hoTen; }

  string getDiaChi() const { return diaChi; }

  void setMaBaoVe(const string &mabv) { maBaoVe = mabv; }

  void setHoTen(const string &ht) { hoTen = ht; }

  void setDiaChi(const string &dc) { diaChi = dc; }

  virtual void nhap() {
    cout << "  Nhap ma bao ve: ";
    cin.ignore();
    getline(cin, maBaoVe);

    cout << "  Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "  Nhap dia chi: ";
    getline(cin, diaChi);
  }

  virtual void xuat() {
    cout << "  Ma: " << maBaoVe << endl;
    cout << "  Ten: " << hoTen << endl;
    cout << "  Dia chi: " << diaChi << endl;
  }

  virtual double tinhLuong() = 0;
};
