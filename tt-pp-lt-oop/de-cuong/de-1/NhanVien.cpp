#include "NhanVien.h"

NhanVien::NhanVien() : hoTen(""), namSinh(0), diaChi(""), sdt("") {}

NhanVien::~NhanVien() {}

void NhanVien::nhap() {
  cin.ignore();
  cout << "Nhap ho ten: ";
  getline(cin, hoTen);
  cout << "Nhap nam sinh: ";
  cin >> namSinh;
  cout << "Nhap dia chi: ";
  cin.ignore();
  getline(cin, diaChi);
  cout << "Nhap so dien thoai: ";
  getline(cin, sdt);
}

void NhanVien::xuat() {
  cout << "Ho ten: " << hoTen << endl;
  cout << "Nam sinh: " << namSinh << endl;
  cout << "Dia chi: " << diaChi << endl;
  cout << "So dien thoai: " << sdt << endl;
}
