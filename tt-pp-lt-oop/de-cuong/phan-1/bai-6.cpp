#include <cmath>
#include <iostream>
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
  void xuat() { cout << "(" << x << ", " << y << ")"; }

  // Tính khoảng cách từ điểm hiện tại đến điểm p2
  double tinhKhoangCach(Point p2) {
    double dx = p2.x - this->x;
    double dy = p2.y - this->y;
    return sqrt(dx * dx + dy * dy);
  }

  // Getter
  double getX() { return x; }

  double getY() { return y; }
};

class Triangle {
 private:
  Point p1, p2, p3;  // 3 đỉnh của tam giác

 public:
  // Constructor mặc định
  Triangle() : p1(), p2(), p3() {}

  // Constructor có tham số
  Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c) {}

  // Nhập 3 đỉnh tam giác
  void nhap() {
    cout << "Nhap dinh thu nhat (A):\n";
    p1.nhap();
    cout << "\nNhap dinh thu hai (B):\n";
    p2.nhap();
    cout << "\nNhap dinh thu ba (C):\n";
    p3.nhap();
  }

  // Xuất 3 đỉnh tam giác
  void xuat() {
    cout << "Dinh A: ";
    p1.xuat();
    cout << endl;
    cout << "Dinh B: ";
    p2.xuat();
    cout << endl;
    cout << "Dinh C: ";
    p3.xuat();
    cout << endl;
  }

  // Tính chu vi tam giác
  // Chu vi = a + b + c (tổng 3 cạnh)
  double tinhChuVi() {
    double a = p1.tinhKhoangCach(p2);  // Cạnh AB
    double b = p2.tinhKhoangCach(p3);  // Cạnh BC
    double c = p3.tinhKhoangCach(p1);  // Cạnh CA

    return a + b + c;
  }

  // Tính diện tích tam giác
  // Sử dụng công thức Heron: S = sqrt(p(p-a)(p-b)(p-c))
  // Với p = (a+b+c)/2 (nửa chu vi)
  double tinhDienTich() {
    double a = p1.tinhKhoangCach(p2);  // Cạnh AB
    double b = p2.tinhKhoangCach(p3);  // Cạnh BC
    double c = p3.tinhKhoangCach(p1);  // Cạnh CA

    double p = (a + b + c) / 2.0;  // Nửa chu vi

    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  // Kiểm tra có phải tam giác hợp lệ không
  // Điều kiện: tổng 2 cạnh > cạnh còn lại
  bool isValid() {
    double a = p1.tinhKhoangCach(p2);
    double b = p2.tinhKhoangCach(p3);
    double c = p3.tinhKhoangCach(p1);

    return (a + b > c) && (b + c > a) && (c + a > b);
  }
};

int main() {
  Triangle t1;

  cout << "=== NHAP TAM GIAC ===\n";
  t1.nhap();

  cout << "\n=== THONG TIN TAM GIAC ===\n";
  t1.xuat();

  if (!t1.isValid()) {
    cout << "\nLoi: Ba diem khong tao thanh tam giac hop le!\n";
    return 1;
  }

  cout << "\nChu vi tam giac: " << t1.tinhChuVi() << endl;
  cout << "Dien tich tam giac: " << t1.tinhDienTich() << endl;

  // Test với tam giác vuông cạnh 3-4-5
  cout << "\n=== TEST VOI TAM GIAC VUONG 3-4-5 ===\n";
  Point    a(0, 0);
  Point    b(3, 0);
  Point    c(0, 4);
  Triangle t2(a, b, c);

  t2.xuat();
  cout << "\nChu vi: " << t2.tinhChuVi() << endl;
  cout << "(Ket qua mong doi: 12)\n";
  cout << "Dien tich: " << t2.tinhDienTich() << endl;
  cout << "(Ket qua mong doi: 6)\n";

  return 0;
}
