#include "PhanSo.h"

int main() {
  PhanSo ps1, ps2, result;

  cout << "Nhap phan so thu nhat:" << endl;
  ps1.nhap();

  cout << "Nhap phan so thu hai:" << endl;
  ps2.nhap();

  while (1) {
    cout << "0. Thoat\n";
    cout << "1. Cong\n";
    cout << "2. Tru\n";
    cout << "3. Nhan\n";
    cout << "4. Chia\n";
    cout << "Nhap lua chon: ";
    int choose;
    cin >> choose;

    switch (choose) {
      case 0:
        return 0;
        break;

      case 1:
        result = ps1.cong(ps2);
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;

      case 2:
        result = ps1.tru(ps2);
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;

      case 3:
        result = ps1.nhan(ps2);
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;

      case 4:
        result = ps1.chia(ps2);
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;
      default:
        break;
    }
  }
  return 0;
}