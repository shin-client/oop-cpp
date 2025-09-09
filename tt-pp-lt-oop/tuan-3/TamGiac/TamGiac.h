#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class ToaDo {
 private:
  double x, y;

 public:
  void nhap() {
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
  }

  void xuat() const { cout << "(" << x << ", " << y << ")"; }

  double tinhKhoangCach(ToaDo td) const { return sqrt(pow(td.x - x, 2) + pow(td.y - y, 2)); }

  int getX() const { return x; }

  int getY() const { return y; }
};

class TamGiac {
 private:
  ToaDo a, b, c;

 public:
  void nhap() {
    cout << "Nhap toa do cua diem a:\n";
    a.nhap();
    cout << "Nhap toa do cua diem b:\n";
    b.nhap();
    cout << "Nhap toa do cua diem c:\n";
    c.nhap();
  }

  void xuat() const {
    cout << "Tam giac co cac dinh la: ";
    a.xuat();
    cout << ", ";
    b.xuat();
    cout << ", ";
    c.xuat();
    cout << endl;
  }

  double tinhChuVi() const { return a.tinhKhoangCach(b) + b.tinhKhoangCach(c) + c.tinhKhoangCach(a); }

  double tinhDienTich() const {
    double temp1 = a.getX() * (b.getY() - c.getY());
    double temp2 = b.getX() * (c.getY() - a.getY());
    double temp3 = c.getX() * (a.getY() - b.getY());
    return 0.5 * abs(temp1 + temp2 + temp3);
  }
};