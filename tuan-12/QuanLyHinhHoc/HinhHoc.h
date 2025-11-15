#pragma once
#include <iostream>

using namespace std;

class HinhHoc {
 protected:
  const double PI = 3.14;

 public:
  virtual void nhap() = 0;

  virtual void xuat() const = 0;

  virtual double tinhDienTich() const = 0;
};
