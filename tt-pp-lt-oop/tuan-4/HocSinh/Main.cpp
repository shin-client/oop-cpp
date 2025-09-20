#include "HocSinh.h"

int main() {
  HocSinh *hs = new HocSinh;

  cin >> *hs;
  cout << *hs;

  delete hs;
  hs = NULL;
  return 0;
}