#include "PhanSo.h"

int main() {
  PhanSo *ps1 = new PhanSo, *ps2 = new PhanSo;
  PhanSo  result;

  cout << "Nhap phan so thu nhat:" << endl;
  cin >> *ps1;

  cout << "Nhap phan so thu hai:" << endl;
  cin >> *ps2;

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
        result = *ps1 + *ps2;
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;

      case 2:
        result = *ps1 - *ps2;
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;

      case 3:
        result = *ps1 * *ps2;
        cout << "Ket qua la ";
        result.xuat();
        cout << endl;
        break;

      case 4:
        result = *ps1 / *ps2;
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