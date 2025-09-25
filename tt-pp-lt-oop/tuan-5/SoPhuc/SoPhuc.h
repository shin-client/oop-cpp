#pragma once
#include <iostream>

using namespace std;

class SoPhuc {
 private:
  int thuc, ao;

 public:
  SoPhuc() : thuc(0), ao(0) {}

  SoPhuc(int thuc, int ao) : thuc(thuc), ao(ao) {}

  ~SoPhuc() {}

  friend istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    in >> sp.thuc;
    cout << "Nhap phan ao: ";
    in >> sp.ao;
    return in;
  }

  friend ostream& operator<<(ostream& out, const SoPhuc& sp) {
    cout << sp.thuc << " + " << sp.ao << "i" << endl;
    return out;
  }

  SoPhuc operator+(const SoPhuc& sp) { return SoPhuc(thuc + sp.thuc, ao + sp.ao); }

  SoPhuc operator-(const SoPhuc& sp) { return SoPhuc(thuc - sp.thuc, ao - sp.ao); }
};
