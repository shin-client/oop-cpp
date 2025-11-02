#include "MyPhanSoArray.h"

int main() {
  MyPhanSoArray *phanSoArr = new MyPhanSoArray();

  cin >> phanSoArr;
  cout << phanSoArr;

  PhanSo *max = phanSoArr->findMax();
  cout << "Phan so lon nhat: ";
  cout << max;

  system("pause");
  return 0;
}