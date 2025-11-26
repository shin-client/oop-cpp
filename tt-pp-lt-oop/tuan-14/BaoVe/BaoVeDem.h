#pragma once
#include "BaoVe.h"

class BaoVeDem : public BaoVe {
 private:
  int soCaLamViec;
  int loaiCa;

 public:
  BaoVeDem() : BaoVe(), soCaLamViec(0), loaiCa(1) {}

  BaoVeDem(const string &mabv, const string &ht, const string &dc,
           const int &sclv, const int &lc)
      : BaoVe(mabv, ht, dc), soCaLamViec(sclv), loaiCa(lc) {}

  ~BaoVeDem() {}

  int getSoCaLamViec() const { return soCaLamViec; }

  int getLoaiCa() const { return loaiCa; }

  void setSoCaLamViec(const int &sclv) { soCaLamViec = sclv; }

  void setLoaiCa(const int &lc) { loaiCa = lc; }

  void nhap() {
    cout << "--- Nhap thong tin Bao Ve Dem ---\n";
    BaoVe::nhap();

    cout << "  Nhap so ca lam viec: ";
    cin >> soCaLamViec;

    do {
      cout << "Nhap loai ca (chi nhap 1 hoac 2): ";
      cin >> loaiCa;
      if (loaiCa != 1 && loaiCa != 2) {
        cout << "Loi! Loai ca khong hop le. Vui long nhap lai.\n";
      }
    } while (loaiCa != 1 && loaiCa != 2);
  }

  void xuat() {
    cout << "[Bao Ve Dem]\n";
    BaoVe::xuat();
    cout << "  So ca: " << soCaLamViec << endl;
    cout << "  Loai ca: " << loaiCa << endl;
  }

  double tinhLuong() {
    if (loaiCa == 1) return soCaLamViec * 120;
    return soCaLamViec * 150;
  }
};
