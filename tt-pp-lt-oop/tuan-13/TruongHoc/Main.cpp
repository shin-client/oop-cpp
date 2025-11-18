#include <iostream>

#include "GiaoVien.h"
#include "HocSinh.h"
#include "TruongHoc.h"

using namespace std;

int main() {
  TruongHoc thpt;

  thpt.nhap();
  thpt.xuat();

  cout << "\n============================================\n";
  cout << "           KET QUA TIM KIEM\n";
  cout << "============================================\n";

  double dtbMax = thpt.timDTBCaoNhat();
  if (dtbMax > 0) {
    cout << "==> Diem trung binh cao nhat la: " << dtbMax << endl;
  } else {
    cout << "==> Khong co hoc sinh nao trong danh sach.\n";
  }
  cout << "--------------------------------------------\n";

  HocSinh *hsMax = thpt.hsDTBCaoNhat();
  if (hsMax != nullptr) {
    cout << "==> Hoc sinh co DTB cao nhat:\n";
    hsMax->xuat();
  } else {
    cout << "==> Khong co hoc sinh nao trong danh sach.\n";
  }
  cout << "--------------------------------------------\n";

  GiaoVien *gvMaxTN = thpt.timGiaoVienThamNienCaoNhat();
  if (gvMaxTN != nullptr) {
    cout << "==> Giao vien co tham nien cao nhat:\n";
    gvMaxTN->xuat();
  } else {
    cout << "==> Khong co giao vien nao trong danh sach.\n";
  }
  cout << "--------------------------------------------\n";

  GiaoVien **dsGV = thpt.timGiaoVienThamNhienHonNam();
  if (dsGV != nullptr) {
    cout << "==> Danh sach GV (Tu Nhien) tham nien > 5 nam:\n";

    // Duyệt mảng cho đến khi gặp "lính canh" nullptr
    for (int i = 0; dsGV[i] != nullptr; ++i) {
      dsGV[i]->xuat();
      cout << "---\n";
    }

    delete[] dsGV;
  } else {
    cout << "==> Khong tim thay GV nao thoa dieu kien.\n";
  }
  cout << "--------------------------------------------\n";

  cout << "\nChuong trinh ket thuc.\n";

  return 0;
}
