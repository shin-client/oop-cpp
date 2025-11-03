#include "MoTo.h"

class HangXe {
 private:
  MoTo *dsMoTo;
  int   soLuong;

 public:
  HangXe() : dsMoTo(nullptr), soLuong(0) {}

  ~HangXe() { delete[] dsMoTo; }

  friend istream &operator>>(istream &in, HangXe &hx) {
    in >> hx.soLuong;

    delete[] hx.dsMoTo;

    hx.dsMoTo = new MoTo[hx.soLuong];

    for (int i = 0; i < hx.soLuong; ++i) {
      in >> hx.dsMoTo[i];
    }

    return in;
  }

  friend ostream &operator<<(ostream &out, HangXe &hx) {
    for (int i = 0; i < hx.soLuong; ++i) {
      out << hx.dsMoTo[i];
    }
    return out;
  }

  MoTo* timXeTheoSoMay(const string& sm) const {
    for (int i = 0; i < soLuong; ++i) {
      if (dsMoTo[i].getSoMay() == sm)
        return &dsMoTo[i];
    }
    return nullptr;
  }

  MoTo* timXeTheoNhaSanXuat(const string& nsx, int &soLuongTimThay) const {
    int xeTimThay = 0;

    for (int i = 0; i < soLuong; ++i) {
      if (dsMoTo[i].getNhaSanXuat() == nsx) ++xeTimThay;
    }

    soLuongTimThay = xeTimThay;
    if (xeTimThay == 0) return nullptr;

    MoTo *dsXeTimThay = new MoTo[xeTimThay];

    int temp = 0;
    for (int i = 0; i < soLuong; ++i) {
      if (dsMoTo[i].getNhaSanXuat() == nsx) {
        dsXeTimThay[temp++] = dsMoTo[i];
      }
    }

    return dsXeTimThay;
  }
};