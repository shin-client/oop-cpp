#pragma once
#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    PhanSo() : tu(0), mau(1) {}

    PhanSo(int tu, int mau) : tu(tu), mau(mau) {}

    PhanSo(PhanSo *ps) {
        tu = ps->tu;
        mau = ps->mau;
    }

    ~PhanSo() { cout << "Ham huy da duoc chay!\n"; }

    friend istream& operator>>(istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.tu;
        cout << "Nhap mau so: ";
        in >> ps.mau;
        return in;
    }

    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        if (ps.tu == ps.mau)
            out << ps.tu;
        else
            out << ps.tu << "/" << ps.mau;
        return out;
    }

    void setTu(int tu) { this->tu = tu; }

    void setMau(int mau) { this->mau = mau; }

    int getTu() const { return tu; }

    int getMau() const { return mau; }

    PhanSo operator+(const PhanSo& ps) const { return PhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau).rutGon(); }

    PhanSo operator-(const PhanSo& ps) const { return PhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau).rutGon(); }

    PhanSo operator*(const PhanSo& ps) const { return PhanSo(tu * ps.tu, mau * ps.mau).rutGon(); }

    PhanSo operator/(const PhanSo& ps) const { return PhanSo(tu * ps.mau, mau * ps.tu).rutGon(); }

    bool operator>(const PhanSo& ps) const { return tu * ps.mau > ps.tu * mau; }

    bool operator<(const PhanSo& ps) const { return tu * ps.mau < ps.tu * mau; }

    bool operator>=(const PhanSo& ps) const { return !(*this < ps); }

    bool operator<=(const PhanSo& ps) const { return !(*this > ps); }

    bool operator==(const PhanSo& ps) const { return tu * ps.mau == ps.tu * mau; }

    bool operator!=(const PhanSo& ps) const { return !(*this == ps); }

private:
    int timUocChungLonNhat(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    PhanSo rutGon() {
        int ucln = timUocChungLonNhat(abs(tu), abs(mau));
        tu /= ucln;
        mau /= ucln;
        return PhanSo(tu, mau);
    }
};