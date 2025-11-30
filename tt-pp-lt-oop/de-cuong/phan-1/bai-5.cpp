#include <iostream>
#include <cmath>
using namespace std;

class Point {
 private:
  double x;
  double y;

 public:
  // Constructor mặc định
  Point() : x(0), y(0) {}

  // Constructor có tham số
  Point(double px, double py) : x(px), y(py) {}

  // Nhập tọa độ điểm
  void nhap() {
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
  }

  // Xuất tọa độ điểm
  void xuat() {
    cout << "(" << x << ", " << y << ")";
  }

  // Tính khoảng cách từ điểm hiện tại đến điểm p2
  // Công thức: d = sqrt((x2-x1)^2 + (y2-y1)^2)
  double tinhKhoangCach(Point p2) {
    double dx = p2.x - this->x;
    double dy = p2.y - this->y;
    return sqrt(dx * dx + dy * dy);
  }

  // Tính khoảng cách từ điểm hiện tại đến gốc tọa độ (0, 0)
  double tinhKhoangCachDenGoc() {
    return sqrt(x * x + y * y);
  }

  // Getter
  double getX() { return x; }
  double getY() { return y; }

  // Setter
  void setX(double px) { x = px; }
  void setY(double py) { y = py; }
};

int main() {
  Point p1, p2;

  cout << "Nhap diem thu nhat (P1):\n";
  p1.nhap();

  cout << "\nNhap diem thu hai (P2):\n";
  p2.nhap();

  cout << "\n--- Ket qua ---\n";
  cout << "Diem P1: ";
  p1.xuat();
  cout << endl;

  cout << "Diem P2: ";
  p2.xuat();
  cout << endl;

  double khoangCach = p1.tinhKhoangCach(p2);
  cout << "\nKhoang cach tu P1 den P2: " << khoangCach << endl;

  cout << "Khoang cach tu P1 den goc toa do: " << p1.tinhKhoangCachDenGoc() << endl;
  cout << "Khoang cach tu P2 den goc toa do: " << p2.tinhKhoangCachDenGoc() << endl;

  // Test với các điểm cụ thể
  cout << "\n--- Test voi diem (3, 4) va (0, 0) ---\n";
  Point p3(3, 4);
  Point p4(0, 0);

  cout << "P3: ";
  p3.xuat();
  cout << endl;

  cout << "P4: ";
  p4.xuat();
  cout << endl;

  cout << "Khoang cach: " << p3.tinhKhoangCach(p4) << endl;
  cout << "(Ket qua mong doi: 5)\n";

  return 0;
}
