#pragma once
#include <iostream>

using namespace std;

class PhanSo {
 private:
  int tu, mau;

 public:
  PhanSo() : tu(0), mau(1) {}

  PhanSo(int tu, int mau) {
    this->tu  = tu;
    this->mau = mau;
  }

  void nhap() {
    cout << "Nhap tu so: ";
    cin >> tu;
    cout << "Nhap mau so: ";
    cin >> mau;
    if (mau == 0) {
      cout << "Mau so khong the la 0. Vui long nhap lai." << endl;
      nhap();
    }
  }

  void xuat() const { cout << tu << "/" << mau; }

  PhanSo cong(const PhanSo& ps2) const {
    int    tuMoi  = tu * ps2.mau + ps2.tu * mau;
    int    mauMoi = mau * ps2.mau;
    PhanSo tong(tuMoi, mauMoi);
    tong.rutGon();
    return tong;
  }

 private:
  int timUocChungLonNhat(int a, int b) const {
    while (b != 0) {
      int temp = b;
      b        = a % b;
      a        = temp;
    }
    return a;
  }

  void rutGon() {
    int ucln = timUocChungLonNhat(abs(tu), abs(mau));
    tu /= ucln;
    mau /= ucln;
  }
};