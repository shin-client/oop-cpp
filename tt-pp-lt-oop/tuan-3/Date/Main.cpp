#include "Date.h"

int main() {
  Date today;

  today.nhap();

  Date homQua = today.getNgayTruoc();
  Date homSau = today.getNgaySau();

  homQua.xuat();
  homSau.xuat();
}