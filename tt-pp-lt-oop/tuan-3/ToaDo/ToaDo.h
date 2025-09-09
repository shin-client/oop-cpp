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
};