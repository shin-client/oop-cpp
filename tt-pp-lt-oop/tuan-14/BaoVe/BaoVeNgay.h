#pragma once
#include "BaoVe.h"

class BaoVeNgay : public BaoVe {
 private:
  int soNgayLamViec;

 public:
  BaoVeNgay() : BaoVe(), soNgayLamViec(0) {}

  BaoVeNgay(const string &mabv, const string &ht, const string &dc,
            const int &snlv)
      : BaoVe(mabv, ht, dc), soNgayLamViec(snlv) {}

  ~BaoVeNgay() {}

  int getSoNgayLamViec() const { return soNgayLamViec; }

  void setSoNgayLamViec(const int &snlv) { soNgayLamViec = snlv; }

  void nhap() {
    cout << "--- Nhap thong tin Bao Ve Ngay ---\n";
    BaoVe::nhap();

    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
  }

  void xuat() {
    cout << "[Bao Ve Ngay]\n";
    BaoVe::xuat();
    cout << "  So ngay lam: " << soNgayLamViec << endl;
  }

  double tinhLuong() { return soNgayLamViec * 100; }
};
