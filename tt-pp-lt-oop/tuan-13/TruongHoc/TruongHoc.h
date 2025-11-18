#pragma once
#include "GiaoVien.h"
#include "HocSinh.h"
#include "Nguoi.h"

class TruongHoc {
 private:
  size_t  SLNguoi;
  Nguoi **dsNguoi;

  void clearDSNguoi() {
    if (dsNguoi != nullptr && SLNguoi > 0) {
      for (size_t i = 0; i < SLNguoi; ++i) {
        delete dsNguoi[i];
      }
      delete[] dsNguoi;
    }
  }

 public:
  TruongHoc() : SLNguoi(0), dsNguoi(nullptr) {}

  ~TruongHoc() { clearDSNguoi(); }

  void nhap() {
    clearDSNguoi();

    cout << "Nhap so luong nguoi: ";
    cin >> SLNguoi;

    dsNguoi = new Nguoi *[SLNguoi];

    for (size_t i = 0; i < SLNguoi; ++i) {
      int lc;
      do {
        cout << "\n1. Giao vien.\n";
        cout << "2. Hoc sinh.\n";
        cout << "Chon nguoi can them: ";
        cin >> lc;
        if (lc != 1 && lc != 2) {
          cout << "Lua chon khong hop le! Vui long nhap lai.\n";
        }
      } while (lc != 1 && lc != 2);

      if (lc == 1) {
        dsNguoi[i] = new GiaoVien();
        dsNguoi[i]->nhap();
      } else {
        dsNguoi[i] = new HocSinh();
        dsNguoi[i]->nhap();
      }
    }
  }

  void xuat() const {
    if (dsNguoi == nullptr || SLNguoi == 0) {
      cout << "Danh sach trong rong!\n";
      return;
    }

    cout << "\n=== THONG TIN TAT CA NGUOI TRONG TRUONG ===\n";
    for (size_t i = 0; i < SLNguoi; ++i) {
      cout << "Nguoi thu " << (i + 1) << ":\n";
      dsNguoi[i]->xuat();
      cout << endl;
    }
  }

  GiaoVien *timGiaoVienThamNienCaoNhat() const {
    GiaoVien *giaoVienCaoNhat = nullptr;

    for (size_t i = 0; i < SLNguoi; ++i) {
      GiaoVien *giaoVien = dynamic_cast<GiaoVien *>(dsNguoi[i]);

      // Nếu chưa tìm thấy ai (giaoVienCaoNhat là nullptr)
      if (giaoVien != nullptr) {
        if (giaoVienCaoNhat == nullptr ||
            giaoVien->tinhThamNien() > giaoVienCaoNhat->tinhThamNien()) {
          giaoVienCaoNhat = giaoVien;
        }
      }
    }

    return giaoVienCaoNhat;
  }

  GiaoVien **timGiaoVienThamNhienHonNam() const {
    int SLTimThay = 0;
    for (size_t i = 0; i < SLNguoi; ++i) {
      GiaoVien *giaoVien = dynamic_cast<GiaoVien *>(dsNguoi[i]);

      if (giaoVien != nullptr && giaoVien->tinhThamNien() > 5 &&
          giaoVien->getChuyenMon() == ChuyenMon::TU_NHIEN) {
        SLTimThay++;
      }
    }

    if (SLTimThay == 0) {
      return nullptr;
    }

    GiaoVien **ketQua = new GiaoVien *[SLTimThay + 1];
    size_t     index  = 0;

    for (size_t i = 0; i < SLNguoi; ++i) {
      GiaoVien *giaoVien = dynamic_cast<GiaoVien *>(dsNguoi[i]);
      if (giaoVien != nullptr && giaoVien->tinhThamNien() > 5 &&
          giaoVien->getChuyenMon() == ChuyenMon::TU_NHIEN) {
        ketQua[index++] = giaoVien;
      }
    }

    // Lính canh để biết khi nào là cuối mảng
    ketQua[SLTimThay] = nullptr;
    return ketQua;
  }

  double timDTBCaoNhat() const {
    double dtbMax = 0;

    for (size_t i = 0; i < SLNguoi; ++i) {
      HocSinh *hocSinh = dynamic_cast<HocSinh *>(dsNguoi[i]);

      if (hocSinh != nullptr) {
        double dtbHienTai = hocSinh->tinhDiemTrungBinh();
        if (dtbHienTai > dtbMax) dtbMax = dtbHienTai;
      }
    }

    return dtbMax;
  }

  HocSinh *hsDTBCaoNhat() const {
    HocSinh *hsDTBMax = nullptr;
    double   dtbMax   = 0;

    for (size_t i = 0; i < SLNguoi; ++i) {
      HocSinh *hocSinh = dynamic_cast<HocSinh *>(dsNguoi[i]);

      if (hocSinh != nullptr) {
        double dtbHienTai = hocSinh->tinhDiemTrungBinh();

        if (hsDTBMax == nullptr || dtbHienTai > dtbMax) {
          hsDTBMax = hocSinh;
          dtbMax   = dtbHienTai;
        }
      }
    }

    return hsDTBMax;
  }
};
