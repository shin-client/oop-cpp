#include "HinhChuNhat.h"

void HinhChuNhat::nhap() {
  cout << "Nhap chieu dai: ";
  cin >> this->chieuDai;
  cout << "Nhap chieu rong: ";
  cin >> this->chieuRong;
}

void HinhChuNhat::xuat() {
  cout << "Chu vi: " << HinhChuNhat::tinhChuVi() << endl;
  cout << "Dien tich: " << HinhChuNhat::tinhDienTich() << endl;
}

float HinhChuNhat::tinhChuVi() { return (this->chieuDai + this->chieuRong) * 2; }

float HinhChuNhat::tinhDienTich() { return this->chieuDai * this->chieuRong; }