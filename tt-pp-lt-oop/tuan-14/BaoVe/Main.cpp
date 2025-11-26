#include "CongTy.h"
#include "BaoVe.h"
#include "BaoVeNgay.h"
#include "BaoVeDem.h"

int main() {
  CongTy ctyA;

  ctyA.nhap();
  ctyA.xuat();

  int soNgayMax = ctyA.timSoNgayLamViecNhieuNhat();
  cout << "==> So ngay lam viec nhieu nhat la: " << soNgayMax << endl;

  BaoVe* bvLuongMax = ctyA.timBaoVeLuongCaoNhat();

  if (dynamic_cast<BaoVeNgay *>(bvLuongMax)) bvLuongMax->xuat();
  else dynamic_cast<BaoVeDem *>(bvLuongMax)->xuat();

  return 0;
}
