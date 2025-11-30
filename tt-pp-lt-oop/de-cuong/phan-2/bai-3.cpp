#include <iostream>
using namespace std;

class MaTran {
 private:
  int   soHang;
  int   soCot;
  int **data;  // Con trỏ mảng 2 chiều

 public:
  // Constructor mặc định
  MaTran() : soHang(0), soCot(0), data(nullptr) {}

  // Constructor có tham số
  MaTran(int h, int c) : soHang(h), soCot(c) {
    // Cấp phát bộ nhớ cho mảng 2 chiều
    data = new int *[soHang];
    for (int i = 0; i < soHang; i++) {
      data[i] = new int[soCot];
      // Khởi tạo giá trị 0
      for (int j = 0; j < soCot; j++) {
        data[i][j] = 0;
      }
    }
  }

  // Copy constructor
  MaTran(const MaTran &other) : soHang(other.soHang), soCot(other.soCot) {
    data = new int *[soHang];
    for (int i = 0; i < soHang; i++) {
      data[i] = new int[soCot];
      for (int j = 0; j < soCot; j++) {
        data[i][j] = other.data[i][j];
      }
    }
  }

  // Destructor - giải phóng bộ nhớ
  ~MaTran() {
    if (data != nullptr) {
      for (int i = 0; i < soHang; i++) {
        delete[] data[i];
      }
      delete[] data;
    }
  }

  // Nhập ma trận
  void nhap() {
    cout << "Nhap so hang: ";
    cin >> soHang;
    cout << "Nhap so cot: ";
    cin >> soCot;

    // Cấp phát bộ nhớ
    data = new int *[soHang];
    for (int i = 0; i < soHang; i++) {
      data[i] = new int[soCot];
    }

    // Nhập dữ liệu
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < soHang; i++) {
      for (int j = 0; j < soCot; j++) {
        cout << "Phan tu [" << i << "][" << j << "]: ";
        cin >> data[i][j];
      }
    }
  }

  // Xuất ma trận
  void xuat() const {
    for (int i = 0; i < soHang; i++) {
      for (int j = 0; j < soCot; j++) {
        cout << data[i][j] << "\t";
      }
      cout << endl;
    }
  }

  // Getter
  int getSoHang() const { return soHang; }

  int getSoCot() const { return soCot; }

  // Khai báo hàm bạn
  friend MaTran congMaTran(const MaTran &a, const MaTran &b) {
    // Kiểm tra điều kiện cộng ma trận: cùng kích thước
    if (a.soHang != b.soHang || a.soCot != b.soCot) {
      cout << "Loi: Hai ma tran phai cung kich thuoc!\n";
      return MaTran();  // Trả về ma trận rỗng
    }

    // Tạo ma trận kết quả
    MaTran ketQua(a.soHang, a.soCot);

    // Cộng từng phần tử
    for (int i = 0; i < a.soHang; i++) {
      for (int j = 0; j < a.soCot; j++) {
        ketQua.data[i][j] = a.data[i][j] + b.data[i][j];
      }
    }

    return ketQua;
  };
};
