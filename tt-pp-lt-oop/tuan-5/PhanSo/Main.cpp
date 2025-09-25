#include "PhanSo.h"

int main() {
  PhanSo *ps1 = new PhanSo, *ps2 = new PhanSo;
  PhanSo  result;
  bool    check = false;

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
    cout << "5. Lon hon\n";
    cout << "6. Lon hon hoac bang\n";
    cout << "7. Be hon\n";
    cout << "8. Be hon hoac bang\n";
    cout << "9. Bang\n";
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
        cout << result << endl;
        break;

      case 2:
        result = *ps1 - *ps2;
        cout << "Ket qua la ";
        cout << result << endl;
        break;

      case 3:
        result = *ps1 * *ps2;
        cout << "Ket qua la ";
        cout << result << endl;
        break;

      case 4:
        result = *ps1 / *ps2;
        cout << "Ket qua la ";
        cout << result << endl;
        break;

      case 5:
        check = *ps1 > *ps2;
        cout << "Ket qua la ";
        cout << check << endl;
        break;

      case 6:
        check = *ps1 >= *ps2;
        cout << "Ket qua la ";
        cout << check << endl;
        break;

      case 7:
        check = *ps1 < *ps2;
        cout << "Ket qua la ";
        cout << check << endl;
        break;

      case 8:
        check = *ps1 <= *ps2;
        cout << "Ket qua la ";
        cout << check << endl;
        break;

      case 9:
        check = *ps1 == *ps2;
        cout << "Ket qua la ";
        cout << check << endl;
        break;
      default:
        break;
    }
  }
  delete ps1, ps2, result;
  return 0;
}