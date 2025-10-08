#pragma once
#include <algorithm>
#include <iostream>
#include <string>

#include "HocSinh.h"

using namespace std;

class LopHoc {
 private:
  string    tenLop;
  int       siSo;
  HocSinh** dsHocSinh;

 public:
  LopHoc() : tenLop(""), siSo(0), dsHocSinh(nullptr) {}

  LopHoc(string tenLop, int siSo, HocSinh** dsHocSinh)
      : tenLop(tenLop), siSo(siSo) {
    this->dsHocSinh = new HocSinh*[siSo];
    for (int i = 0; i < siSo; ++i) {
      this->dsHocSinh[i] = new HocSinh(*dsHocSinh[i]);
    }
  }

  ~LopHoc() {
    if (dsHocSinh != nullptr) {
      for (int i = 0; i < siSo; ++i) {
        delete dsHocSinh[i];
      }
      delete[] dsHocSinh;
      dsHocSinh = nullptr;
    }
  }

  friend istream& operator>>(istream& in, LopHoc& lh) {
    cout << "Nhap ten lop hoc: ";
    getline(in, lh.tenLop);
    cout << "Nhap si so lop hoc: ";
    cin >> lh.siSo;
    cin.ignore();

    if (lh.siSo > 0) {
      lh.dsHocSinh = new HocSinh*[lh.siSo];

      cout << "Nhap danh sanh " << lh.siSo << " hoc sinh\n";
      for (int i = 0; i < lh.siSo; ++i) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        lh.dsHocSinh[i] = new HocSinh();
        in >> *(lh.dsHocSinh[i]);
      }
    } else
      lh.dsHocSinh = nullptr;
    return in;
  }

  friend ostream& operator<<(ostream& out, const LopHoc& lh) {
    system("cls");
    out << "--- Thong tin Lop Hoc ---\n";
    out << "Ten lop: " << lh.tenLop << "\n";
    out << "Si so: " << lh.siSo << "\n";
    out << "Danh sach hoc sinh:\n";

    if (lh.dsHocSinh != nullptr) {
      for (int i = 0; i < lh.siSo; ++i) {
        out << i + 1 << ". ";
        out << *(lh.dsHocSinh[i]) << "\n";
      }
    } else {
      out << "  (Khong co hoc sinh)\n";
    }

    return out;
  }

  float diemTrungBinhCaLop() const {
    float res = 0;
    for (int i = 0; i < siSo; ++i) {
      res += dsHocSinh[i]->tinhDiemTrungBinh();
    }
    return res / siSo;
  }

  float timDiemTrungBinhMax() const {
    float tbMax = -1;
    for (int i = 0; i < siSo - 1; ++i) {
      for (int j = i; j < siSo; ++j) {
        if (dsHocSinh[j]->tinhDiemTrungBinh() > tbMax)
          tbMax = dsHocSinh[j]->tinhDiemTrungBinh();
      }
    }
    return tbMax;
  }

  HocSinh* timHocSinhTheoMa(const string& maCanTim) {
    if (dsHocSinh == nullptr || siSo == 0) return nullptr;

    for (int i = 0; i < siSo; ++i) {
      if (dsHocSinh[i]->getMaHS() == maCanTim) return dsHocSinh[i];
    }

    return nullptr;
  }

  HocSinh** timHocSinhTheoTen(const string& tenCanTim, int& count) const {
    count = 0;

    if (dsHocSinh == nullptr || siSo == 0) return nullptr;

    for (int i = 0; i < siSo; ++i) {
      if (dsHocSinh[i]->getHoTen().find(tenCanTim) != string::npos) count++;
    }

    if (count == 0) return nullptr;

    HocSinh** res       = new HocSinh*[count];
    int       currIndex = 0;
    for (int i = 0; i < siSo; ++i) {
      if (dsHocSinh[i]->getHoTen().find(tenCanTim) != string::npos)
        res[currIndex++] = dsHocSinh[i];
    }

    return res;
  }

  HocSinh** timHocSinhXepLoaiYeu(int& count) const {
    count = 0;

    if (dsHocSinh == nullptr || siSo == 0) return nullptr;

    for (int i = 0; i < siSo; ++i) {
      if (dsHocSinh[i]->tinhXepLoai() == "Yeu") count++;
    }

    if (count == 0) return nullptr;

    HocSinh** res       = new HocSinh*[count];
    int       currIndex = 0;
    for (int i = 0; i < siSo; ++i) {
      if (dsHocSinh[i]->tinhXepLoai() == "Yeu") res[currIndex++] = dsHocSinh[i];
    }

    return res;
  }

  LopHoc sapXepTangDanTheoDiemTrungBinh() const {
    LopHoc temp = *this;
    sort(temp.dsHocSinh, temp.dsHocSinh + siSo,
         [](const HocSinh* hs1, const HocSinh* hs2) {
           return hs1->tinhDiemTrungBinh() < hs2->tinhDiemTrungBinh();
         });
    return temp;
  }

  LopHoc sapXepTangDanTheoTen() const {
    LopHoc temp = *this;
    sort(temp.dsHocSinh, temp.dsHocSinh + siSo,
         [](const HocSinh* hs1, const HocSinh* hs2) {
           if (hs1->getTen() != hs2->getTen())
             return hs1->getTen() < hs2->getTen();
           return hs1->getHoTen() < hs2->getHoTen();
         });
    return temp;
  }
};
