#include <iostream>
#include <string>
using namespace std;

class SinhVien {
 private:
  string maSo;
  string hoTen;
  float  diemTB;

 public:
  // Member Initializer List (Danh sách khởi tạo thành viên)
  SinhVien() : maSo(""), hoTen(""), diemTB(0) {}

  SinhVien(string ms, string ht, float dtb)
      : maSo(ms), hoTen(ht), diemTB(dtb) {}

  SinhVien(const SinhVien &sv)
      : maSo(sv.maSo), hoTen(sv.hoTen), diemTB(sv.diemTB) {}

  void nhap() {
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, maSo);
    cout << "Nhap Ho Ten: ";
    getline(cin, hoTen);
    cout << "Nhap DTB: ";
    cin >> diemTB;
  }

  void xuat() {
    cout << "MSSV: " << maSo << endl;
    cout << "Ten: " << hoTen << endl;
    cout << "DTB: " << diemTB << endl;
  }

  float getDTB() { return diemTB; }

  void setDTB(float dtb) {
    if (dtb < 0 && dtb > 10) return;
    diemTB = dtb;
  }
};

int main() {
  SinhVien sv1, sv2;
  cout << "Nhap SV 1:\n";
  sv1.nhap();
  cout << "Nhap SV 2:\n";
  sv2.nhap();

  if (sv1.getDTB() > sv2.getDTB())
    cout << "SV1 co diem cao hon.";
  else if (sv1.getDTB() < sv2.getDTB())
    cout << "SV2 co diem cao hon.";
  else
    cout << "Hai SV diem bang nhau.";
  return 0;
}
