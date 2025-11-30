#include <iostream>
#include <string>
using namespace std;

class SinhVien {
 private:
  string maSV;
  string hoTen;
  float diemTrungBinh;

 public:
  // Constructor
  SinhVien() : maSV(""), hoTen(""), diemTrungBinh(0) {}

  SinhVien(string ma, string ten, float diem)
      : maSV(ma), hoTen(ten), diemTrungBinh(diem) {}

  // Nhập thông tin sinh viên
  void nhap() {
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, maSV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap diem TB: ";
    cin >> diemTrungBinh;
  }

  // Khai báo LopHoc là friend class
  // LopHoc có thể truy cập TẤT CẢ thuộc tính private của SinhVien
  friend class LopHoc;
};

class LopHoc {
 private:
  string tenLop;
  SinhVien* danhSach;  // Mảng động các obj sinh viên
  int soLuong;

 public:
  // Constructor
  LopHoc() : tenLop(""), danhSach(nullptr), soLuong(0) {}

  LopHoc(string ten, int sl) : tenLop(ten), soLuong(sl) {
    danhSach = new SinhVien[soLuong];
  }

  // Destructor
  ~LopHoc() {
    if (danhSach != nullptr) {
      delete[] danhSach;
    }
  }

  // Nhập danh sách lớp
  void nhapDanhSach() {
    cout << "Nhap ten lop: ";
    cin.ignore();
    getline(cin, tenLop);
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;

    // Giải phóng bộ nhớ cũ trước khi cấp phát mới
    // Tránh memory leak khi gọi nhapDanhSach() nhiều lần
    if (danhSach != nullptr) {
      delete[] danhSach;
      danhSach = nullptr;
    }

    danhSach = new SinhVien[soLuong];

    for (int i = 0; i < soLuong; i++) {
      cout << "\n--- Sinh vien thu " << (i + 1) << " ---\n";
      danhSach[i].nhap();
    }
  }

  // Phương thức in danh sách lớp
  // Có thể truy cập thuộc tính PRIVATE của SinhVien vì LopHoc là friend class
  void inDanhSachLop() {
    cout << "\n========================================\n";
    cout << "DANH SACH LOP: " << tenLop << endl;
    cout << "So luong sinh vien: " << soLuong << endl;
    cout << "========================================\n";

    for (int i = 0; i < soLuong; i++) {
      cout << "\nSinh vien " << (i + 1) << ":\n";

      // Truy cập TRỰC TIẾP vào thuộc tính private của SinhVien
      // Điều này CHỈ được phép vì LopHoc là friend class
      cout << "  MSSV: " << danhSach[i].maSV << endl;
      cout << "  Ho ten: " << danhSach[i].hoTen << endl;
      cout << "  Diem TB: " << danhSach[i].diemTrungBinh << endl;
    }
  }

  // Tìm sinh viên có điểm cao nhất
  void timSinhVienGioi() {
    if (soLuong == 0) return;

    int indexMax = 0;
    for (int i = 1; i < soLuong; i++) {
      // Truy cập private member diemTrungBinh
      if (danhSach[i].diemTrungBinh > danhSach[indexMax].diemTrungBinh) {
        indexMax = i;
      }
    }

    cout << "\n=== SINH VIEN CO DIEM CAO NHAT ===\n";
    cout << "MSSV: " << danhSach[indexMax].maSV << endl;
    cout << "Ho ten: " << danhSach[indexMax].hoTen << endl;
    cout << "Diem TB: " << danhSach[indexMax].diemTrungBinh << endl;
  }
};

int main() {
  LopHoc lop;

  cout << "=== NHAP THONG TIN LOP HOC ===\n";
  lop.nhapDanhSach();

  // In danh sách lớp (LopHoc có thể truy cập private của SinhVien)
  lop.inDanhSachLop();

  // Tìm sinh viên giỏi
  lop.timSinhVienGioi();

  // ===== TEST: Thử truy cập trực tiếp từ main =====
  cout << "\n\n=== THU NGHIEM: TRUY CAP PRIVATE TU MAIN ===\n";

  SinhVien sv;

  // DÒNG CODE SAI - SẼ BỊ LỖI BIÊN DỊCH
  // Bỏ comment để thấy lỗi:

  // sv.diemTrungBinh = 9.5;
  // cout << sv.maSV;

  /*
   * LỖI BIÊN DỊCH:
   * error: 'float SinhVien::diemTrungBinh' is private within this context
   * error: 'std::string SinhVien::maSV' is private within this context
   *
   * GIẢI THÍCH:
   * - Thuộc tính diemTrungBinh, maSV, hoTen được khai báo PRIVATE
   * - Hàm main() KHÔNG phải là friend của SinhVien
   * - Chỉ có LopHoc (friend class) mới được truy cập private members
   * - Từ main(), chỉ có thể dùng public methods như nhap(), không thể
   *   truy cập trực tiếp vào private members
   *
   * KẾT LUẬN:
   * - Private members CHỈ truy cập được từ:
   *   + Bên trong chính class đó
   *   + Friend functions/classes đã được khai báo
   * - Mọi code khác (kể cả main) đều BỊ CHẶN truy cập
   * - Đây là cơ chế ĐÓNG GÓI (Encapsulation) trong OOP
   */

  cout << "Neu ban uncomment dong sv.diemTrungBinh = 9.5;\n";
  cout << "Trinh bien dich se bao loi:\n";
  cout << "  'float SinhVien::diemTrungBinh' is private\n";
  cout << "\nLy do: main() KHONG phai la friend cua SinhVien!\n";

  return 0;
}
