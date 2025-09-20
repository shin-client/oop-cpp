#include "TamGiac.h"

int main() {
  TamGiac tg;
  tg.nhap();
  tg.xuat();

  cout << "Chu vi cua tam giac la: " << tg.tinhChuVi() << endl;
  cout << "Dien tich cua tam giac la: " << tg.tinhDienTich() << endl;

  return 0;
}