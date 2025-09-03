#include "HinhTron.h"

int main() {
  HinhTron ht{};

  ht.nhap();

  float chuVi    = ht.tinhChuVi();
  float dienTich = ht.tinhDienTich();

  ht.xuat();
  return 0;
}