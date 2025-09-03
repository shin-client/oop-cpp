#include "HinhChuNhat.h"

int main() {
  HinhChuNhat hcn{};

  hcn.xuat();

  hcn.nhap();

  float chuVi    = hcn.tinhChuVi();
  float dienTich = hcn.tinhDienTich();

  hcn.xuat();
  return 0;
}