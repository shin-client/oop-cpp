#include "ToaDo.h"

int main() {
  ToaDo a, b;

  a.nhap(); b.nhap();

  double result = a.tinhKhoangCach(b);

  cout << result << endl;
}