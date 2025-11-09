#pragma once
#include "GiaSuc.h"

class Bo : public GiaSuc {
 public:
  Bo() : GiaSuc() {}

  Bo(const string &ms, const float &cn, const int &t) : GiaSuc(ms, cn, t) {}

  void xuat() {
    cout << "Loai: BO\n";
    GiaSuc::xuat();
  }

  float tinhLuongSua() {
    if (tuoi >= 2 && tuoi <= 5)
      return max((float)0, canNang - tuoi / (float)10);
    return 0;
  }
};