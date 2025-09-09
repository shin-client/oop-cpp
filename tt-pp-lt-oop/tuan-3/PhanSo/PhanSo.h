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
      cout << "Mau so phai khac 0. Vui long nhap lai." << endl;
      nhap();
    }
  }

  void xuat() const {
    if (tu == mau)
      cout << tu;
    else
      cout << tu << "/" << mau;
  }

  PhanSo cong(const PhanSo& ps) const {
    int tuMoi, mauMoi;

    if (mau == ps.mau) {
      tuMoi  = tu + ps.tu;
      mauMoi = mau;
    } else {
      tuMoi  = tu * ps.mau + mau * ps.tu;
      mauMoi = mau == mau * ps.mau;
    }

    PhanSo result(tuMoi, mauMoi);
    result.rutGon();
    return result;
  }

  PhanSo tru(const PhanSo& ps) const {
    int tuMoi, mauMoi;

    if (mau == ps.mau) {
      tuMoi  = tu - ps.tu;
      mauMoi = mau;
    } else {
      tuMoi  = tu * ps.mau - mau * ps.tu;
      mauMoi = mau == mau * ps.mau;
    }

    PhanSo result(tuMoi, mauMoi);
    result.rutGon();
    return result;
  }

  PhanSo nhan(const PhanSo& ps) const {
    int tuMoi = tu * ps.tu, mauMoi = mau * ps.mau;

    PhanSo result(tuMoi, mauMoi);
    result.rutGon();
    return result;
  }

  PhanSo chia(const PhanSo& ps) const {
    int tuMoi = tu * ps.mau, mauMoi = mau * ps.tu;

    PhanSo result(tuMoi, mauMoi);
    result.rutGon();
    return result;
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