#pragma once
#include "BaoVe.h"
#include "BaoVeDem.h"
#include "BaoVeNgay.h"

class CongTy {
 private:
  int     slBaoVe;
  BaoVe **dsBaoVe;

  void clearDSBaoVe() {
    if (dsBaoVe != nullptr && slBaoVe > 0) {
      for (size_t i = 0; i < slBaoVe; ++i) {
        delete dsBaoVe[i];
      }
      delete[] dsBaoVe;
    }
  }

 public:
  CongTy() : slBaoVe(0), dsBaoVe(nullptr) {}

  CongTy(const int &slbv) : slBaoVe(slbv) {
    clearDSBaoVe();

    dsBaoVe = new BaoVe *[slBaoVe];

    for (size_t i = 0; i < slBaoVe; ++i) {
      int lc;
      do {
        cout << "\n1. Bao ve ngay.\n";
        cout << "2. Bao ve dem.\n";
        cout << "Chon bao ve can them: ";
        cin >> lc;
        if (lc != 1 && lc != 2) {
          cout << "Lua chon khong hop le! Vui long nhap lai.\n";
        }
      } while (lc != 1 && lc != 2);

      if (lc == 1) {
        dsBaoVe[i] = new BaoVeNgay();
        dsBaoVe[i]->nhap();
      } else {
        dsBaoVe[i] = new BaoVeDem();
        dsBaoVe[i]->nhap();
      }
    }
  }

  ~CongTy() { clearDSBaoVe(); }

  void nhap() {
    clearDSBaoVe();

    cout << "Nhap so luong bao ve: ";
    cin >> slBaoVe;

    dsBaoVe = new BaoVe *[slBaoVe];

    for (size_t i = 0; i < slBaoVe; ++i) {
      int lc;
      do {
        cout << "\n1. Bao ve ngay.\n";
        cout << "2. Bao ve dem.\n";
        cout << "Chon bao ve can them: ";
        cin >> lc;
        if (lc != 1 && lc != 2) {
          cout << "Lua chon khong hop le! Vui long nhap lai.\n";
        }
      } while (lc != 1 && lc != 2);

      if (lc == 1) {
        dsBaoVe[i] = new BaoVeNgay();
        dsBaoVe[i]->nhap();
      } else {
        dsBaoVe[i] = new BaoVeDem();
        dsBaoVe[i]->nhap();
      }
    }
  }

  void xuat() const {
    if (dsBaoVe == nullptr || slBaoVe == 0) {
      cout << "Danh sach trong rong!\n";
      return;
    }

    cout << "\n=== THONG TIN TAT CA BAO VE TRONG CONG TY ===\n";
    for (size_t i = 0; i < slBaoVe; ++i) {
      cout << "Bao ve thu " << (i + 1) << ":\n";
      dsBaoVe[i]->xuat();
      cout << endl;
    }
  }

  int timSoNgayLamViecNhieuNhat() const {
    int soNgayMax = 0;

    for (size_t i = 0; i < slBaoVe; ++i) {
      BaoVeNgay *bvCurr = dynamic_cast<BaoVeNgay *>(dsBaoVe[i]);
      if (bvCurr && bvCurr->getSoNgayLamViec() > soNgayMax) {
        soNgayMax = bvCurr->getSoNgayLamViec();
      }
    }

    return soNgayMax;
  }

  BaoVe* timBaoVeLuongCaoNhat() const {
    if (dsBaoVe == nullptr || slBaoVe == 0) {
      return nullptr;
    }

    BaoVe* baoVeLuongMax = dsBaoVe[0];
    double luongMax = baoVeLuongMax->tinhLuong();

    for (size_t i = 1; i < slBaoVe; ++i) {
      double luongCurr = dsBaoVe[i]->tinhLuong();
      if (luongCurr > luongMax) {
        luongMax = luongCurr;
        baoVeLuongMax = dsBaoVe[i];
      }
    }

    return baoVeLuongMax;
  }
};
