#pragma once
#include <ctime>

#include "Nguoi.h"

enum class ChuyenMon { TU_NHIEN, XA_HOI };

class GiaoVien : public Nguoi {
 private:
  int       namBatDauDay;
  ChuyenMon chuyenMon;

 public:
  void nhap() {
    Nguoi::nhap();
    cout << "  Nhap nam bat dau day: ";
    cin >> namBatDauDay;

    int chonMon;
    cout << "  Chon chuyen mon (1: Tu nhien, 2: Xa hoi): ";
    cin >> chonMon;
    if (chonMon == 1) {
      chuyenMon = ChuyenMon::TU_NHIEN;
    } else {
      chuyenMon = ChuyenMon::XA_HOI;
    }
  }

  void xuat() {
    cout << "--- Thong tin Giao Vien ---" << endl;
    Nguoi::xuat();

    cout << "  Nam bat dau day: " << namBatDauDay << endl;
    cout << "  Chuyen mon: "
         << (chuyenMon == ChuyenMon::TU_NHIEN ? "Tu Nhien" : "Xa Hoi") << endl;
  }

  int getNamBatDauDay() const { return namBatDauDay; }

  ChuyenMon getChuyenMon() const { return chuyenMon; }

  void setNamBatDauDay(const int& nam) { namBatDauDay = nam; }

  void setChuyenMon(const ChuyenMon& mon) { chuyenMon = mon; }

  int tinhThamNien() const {
    // time(nullptr) trả về số giây tính từ 00:00:00 ngày 1/1/1970
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // tm_year là số năm KỂ TỪ NĂM 1900.
    int namHienTai = 1900 + now->tm_year;

    return namHienTai - namBatDauDay;
  }
};
