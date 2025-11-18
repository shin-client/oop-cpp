#pragma once
#include <iostream>
#include <limits>

using namespace std;

class Nguoi {
 protected:
  string hoTen;
  int    namSinh;
  string noiSinh;
  string diaChi;

 public:
  Nguoi() : hoTen(""), namSinh(0), noiSinh(""), diaChi("") {}

  Nguoi(const string& ht, int ns, const string& noisinh, const string& dc)
    : hoTen(ht), namSinh(ns), noiSinh(noisinh), diaChi(dc) {}

  virtual ~Nguoi() {}

  virtual void nhap() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "  Nhap nam sinh: ";
    cin >> namSinh;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  Nhap noi sinh: ";
    getline(cin, noiSinh);
    cout << "  Nhap dia chi: ";
    getline(cin, diaChi);
  }

  virtual void xuat() {
    cout << "  Ho ten: " << hoTen << endl;
    cout << "  Nam sinh: " << namSinh << endl;
    cout << "  Noi sinh: " << noiSinh << endl;
    cout << "  Dia chi: " << diaChi << endl;
  };

  string getHoTen() const { return hoTen; }

  int getNamSinh() const { return namSinh; }

  string getNoiSinh() const { return noiSinh; }

  string getDiaChi() const { return diaChi; }

  void setHoTen(const string& ht) { hoTen = ht; }

  void setNamSinh(const int& ns) { namSinh = ns; }

  void setNoiSinh(const string& ns) { noiSinh = ns; }

  void setDiaChi(const string& dc) { diaChi = dc; }
};
