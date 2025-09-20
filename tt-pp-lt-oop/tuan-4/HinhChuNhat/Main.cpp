#include "HinhChuNhat.h"

int main() {
  HinhChuNhat *hcn = new HinhChuNhat(4, 7);

  float chuVi    = hcn->tinhChuVi();
  float dienTich = hcn->tinhDienTich();

  cout << *hcn;

  delete hcn;
  hcn = NULL;
  return 0;
}