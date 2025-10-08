#pragma once
#include <iostream>
#include <string>

using namespace std;

class HocSinh {
 private:
  string maHS, hoTen;
  float  diemToan, diemVan;

 public:
  HocSinh() : maHS(""), hoTen(""), diemToan(0), diemVan(0) {}

  HocSinh(const string& maHS, const string& hoTen, const float& diemToan,
          const float& diemVan)
      : maHS(maHS), hoTen(hoTen), diemToan(diemToan), diemVan(diemVan) {}

  string getMaHS() const { return maHS; }

  string getHoTen() const { return hoTen; }

  float getDiemToan() const { return diemToan; }

  float getDiemVan() const { return diemVan; }

  void setMaHS(const string& maHS) { this->maHS = maHS; }

  void setHoTen(const string& hoTen) { this->hoTen = hoTen; }

  void setDiemToan(const float& diemToan) { this->diemToan = diemToan; }

  void setDiemVan(const float& diemVan) { this->diemVan = diemVan; }

  friend istream& operator>>(istream& in, HocSinh& hs) {
    cout << "Nhap ho ten: ";
    getline(in, hs.hoTen);
    cout << "Nhap diem Toan: ";
    in >> hs.diemToan;
    cout << "Nhap diem Van: ";
    in >> hs.diemVan;
    in.ignore();
    return in;
  }

  friend ostream& operator<<(ostream& out, const HocSinh& hs) {
    out << "Ho ten: " << hs.hoTen << endl;
    out << "Diem Toan: " << hs.diemToan << endl;
    out << "Diem Van: " << hs.diemVan << endl;
    out << "Diem TB: " << hs.tinhDiemTrungBinh() << endl;
    out << "Xep loai: " << hs.tinhXepLoai() << endl;
    return out;
  }

  float tinhDiemTrungBinh() const { return (diemToan + diemVan) / 2; }

  string tinhXepLoai() const {
    float dtb = (diemToan + diemVan) / 2;
    if (dtb >= 8.0)
      return "Gioi";
    else if (dtb >= 6.5)
      return "Kha";
    else if (dtb >= 5.0)
      return "Trung Binh";
    else
      return "Yeu";
  }

  string getTen() const {
    size_t lastSpacePos = hoTen.find_last_of(" ");

    if (lastSpacePos != string::npos) return hoTen.substr(lastSpacePos + 1);

    return hoTen;
  }
};