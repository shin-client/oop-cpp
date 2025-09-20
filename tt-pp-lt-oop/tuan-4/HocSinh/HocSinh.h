#pragma once
#include <iostream>
#include <string>

using namespace std;

class HocSinh {
 private:
  string hoTen;
  float  diemToan, diemVan;

 public:
  HocSinh() : hoTen(""), diemToan(0), diemVan(0) {}

  HocSinh(string hoTen, float diemToan, float diemVan) : hoTen(hoTen), diemToan(diemToan), diemVan(diemVan) {}

  ~HocSinh() { cout << "Ham huy da duoc chay!\n"; }

  void nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap diem Toan: ";
    cin >> diemToan;
    cout << "Nhap diem Van: ";
    cin >> diemVan;
    cin.ignore();
  }

  void xuat() const {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Diem Toan: " << diemToan << endl;
    cout << "Diem Van: " << diemVan << endl;
    cout << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
    cout << "Xep loai: " << tinhXepLoai() << endl;
  }

  friend istream& operator>>(istream& in, HocSinh& hs) {
    cout << "Nhap ho ten: ";
    getline(in, hs.hoTen);
    cout << "Nhap diem Toan: ";
    in >> hs.diemToan;
    cout << "Nhap diem Van: ";
    in >> hs.diemVan;
    in.ignore();
    return in;
  }

  friend ostream& operator<<(ostream& out, const HocSinh& hs) {
    out << "Ho ten: " << hs.hoTen << endl;
    out << "Diem Toan: " << hs.diemToan << endl;
    out << "Diem Van: " << hs.diemVan << endl;
    return out;
  }

  float tinhDiemTrungBinh() const { return (diemToan + diemVan) / 2; }

  string tinhXepLoai() const {
    float dtb = (diemToan + diemVan) / 2;
    if (dtb >= 8.0)
      return "Gioi";
    else if (dtb >= 6.5)
      return "Kha";
    else if (dtb >= 5.0)
      return "Trung Binh";
    else
      return "Yeu";
  }
};