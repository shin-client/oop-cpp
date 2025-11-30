#include <iomanip>
#include <iostream>
using namespace std;

class Time {
 private:
  int gio;
  int phut;
  int giay;

 public:
  // Constructor mặc định
  Time() : gio(0), phut(0), giay(0) {}

  // Constructor có tham số
  Time(int g, int p, int s) : gio(g), phut(p), giay(s) {
    // Kiểm tra tính hợp lệ
    if (g < 0 || g > 23) gio = 0;
    if (p < 0 || p > 59) phut = 0;
    if (s < 0 || s > 59) giay = 0;
  }

  // Nhập thời gian
  void nhap() {
    cout << "Nhap gio (0-23): ";
    cin >> gio;
    cout << "Nhap phut (0-59): ";
    cin >> phut;
    cout << "Nhap giay (0-59): ";
    cin >> giay;

    // Kiểm tra tính hợp lệ
    if (gio < 0 || gio > 23) gio = 0;
    if (phut < 0 || phut > 59) phut = 0;
    if (giay < 0 || giay > 59) giay = 0;
  }

  // Xuất thời gian theo định dạng HH:MM:SS
  void xuat() {
    cout << setfill('0') << setw(2) << gio << ":" << setw(2) << phut << ":"
         << setw(2) << giay << endl;
  }

  // Tăng thời gian lên 1 giây
  void nextSecond() {
    giay++;

    // Xử lý khi giây vượt quá 59
    if (giay > 59) {
      giay = 0;
      phut++;

      // Xử lý khi phút vượt quá 59
      if (phut > 59) {
        phut = 0;
        gio++;

        // Xử lý khi giờ vượt quá 23 (quay lại 00:00:00)
        if (gio > 23) {
          gio = 0;
        }
      }
    }
  }
};

int main() {
  Time t1;

  cout << "Nhap thoi gian:\n";
  t1.nhap();

  cout << "\nThoi gian hien tai: ";
  t1.xuat();

  cout << "\nThoi gian sau 1 giay: ";
  t1.nextSecond();
  t1.xuat();

  // Test trường hợp đặc biệt 23:59:59
  cout << "\n--- Test truong hop 23:59:59 ---\n";
  Time t2(23, 59, 59);
  cout << "Thoi gian: ";
  t2.xuat();
  cout << "Sau 1 giay: ";
  t2.nextSecond();
  t2.xuat();

  // Test trường hợp 12:59:59
  cout << "\n--- Test truong hop 12:59:59 ---\n";
  Time t3(12, 59, 59);
  cout << "Thoi gian: ";
  t3.xuat();
  cout << "Sau 1 giay: ";
  t3.nextSecond();
  t3.xuat();

  return 0;
}
