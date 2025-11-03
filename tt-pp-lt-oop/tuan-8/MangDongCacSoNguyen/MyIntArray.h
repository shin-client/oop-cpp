#pragma once
#include <iostream>

using namespace std;

class MyIntArray {
 private:
  int *arr;
  int  size;

 public:
  MyIntArray() : arr(nullptr), size(0) {}

  MyIntArray(int iSize) : size(iSize) {
    arr = new int[iSize];
    for (int i = 0; i < size; ++i) {
      arr[i] = 0;
    }
  }

  MyIntArray(int *p, int iSize) : size(iSize) {
    arr = new int[iSize];

    for (int i = 0; i < size; ++i) {
      arr[i] = p[i];
    }
  }

  MyIntArray(MyIntArray *A) {
    size = A->size;
    arr  = new int[size];

    for (int i = 0; i < size; ++i) {
      arr[i] = A->arr[i];
    }
  }

  ~MyIntArray() {
    if (size > 0) {
      size = 0;
      delete[] arr;
      arr = nullptr;
    }
  }

  friend istream &operator>>(istream &in, MyIntArray *A) {
    cout << "Nhap so phan tu: ";
    in >> A->size;
    A->arr = new int[A->size];
    for (int i = 0; i < A->size; ++i) {
      cout << "Nhap phan tu " << i << ": ";
      in >> A->arr[i];
    }
    return in;
  }

  friend ostream &operator<<(ostream &out, MyIntArray *A) {
    out << "\nSo phan tu: " << A->size << endl;
    for (int i = 0; i < A->size; ++i) {
      out << A->arr[i] << " ";
    }
    return out;
  }

  int &operator[](const int idx) { return arr[idx]; }

  int GetLenght() const { return size; }

  int FindFirst(int n) const {
    int kq = -1;
    for (int i = 0; i < size; ++i) {
      if (arr[i] == n) {
        kq = i;
        break;
      }
    }
    return kq;
  }

  int FindMax() {
    int max = arr[0];
    for (int i = 0; i < size; ++i) {
      if (arr[i] > max) max = arr[i];
    }
    return max;
  }

  int FindMin() {
    int min = arr[0];
    for (int i = 0; i < size; ++i) {
      if (arr[i] < min) min = arr[i];
    }
    return min;
  }

  bool Add(int n) {
    bool kq = false;
    int *p  = new int[size + 1];
    if (p != nullptr) {
      for (int i = 0; i < size; ++i) p[i] = arr[i];

      p[size] = n;

      delete[] arr;

      size++;
      arr = new int[size];

      if (arr != nullptr) {
        for (int i = 0; i < size; ++i) arr[i] = p[i];
        kq = true;
      }
    }
    return kq;
  }

  bool Insert(int n, int idx) {
    bool kq = false;
    int *p  = new int[size + 1];

    if (p != nullptr && idx <= size) {
      for (int i = 0; i < idx; ++i) p[i] = arr[i];

      p[idx] = n;

      for (int i = idx + 1; i < size + 1; ++i) p[i] = arr[i - 1];

      delete[] arr;
      arr = nullptr;

      size++;
      arr = new int[size];

      if (arr != nullptr) {
        for (int i = 0; i < size; ++i) arr[i] = p[i];
        kq = true;
      }
    }
    return kq;
  }

  bool Remove(int idx) {
    bool kq = false;

    int *p = new int[size - 1];

    if (p != nullptr && idx <= size) {
      for (int i = 0; i < idx; ++i) p[i] = arr[i];

      for (int i = idx; i < size - 1; ++i) p[i] = arr[i + 1];

      delete[] arr;
      arr = nullptr;

      size--;
      arr = new int[size];

      if (arr != nullptr) {
        for (int i = 0; i < size; ++i) arr[i] = p[i];
        kq = true;
      }
    }
    return kq;
  }

  bool RemoveAll() {
    bool kq = false;

    if (size > 0) {
      delete[] arr;
      arr = nullptr;
      kq  = true;
    }
    return kq;
  }

  void Sort() {
    int iSize = size;
    for (int i = 0; i < iSize - 1; ++i) {
      for (int j = i + 1; j < iSize; ++j) {
        if (arr[i] > arr[j]) {
          int temp = arr[i];
          arr[i]   = arr[j];
          arr[j]   = temp;
        }
      }
    }
  }
};
