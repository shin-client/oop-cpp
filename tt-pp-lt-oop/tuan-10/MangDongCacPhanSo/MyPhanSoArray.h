#pragma once
#include "PhanSo.h"

class MyPhanSoArray {
private:
	PhanSo** phanSoArr;
	int size;
	
	void clearArray() {
		if (phanSoArr != nullptr) {
			for (int i = 0; i < size; ++i) {
				delete phanSoArr[i];
			}

			delete[] phanSoArr;
		}
		phanSoArr = nullptr;
		size = 0;
	}
public:
	MyPhanSoArray() : phanSoArr(nullptr), size(0) {}

	MyPhanSoArray(int size) {
		this->size = (size > 0) ? size : 0;
		if (this->size > 0) {
			this->phanSoArr = new PhanSo * [this->size];
			for (int i = 0; i < this->size; ++i) {
				this->phanSoArr[i] = new PhanSo();
			}
		}
		else {
			this->phanSoArr = nullptr;
		}
	}

	MyPhanSoArray(PhanSo** p, int size) {
		this->size = (size > 0) ? size : 0;
		if (this->size > 0 && p != nullptr) {
			this->phanSoArr = new PhanSo * [this->size];
			for (int i = 0; i < this->size; ++i) {
				if (p[i] != nullptr) {
					this->phanSoArr[i] = new PhanSo(p[i]);
				}
				else {
					this->phanSoArr[i] = nullptr;
				}
			}
		}
		else {
			this->phanSoArr = nullptr;
		}
	}

	~MyPhanSoArray() { clearArray(); }

	void setSize(const int& newSize) {
		if (this->size != newSize) {
			clearArray();
			this->size = (newSize > 0) ? newSize : 0;
			if (this->size > 0) {
				this->phanSoArr = new PhanSo * [this->size];
				for (int i = 0; i < this->size; ++i) {
					this->phanSoArr[i] = new PhanSo();
				}
			}
		}
	}

	void setArr(PhanSo** ps, int newSize) {
		clearArray();
		this->size = (newSize > 0) ? newSize : 0;
		if (this->size > 0 && ps != nullptr) {
			this->phanSoArr = new PhanSo * [this->size];
			for (int i = 0; i < this->size; ++i) {
				if (ps[i] != nullptr) {
					this->phanSoArr[i] = new PhanSo(ps[i]);
				}
				else {
					this->phanSoArr[i] = nullptr;
				}
			}
		}
	}

	int getSize() const { return size; }

	PhanSo** getArr() const { return phanSoArr; }

	friend istream& operator>>(istream& in, MyPhanSoArray* myA) {
		if (myA == nullptr) return in;

		myA->clearArray();

		cout << "Nhap kich thuoc mang: ";
		in >> myA->size;

		if (myA->size > 0) {
			myA->phanSoArr = new PhanSo * [myA->size];
			cout << "Nhap " << myA->size << " phan so:\n";
			for (int i = 0; i < myA->size; ++i) {
				cout << "Phan so thu " << i + 1 << ": ";
				myA->phanSoArr[i] = new PhanSo();
				in >> *(myA->phanSoArr[i]);
			}
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const MyPhanSoArray* myA) {
		if (myA == nullptr) {
			out << "NULL Array";
			return out;
		}

		out << "[";
		for (int i = 0; i < myA->size; ++i) {
			if (myA->phanSoArr[i] != nullptr) {
				out << *(myA->phanSoArr[i]);
			}
			else {
				out << "NULL";
			}
			if (i < myA->size - 1) {
				out << ", ";
			}
		}
		out << "]";
		return out;
	}

	PhanSo* operator[](const int& idx) {
		if (idx < 0 || idx >= size) {
			return nullptr;
		}
		return phanSoArr[idx];
	}

	PhanSo* findMax() {
		if (size == 0) return nullptr;

		PhanSo* maxPs = nullptr;
		for (int i = 0; i < size; ++i) {
			if (phanSoArr[i] != nullptr) {
				if (maxPs == nullptr || *phanSoArr[i] > *maxPs) {
					maxPs = phanSoArr[i];
				}
			}
		}
		return maxPs;
	}

	PhanSo* findMin() {
		if (size == 0) return nullptr;

		PhanSo* minPs = nullptr;
		for (int i = 0; i < size; ++i) {
			if (phanSoArr[i] != nullptr) {
				if (minPs == nullptr || *phanSoArr[i] < *minPs) {
					minPs = phanSoArr[i];
				}
			}
		}
		return minPs;
	}

	// Them cuoi mang
	bool add(PhanSo* ps) {
		if (ps == nullptr) return false;

		PhanSo** newArr = new PhanSo * [size + 1];

		for (int i = 0; i < size; ++i) {
			newArr[i] = phanSoArr[i];
		}

		newArr[size] = new PhanSo(ps);

		delete[] phanSoArr;

		phanSoArr = newArr;
		size++;
		return true;
	}

	// Them dau mang
	bool insert(PhanSo* ps) {
		if (ps == nullptr) return false;

		PhanSo** newArr = new PhanSo * [size + 1];

		newArr[0] = new PhanSo(ps);

		for (int i = 0; i < size; ++i) {
			newArr[i + 1] = phanSoArr[i];
		}

		delete[] phanSoArr;
		phanSoArr = newArr;
		size++;
		return true;
	}

	bool remove(int idx) {
		if (idx < 0 || idx >= size || size == 0) return false;

		delete phanSoArr[idx];
		phanSoArr[idx] = nullptr;

		for (int i = idx; i < size - 1; ++i) {
			phanSoArr[i] = phanSoArr[i + 1];
		}

		size--;

		PhanSo** newArr = nullptr;
		if (size > 0) {
			newArr = new PhanSo * [size];
			for (int i = 0; i < size; ++i) {
				newArr[i] = phanSoArr[i];
			}
		}
		delete[] phanSoArr;
		phanSoArr = newArr;

		return true;
	}

	bool removeAll() {
		if (size == 0) return false;
		clearArray();
		return true;
	}

	void sort() {
		if (size <= 1) return;

		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - 1 - i; ++j) {
				if (phanSoArr[j] != nullptr && phanSoArr[j + 1] != nullptr) {
					if (*(phanSoArr[j]) > *(phanSoArr[j + 1])) {
						PhanSo* temp = phanSoArr[j];
						phanSoArr[j] = phanSoArr[j + 1];
						phanSoArr[j + 1] = temp;
					}
				}
			}
		}
	}
};
