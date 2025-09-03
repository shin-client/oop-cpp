#pragma once
#include <iostream>
#include <string>

using namespace std;

class HocSinh {
 private:
  string hoTen;
  float  diemToan, diemVan;

 public:
  HocSinh() {
    this->hoTen    = "";
    this->diemToan = 0;
    this->diemVan  = 0;
  }

  HocSinh(string hoTen, float diemToan, float diemVan) {
    this->hoTen    = hoTen;
    this->diemToan = diemToan;
    this->diemVan  = diemVan;
  }

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