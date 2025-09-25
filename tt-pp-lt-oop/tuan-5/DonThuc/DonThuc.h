#pragma once
#include <iostream>

using namespace std;

class DonThuc {
 private:
  int ax, b;

 public:
  DonThuc() : ax(0), b(0) {}

  DonThuc(int ax, int b) : ax(ax), b(b) {}

  ~DonThuc() {}

  int getAx() const { return ax; }

  int getB() const { return b; }

  void setAx(int ax) { this->ax = ax; }

  void setB(int b) { this->b = b; }

  friend istream& operator>>(istream& in, DonThuc& dt) {
    cout << "Nhap ax: ";
    in >> dt.ax;
    cout << "Nhap b: ";
    in >> dt.b;
    return in;
  }

  friend ostream& operator<<(ostream& out, const DonThuc& dt) {
    cout << dt.ax << "x" << " + " << dt.b << endl;
    return out;
  }

  DonThuc operator+(const DonThuc& dt) const { return DonThuc(ax + dt.ax, b + dt.b); }

  DonThuc operator-(const DonThuc& dt) const { return DonThuc(ax - dt.ax, b - dt.b); }
};
