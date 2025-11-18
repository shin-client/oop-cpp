#pragma once
#include "Nguoi.h"

class HocSinh : public Nguoi {
 private:
  double diemToan;
  double diemVan;
  double diemNgoaiNgu;

 public:
  void nhap() {
    Nguoi::nhap();

    cout << "  Nhap diem Toan: ";
    cin >> diemToan;
    cout << "  Nhap diem Van: ";
    cin >> diemVan;
    cout << "  Nhap diem Ngoai ngu: ";
    cin >> diemNgoaiNgu;
  }

  void xuat() {
    cout << "--- Thong tin Hoc Sinh ---" << endl;
    Nguoi::xuat();

    cout << "  Diem Toan: " << diemToan << endl;
    cout << "  Diem Van: " << diemVan << endl;
    cout << "  Diem Ngoai ngu: " << diemNgoaiNgu << endl;
  }

  double getDiemToan() const { return diemToan; }

  double getDiemVan() const { return diemVan; }

  double getDiemNgoaiNgu() const { return diemNgoaiNgu; }

  void setDiemToan(double diem) { diemToan = diem; }

  void setDiemVan(double diem) { diemVan = diem; }

  void setDiemNgoaiNgu(double diem) { diemNgoaiNgu = diem; }

  double tinhDiemTrungBinh() const {
    return (diemToan + diemVan + diemNgoaiNgu) / 3.0;
  }

  string tinhXepLoai() const {
    double dtbHienTai = tinhDiemTrungBinh();
    if (dtbHienTai >= 9) return "Xuat sac";
    else if (dtbHienTai >= 8) return "Gioi";
    else if (dtbHienTai >= 7) return "Kha";
    else if (dtbHienTai >= 5) return "Trung binh";
    else return "Yeu";
  }
};
