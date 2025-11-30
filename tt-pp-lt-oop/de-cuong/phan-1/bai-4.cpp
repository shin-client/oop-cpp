#include <iostream>
using namespace std;

class Date {
 private:
  int ngay;
  int thang;
  int nam;

 public:
  // Constructor mặc định
  Date() : ngay(1), thang(1), nam(2000) {}

  // Constructor có tham số
  Date(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

  // Nhập ngày tháng năm
  void nhap() {
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
  }

  // Xuất ngày tháng năm
  void xuat() { cout << ngay << "/" << thang << "/" << nam << endl; }

  // Kiểm tra năm nhuận
  bool isLeapYear() {
    // Năm nhuận: chia hết cho 4 NHƯNG không chia hết cho 100
    // HOẶC chia hết cho 400
    if (nam % 400 == 0) {
      return true;
    }
    if (nam % 100 == 0) {
      return false;
    }
    if (nam % 4 == 0) {
      return true;
    }
    return false;
  }

  // Kiểm tra năm nhuận (static - có thể gọi mà không cần object)
  static bool isLeapYear(int year) {
    if (year % 400 == 0) {
      return true;
    }
    if (year % 100 == 0) {
      return false;
    }
    if (year % 4 == 0) {
      return true;
    }
    return false;
  }

  // Lấy số ngày trong tháng (tính cả năm nhuận)
  int getDaysInMonth() {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (thang == 2 && isLeapYear()) {
      return 29;
    }

    if (thang >= 1 && thang <= 12) {
      return daysInMonth[thang];
    }

    return 0;
  }

  // Kiểm tra ngày có hợp lệ không
  bool isValid() {
    if (nam < 1) return false;
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > getDaysInMonth()) return false;
    return true;
  }
};

int main() {
  Date d1;

  cout << "Nhap ngay thang nam:\n";
  d1.nhap();

  cout << "\nNgay vua nhap: ";
  d1.xuat();

  // Kiểm tra năm nhuận
  if (d1.isLeapYear()) {
    cout << "Nam nay LA nam nhuan.\n";
  } else {
    cout << "Nam nay KHONG phai nam nhuan.\n";
  }

  // Kiểm tra tính hợp lệ
  if (d1.isValid()) {
    cout << "Ngay hop le.\n";
  } else {
    cout << "Ngay khong hop le.\n";
  }

  cout << "\n--- Test cac nam nhuan ---\n";
  // Test các năm đặc biệt
  int testYears[] = {2000, 1900, 2024, 2023, 2100, 2400};

  for (int year : testYears) {
    if (Date::isLeapYear(year)) {
      cout << year << " la nam nhuan\n";
    } else {
      cout << year << " khong phai nam nhuan\n";
    }
  }

  return 0;
}
