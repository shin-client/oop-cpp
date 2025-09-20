#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class ToaDo {
 private:
  double x, y;

 public:
  ToaDo() : x(0), y(0) {}

  ToaDo(double x, double y) : x(x), y(y) {}

  ~ToaDo() { x = y = 0; }

  void nhap() {
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
  }

  void xuat() const { cout << "(" << x << ", " << y << ")"; }

  friend istream& operator>>(istream& in, ToaDo& td) {
    cout << "Nhap toa do x: ";
    in >> td.x;
    cout << "Nhap toa do y: ";
    in >> td.y;
    return in;
  }

  friend ostream& operator>>(ostream& out, ToaDo& td) {
    out << "(" << td.x << ", " << td.y << ")";
    return out;
  }

  double tinhKhoangCach(const ToaDo& td) const { return sqrt(pow(td.x - x, 2) + pow(td.y - y, 2)); }
};