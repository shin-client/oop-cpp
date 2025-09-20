#include "ToaDo.h"

int main() {
  ToaDo *a = new ToaDo, *b = new ToaDo;

  cin >> *a;
  cin >> *b;

  double result = a->tinhKhoangCach(*b);

  cout << result << endl;
}