#pragma once
#include "HinhChuNhat.h"
#include "HinhElip.h"
#include "HinhHoc.h"
#include "HinhTron.h"
#include "HinhVuong.h"

class DanhSachHinh {
 private:
  HinhHoc **DSHinh;
  int       SLHinh;

 public:
  ~DanhSachHinh() {
    if (DSHinh != nullptr) {
      for (int i = 0; i < SLHinh; ++i) {
        delete DSHinh[i];
      }
      delete[] DSHinh;
    }
  }

  void nhap() {
    cout << "Nhap so luong hinh: ";
    cin >> SLHinh;

    DSHinh = new HinhHoc *[SLHinh];

    for (int i = 0; i < SLHinh; ++i) {
      cout << "1. Hinh chu nhat\n";
      cout << "2. Hinh vuong\n";
      cout << "3. Hinh Elip\n";
      cout << "4. Hinh tron\n";
      cout << "Chon loai hinh: ";
      int chosse;
      cin >> chosse;

      if (chosse == 1) {
        DSHinh[i] = new HinhChuNhat();
        DSHinh[i]->nhap();
      } else if (chosse == 2) {
        DSHinh[i] = new HinhVuong();
        DSHinh[i]->nhap();
      } else if (chosse == 3) {
        DSHinh[i] = new HinhElip();
        DSHinh[i]->nhap();
      } else if (chosse == 4) {
        DSHinh[i] = new HinhTron();
        DSHinh[i]->nhap();
      } else {
        cout << "Lua chon khong hop le! Nghung nhap!";
        return;
      }
    }
  }

  void xuat() const {
    if (DSHinh == nullptr) {
      cout << "Khong co hinh nao ca!";
      return;
    }

    cout << "Chi tiet danh sach cac hinh:\n";
    for (int i = 0; i < SLHinh; ++i) {
      DSHinh[i]->xuat();
    }
  }

  double tinhTongDienTich() const {
    if (DSHinh == nullptr) return;

    double res = 0;
    for (int i = 0; i < SLHinh; ++i) {
      res += DSHinh[i]->tinhDienTich();
    }
    return res;
  }

  double timDienTichMax() const {
    if (DSHinh == nullptr) return;

    double dTMax = DSHinh[0]->tinhDienTich();
    for (int i = 1; i < SLHinh; ++i) {
      if (DSHinh[i]->tinhDienTich() > dTMax) dTMax = DSHinh[i]->tinhDienTich();
    }
    return dTMax;
  }

  HinhHoc *timHinhCoDienTichMax() const {
    if (DSHinh == nullptr) return;

    HinhHoc *hinhMax = DSHinh[0];
    double   dTMax   = hinhMax->tinhDienTich();

    for (int i = 0; i < SLHinh; ++i) {
      if (DSHinh[i]->tinhDienTich() > dTMax) {
        hinhMax = DSHinh[i];
        dTMax   = DSHinh[i]->tinhDienTich();
      }
    }

    return hinhMax;
  }

  string timLoaiHinhCoTongDienTichMax() const {
    if (DSHinh == nullptr) return;

    string loaiHinhDTMax = "";

    double tongLoaiDTHinhCN = 0, tongLoaiDTHinhVuong = 0,
           tongLoaiDTHinhElip = 0, tongLoaiDTHinhTron = 0;

    for (int i = 0; i < SLHinh; ++i) {
      HinhHoc *hinh = DSHinh[i];
      if (dynamic_cast<HinhVuong *>(hinh)) {
        tongLoaiDTHinhVuong += hinh->tinhDienTich();
      } else if (dynamic_cast<HinhChuNhat *>(hinh)) {
        tongLoaiDTHinhCN += hinh->tinhDienTich();
      } else if (dynamic_cast<HinhTron *>(hinh)) {
        tongLoaiDTHinhTron += hinh->tinhDienTich();
      } else if (dynamic_cast<HinhElip *>(hinh)) {
        tongLoaiDTHinhElip += hinh->tinhDienTich();
      }
    }

    double maxDienTich = -1.0;

    if (tongLoaiDTHinhCN > maxDienTich) {
      maxDienTich   = tongLoaiDTHinhCN;
      loaiHinhDTMax = "Hinh Chu Nhat";
    }

    if (tongLoaiDTHinhVuong > maxDienTich) {
      maxDienTich   = tongLoaiDTHinhVuong;
      loaiHinhDTMax = "Hinh Vuong";
    }

    if (tongLoaiDTHinhElip > maxDienTich) {
      maxDienTich   = tongLoaiDTHinhElip;
      loaiHinhDTMax = "Hinh Elip";
    }

    if (tongLoaiDTHinhTron > maxDienTich) {
      maxDienTich   = tongLoaiDTHinhTron;
      loaiHinhDTMax = "Hinh Tron";
    }

    return loaiHinhDTMax;
  }
};