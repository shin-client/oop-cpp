#pragma once
#include "Bo.h"
#include "De.h"
#include "GiaSuc.h"

class NongTrai {
 private:
  int      soLuong;
  GiaSuc **dsGiaSuc;

  void clearDSGiaSuc() const {
    if (dsGiaSuc != nullptr) {
      for (int i = 0; i < soLuong; ++i) {
        delete dsGiaSuc[i];
      }
      delete[] dsGiaSuc;
    }
  }

 public:
  NongTrai() : soLuong(0), dsGiaSuc(nullptr) {}

  ~NongTrai() { clearDSGiaSuc(); }

  void nhap() {
    clearDSGiaSuc();

    cout << "Nhap so luong gia suc: ";
    cin >> soLuong;

    dsGiaSuc = new GiaSuc *[soLuong];

    for (int i = 0; i < soLuong; ++i) {
      cout << "1. Bo.\n";
      cout << "2. De.\n";
      cout << "Nhap loai gia suc: ";
      int choose;
      cin >> choose;

      if (choose == 1) {
        dsGiaSuc[i] = new Bo();
        dsGiaSuc[i]->nhap();
      } else if (choose == 2) {
        dsGiaSuc[i] = new De();
        dsGiaSuc[i]->nhap();
      } else
        cout << "Vui long chon 1 hoac 2!\n";
    }
  }

  void xuat() {
    cout << "\nThong Tin Nong Trai\n";
    cout << "Tong so luong gia suc: " << soLuong << endl;
    for (int i = 0; i < soLuong; ++i) {
      dsGiaSuc[i]->xuat();
      cout << "Luong sua: " << dsGiaSuc[i]->tinhLuongSua() << " lit\n\n";
    }
  }

  float tongLuongSuaBo() const {
    float tong = 0;
    for (int i = 0; i < soLuong; ++i) {
      // Ep kieu that bai se la nullptr
      Bo *conBo = dynamic_cast<Bo *>(dsGiaSuc[i]);
      if (conBo != nullptr) {
        tong += conBo->tinhLuongSua();
      }
    }
    return tong;
  }

  float tongLuongSuaDe() const {
    float tong = 0;
    for (int i = 0; i < soLuong; ++i) {
      // Ep kieu that bai se la nullptr
      De *conDe = dynamic_cast<De *>(dsGiaSuc[i]);
      if (conDe != nullptr) {
        tong += conDe->tinhLuongSua();
      }
    }
    return tong;
  }

  float timLuongSuaMax() const {
    if (soLuong == 0) return 0;

    float maxSua = dsGiaSuc[0]->tinhLuongSua();
    for (int i = 1; i < soLuong; ++i) {
      float sua = dsGiaSuc[i]->tinhLuongSua();
      if (sua > maxSua) {
        maxSua = sua;
      }
    }
    return maxSua;
  }

  GiaSuc *timGiaSucCoLuongSuaMax() const {
    if (soLuong == 0) return nullptr;

    GiaSuc *conVatMax = dsGiaSuc[0];
    float   maxSua    = conVatMax->tinhLuongSua();

    for (int i = 0; i < soLuong; ++i) {
      // Chi lay gia suc co luong sua cao nhat dau tien
      float suaHienTai = dsGiaSuc[i]->tinhLuongSua();
      if (suaHienTai == maxSua) {
        maxSua    = suaHienTai;
        conVatMax = dsGiaSuc[i];
        return;
      }
    }

    return conVatMax;
  }
};