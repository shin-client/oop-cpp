#pragma once
#include <cmath>
#include <iostream>
#include <vector>

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

class DaGiac {
 private:
  int           n;
  vector<ToaDo> dinh;

 public:
  void nhap() {
    cout << "Nhap so dinh: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      ToaDo temp;
      cout << "Nhap toa do " << i << "\n";
      temp.nhap();
      dinh.push_back(temp);
    }
  }

  void xuat() const {
    cout << "Tat ca cac dinh: ";
    bool first = true;
    for (const ToaDo& td : dinh) {
      if (!first) cout << ", ";
      td.xuat();
      first = false;
    }
    cout << endl;
  }

  double tinhChuVi() const {
    double result = 0;

    for (size_t i = 0; i < dinh.size(); ++i) {
      if (i == (dinh.size() - 1))
        result += dinh[i].tinhKhoangCach(dinh[0]);
      else
        result += dinh[i].tinhKhoangCach(dinh[i + 1]);
    }
    return result;
  }
};