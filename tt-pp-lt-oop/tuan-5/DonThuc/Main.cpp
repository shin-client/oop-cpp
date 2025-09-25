#include "DonThuc.h"

int main() {
  DonThuc *dt1 = new DonThuc, *dt2 = new DonThuc;
  cout << "Nhap don thuc 1:\n";
  cin >> *dt1;
  cout << "Nhap don thuc 2:\n";
  cin >> *dt2;

  DonThuc result = *dt1 + *dt2;

  cout << result;
  delete dt1, dt2;
  return 0;
}