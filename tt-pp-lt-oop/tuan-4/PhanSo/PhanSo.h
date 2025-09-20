#pragma once
#include <iostream>

using namespace std;

class PhanSo {
 private:
  int tu, mau;

 public:
  PhanSo() : tu(0), mau(1) {}

  PhanSo(int tu, int mau) : tu(tu), mau(mau) {}

  ~PhanSo() { cout << "Ham huy da duoc chay!\n"; }

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

  friend istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.tu;
    cout << "Nhap mau so: ";
    in >> ps.mau;
    return in;
  }

  friend ostream& operator<<(ostream& out, const PhanSo& ps) {
    if (ps.tu == ps.mau)
      out << ps.tu;
    else
      out << ps.tu << "/" << ps.mau;
    return out;
  }

  PhanSo operator+(const PhanSo& ps) const { return PhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau).rutGon(); }

  PhanSo operator-(const PhanSo& ps) const { return PhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau).rutGon(); }

  PhanSo operator*(const PhanSo& ps) const { return PhanSo(tu * ps.tu, mau * ps.mau).rutGon(); }

  PhanSo operator/(const PhanSo& ps) const { return PhanSo(tu * ps.mau, mau * ps.tu).rutGon(); }

 private:
  int timUocChungLonNhat(int a, int b) const {
    while (b != 0) {
      int temp = b;
      b        = a % b;
      a        = temp;
    }
    return a;
  }

  PhanSo rutGon() {
    int ucln = timUocChungLonNhat(abs(tu), abs(mau));
    tu /= ucln;
    mau /= ucln;
    return PhanSo(tu, mau);
  }
};