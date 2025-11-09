#pragma once
#include "GiaSuc.h"

class De : public GiaSuc {
 public:
  De() : GiaSuc() {}

  De(const string &ms, const float &cn, const int &t) : GiaSuc(ms, cn, t) {}

  void xuat() {
    cout << "Loai: DE\n";
    GiaSuc::xuat();
  }

  float tinhLuongSua() {
    if (tuoi >= 1 && tuoi <= 2)
      return canNang / 10;
    else if (tuoi > 2 && tuoi <= 4)
      return canNang / 15;
    return 0;
  }
};