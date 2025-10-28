#include "MyIntArray.h"

int main() {
  MyIntArray *a1 = new MyIntArray();
  cin >> a1;
  cout << a1;

  MyIntArray *a2 = new MyIntArray(3);
  cout << a2;

  MyIntArray *a3 = new MyIntArray(a1);
  cout << a3;

  cout << "\n\nTruy xuat phan tu thu idx (toan tu[]):";
  cout << "\nNhap idx: ";
  int idx;
  cin >> idx;
  int kq = (*a1)[idx];
  cout << "Phan tu thu " << idx << ": " << kq << endl;
  (*a1)[idx] = 5;

  cout << "\n\nVi tri xuat hien dau tien (Find First):";
  int pos, n;
  cout << "\nNhap n: ";
  cin >> n;
  pos = a1->FindFirst(n);
  cout << "Vi tri dau tien: " << pos;

  cout << "\n\nGia tri lon nhat (Find Max):";
  int max = a1->FindMax();
  cout << "\nGTLN: " << max;

  cout << "\n\nGia tri nho nhat (Find Min):";
  int min = a1->FindMin();
  cout << "\nGTNN: " << min;

  cout << "\n\nThem vao cuoi mang (Add):";
  cout << "\nNhap n: ";
  cin >> n;
  a1->Add(n);
  cout << a1;

  cout << "\n\nThem vao mang 1 phan tu tai vi tri idx (Insert):";
  cout << "\nNhap n: ";
  cin >> n;
  cout << "Nhap idx: ";
  cin >> idx;
  a1->Insert(n, idx);
  cout << a1;

  cout << "\n\nXoa phan tu thu idx (Remove):";
  cout << "\nNhap idx: ";
  cin >> idx;
  a1->Remove(idx);
  cout << a1;

  cout << "\n\nSap xep tang dan (Sort):";
  a1->Sort();
  cout << a1;

  cout << "\n\nXoa tat ca phan tu (RemoveAll):";
  a1->RemoveAll();
  cout << a1;

  delete a1;
  a1 = nullptr;
  system("pause");
}