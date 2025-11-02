#pragma once
#include <iostream>
#include <string>

using namespace std;

class DichVu {
protected:
	string tenDichVu;
public:
	DichVu(string ten): tenDichVu(ten) {}

	virtual void xuat() const {
		cout << "Dich vu: " << tenDichVu << endl;
	}

	virtual float tinhTien() const = 0;

	virtual ~DichVu() {}
};
