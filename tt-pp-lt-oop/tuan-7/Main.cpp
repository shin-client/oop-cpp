#include "HocSinh.h"
#include "LopHoc.h"

int main() {
  LopHoc lh;
  cin >> lh;

  LopHoc lhSapXepTheoTen = lh.sapXepTangDanTheoTen();
  cout << lhSapXepTheoTen;

  // int       soHSCanTim;
  // string    tenHSCanTim = "Tai";
  // HocSinh **kq          = lh.timHocSinhTheoTen(tenHSCanTim, soHSCanTim);

  // if (kq != nullptr) {
  //   cout << "\nCo " << soHSCanTim << " hoc sinh duoc tim thay:\n";
  //   for (int i = 0; i < soHSCanTim; ++i) {
  //     cout << i + 1 << ". ";
  //     cout << kq[i]->getHoTen() << endl;
  //   }
  //   delete[] kq;
  // } else
  //   cout << "\nKhong co hoc sinh nao!";

  return 0;
}