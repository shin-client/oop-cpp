#pragma once
#include <iostream>

using namespace std;

class MyIntArray {
 private:
  int *m_pArr;
  int  m_iSize;

 public:
  MyIntArray() : m_pArr(nullptr), m_iSize(0) {}

  MyIntArray(int iSize) : m_iSize(iSize) {
    m_pArr = new int[iSize];
    for (int i = 0; i < m_iSize; ++i) {
      m_pArr[i] = 0;
    }
  }

  MyIntArray(int *p, int iSize) : m_iSize(iSize) {
    m_pArr = new int[iSize];

    for (int i = 0; i < m_iSize; ++i) {
      m_pArr[i] = p[i];
    }
  }

  MyIntArray(MyIntArray *A) {
    m_iSize = A->m_iSize;
    m_pArr  = new int[m_iSize];

    for (int i = 0; i < m_iSize; ++i) {
      m_pArr[i] = A->m_pArr[i];
    }
  }

  ~MyIntArray() {
    if (m_iSize > 0) {
      m_iSize = 0;
      delete[] m_pArr;
      m_pArr = nullptr;
    }
  }

  friend istream &operator>>(istream &in, MyIntArray *A) {
    cout << "Nhap so phan tu: ";
    in >> A->m_iSize;
    A->m_pArr = new int[A->m_iSize];
    for (int i = 0; i < A->m_iSize; ++i) {
      cout << "Nhap phan tu " << i << ": ";
      in >> A->m_pArr[i];
    }
    return in;
  }

  friend ostream &operator<<(ostream &out, MyIntArray *A) {
    out << "\nSo phan tu: " << A->m_iSize << endl;
    for (int i = 0; i < A->m_iSize; ++i) {
      out << A->m_pArr[i] << " ";
    }
    return out;
  }

  int &operator[](const int idx) { return m_pArr[idx]; }

  int GetLenght() const { return m_iSize; }

  int FindFirst(int n) const {
    int kq = -1;
    for (int i = 0; i < m_iSize; ++i) {
      if (m_pArr[i] == n) {
        kq = i;
        break;
      }
    }
    return kq;
  }

  int FindMax() {
    int max = m_pArr[0];
    for (int i = 0; i < m_iSize; ++i) {
      if (m_pArr[i] > max) max = m_pArr[i];
    }
    return max;
  }

  int FindMin() {
    int min = m_pArr[0];
    for (int i = 0; i < m_iSize; ++i) {
      if (m_pArr[i] < min) min = m_pArr[i];
    }
    return min;
  }

  bool Add(int n) {
    bool kq = false;
    int *p  = new int[m_iSize + 1];
    if (p != nullptr) {
      for (int i = 0; i < m_iSize; ++i) p[i] = m_pArr[i];

      p[m_iSize] = n;

      delete[] m_pArr;

      m_iSize++;
      m_pArr = new int[m_iSize];

      if (m_pArr != nullptr) {
        for (int i = 0; i < m_iSize; ++i) m_pArr[i] = p[i];
        kq = true;
      }
    }
    return kq;
  }

  bool Insert(int n, int idx) {
    bool kq = false;
    int *p  = new int[m_iSize + 1];

    if (p != nullptr && idx <= m_iSize) {
      for (int i = 0; i < idx; ++i) p[i] = m_pArr[i];

      p[idx] = n;

      for (int i = idx + 1; i < m_iSize + 1; ++i) p[i] = m_pArr[i - 1];

      delete[] m_pArr;
      m_pArr = nullptr;

      m_iSize++;
      m_pArr = new int[m_iSize];

      if (m_pArr != nullptr) {
        for (int i = 0; i < m_iSize; ++i) m_pArr[i] = p[i];
        kq = true;
      }
    }
    return kq;
  }

  bool Remove(int idx) {
    bool kq = false;

    int *p = new int[m_iSize - 1];

    if (p != nullptr && idx <= m_iSize) {
      for (int i = 0; i < idx; ++i) p[i] = m_pArr[i];

      for (int i = idx; i < m_iSize - 1; ++i) p[i] = m_pArr[i + 1];

      delete[] m_pArr;
      m_pArr = nullptr;

      m_iSize--;
      m_pArr = new int[m_iSize];

      if (m_pArr != nullptr) {
        for (int i = 0; i < m_iSize; ++i) m_pArr[i] = p[i];
        kq = true;
      }
    }
    return kq;
  }

  bool RemoveAll() {
    bool kq = false;

    if (m_iSize > 0) {
      delete[] m_pArr;
      m_pArr = nullptr;
      kq     = true;
    }
    return kq;
  }

  void Sort() {
    int iSize = m_iSize;
    for (int i = 0; i < iSize - 1; ++i) {
      for (int j = i + 1; j < iSize; ++j) {
        if (m_pArr[i] > m_pArr[j]) {
          int temp  = m_pArr[i];
          m_pArr[i] = m_pArr[j];
          m_pArr[j] = temp;
        }
      }
    }
  }
};
