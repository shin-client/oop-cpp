#include "NongTrai.h"

int main() {
  NongTrai myFarm;

  myFarm.nhap();

  myFarm.xuat();

  cout << "Tong luong sua bo: " << myFarm.tongLuongSuaBo() << endl;

  cout << "Tong luong sua de: " << myFarm.tongLuongSuaDe() << endl;

  return 0;
}