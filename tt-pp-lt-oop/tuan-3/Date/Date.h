#pragma once
#include <iostream>

using namespace std;

class Date {
 private:
  int ngay, thang, nam;

 public:
  Date() {}

  Date(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}

  void nhap() {
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
  }

  void xuat() const { cout << ngay << "/" << thang << "/" << nam << endl; }

  Date getNgayTruoc() const {
    if (!dateHopLe()) {
      cout << "Thong tin nhap vao khong hop le!\n";
      return Date(0, 0, 0);
    }

    int prevNgay = ngay - 1, prevThang = thang, prevNam = nam;

    if (prevNgay == 0) {
      prevThang--;
      if (prevThang == 0) {
        prevNam--;
        prevThang = 12;
      }

      if (prevThang == 2) {
        prevNgay = laNamNhuan() ? 29 : 28;
      } else if (prevThang == 4 || prevThang == 6 || prevThang == 9 || prevThang == 11)
        prevNgay = 30;
      else
        prevNgay = 31;
    }

    return Date(prevNgay, prevThang, prevNam);
  }

  Date getNgaySau() const {
    if (!dateHopLe()) {
      cout << "Thong tin nhap vao khong hop le!\n";
      return Date(0, 0, 0);
    }

    int nextNgay = ngay + 1, nextThang = thang, nextNam = nam;

    int ngayTrongThang;
    if (thang == 2)
      ngayTrongThang = laNamNhuan() ? 29 : 28;
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
      ngayTrongThang = 30;
    else
      ngayTrongThang = 31;

    if (nextNgay > ngayTrongThang) {
      nextNgay = 1;
      nextThang++;
      if (nextThang > 12) {
        nextThang = 1;
        nextNam++;
      }
    }

    return Date(nextNgay, nextThang, nextNam);
  }

 private:
  bool dateHopLe() const {
    if (ngay < 1 || ngay > 31 || thang < 1 || thang > 12) return false;
    if (thang == 2) {
      if (laNamNhuan()) {
        if (ngay > 29) return false;
      } else {
        if (ngay > 28) return false;
      }
    }
    if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30) return false;
    return true;
  }

  bool laNamNhuan() const { return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0); }
};
