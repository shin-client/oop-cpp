#include <iostream>
#include <numeric>
using namespace std;

int USCLN(int a, int b) {
  if (b == 0) return a;
  return USCLN(b, a % b);
}

class PhanSo {
 private:
  int tu, mau;

 public:
  PhanSo() : tu(0), mau(1) {}

  PhanSo(int t, int m) : tu(t) { mau = (m != 0) ? m : 1; }

  void nhap() {
    cout << "Nhap tu: ";
    cin >> tu;
    do {
      cout << "Nhap mau (!=0): ";
      cin >> mau;
    } while (mau == 0);
  }

  void rutGon() {
    int uoc = USCLN(abs(tu), abs(mau));
    tu /= uoc;
    mau /= uoc;
  }

  void xuat() { cout << tu << "/" << mau << endl; }
};
