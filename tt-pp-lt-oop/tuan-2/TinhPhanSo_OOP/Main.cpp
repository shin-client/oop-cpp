#include "PhanSo.h"

int main() {
  PhanSo ps1, ps2;

  cout << "Nhap phan so thu nhat:" << endl;
  ps1.nhap();

  cout << "Nhap phan so thu hai:" << endl;
  ps2.nhap();

  PhanSo tong = ps1.cong(ps2);

  cout << "\nTong cua ";
  ps1.xuat();
  cout << " va ";
  ps2.xuat();
  cout << " la ";
  tong.xuat();
  cout << endl;

  return 0;
}