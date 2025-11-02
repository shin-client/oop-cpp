#include "DichVuDienThoai.h"
#include "DichVuThueXe.h"

int main() {
    DichVu* dv = nullptr;
    int luaChon;
    int thoiGian;
    string loai;

    do {
        cout << "\nChon loai dich vu:" << endl;
        cout << "1. Thue Xe" << endl;
        cout << "2. Dien Thoai" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        delete dv;
        dv = nullptr;

        switch (luaChon) {
        case 1: {
            cout << "Nhap loai thue (gio/ngay): ";
            cin >> loai;
            cout << "Nhap thoi gian su dung (so gio/ngay): ";
            cin >> thoiGian;
            dv = new DichVuThueXe(thoiGian, loai);
            break;
        }
        case 2: {
            cout << "Nhap loai cuoc goi (trong nuoc/ngoai nuoc): ";
            cin.ignore();
            getline(cin, loai);
            cout << "Nhap so phut goi: ";
            cin >> thoiGian;
            dv = new DichVuDienThoai(thoiGian, loai);
            break;
        }
        case 0: {
            cout << "Cam on da su dung chuong trinh!" << endl;
            break;
        }
        default: {
            cout << "Lua chon khong hop le. Vui long chon loi!." << endl;
            break;
        }
        }

        if (dv != nullptr) {
            dv->xuat();
            cout << "=> **THANH TIEN:** " << dv->tinhTien() << " VND" << endl;
        }

    } while (luaChon != 0);

    delete dv;

    return 0;
}