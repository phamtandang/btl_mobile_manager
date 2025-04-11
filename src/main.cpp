#include "../include/models.h"
#include "../include/sanpham.h"
#include "../include/khachhang.h"
#include "../include/thongke.h"
#include "../include/utils.h"
#include <iostream>
#include <limits>

using namespace std;

// Khai báo các biến toàn cục
extern NodeSanPham* dsSanPham;
extern NodeKhachHang* dsKhachHang;

// Hàm để xử lý lựa chọn quản lý sản phẩm
void xuLyQuanLySanPham() {
    int luaChonSP;
    
    do {
        system("cls"); // Xóa màn hình (Windows)
        // Nếu dùng Linux/Mac, thay bằng system("clear");
        
        hienThiMenuSanPham();
        cin >> luaChonSP;
        
        // Xử lý lỗi đầu vào
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập số từ 0-7.\n";
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (luaChonSP) {
            case 1:
                hienThiDanhSachSanPham(dsSanPham);
                break;
            case 2:
                themSanPham(dsSanPham);
                break;
            case 3:
                suaSanPham(dsSanPham);
                break;
            case 4:
                xoaSanPham(dsSanPham);
                break;
            case 5:
                timKiemSanPham(dsSanPham);
                break;
            case 6:
                sapXepSanPham(dsSanPham);
                break;
            case 7:
                thongKeSanPham(dsSanPham);
                break;
            case 0:
                cout << "Quay lại menu chính.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng chọn từ 0-7.\n";
        }
        
        if (luaChonSP != 0) {
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
        }
    } while (luaChonSP != 0);
}

// Hàm để xử lý lựa chọn quản lý khách hàng
void xuLyQuanLyKhachHang() {
    int luaChonKH;
    
    do {
        system("cls"); // Xóa màn hình (Windows)
        // Nếu dùng Linux/Mac, thay bằng system("clear");
        
        hienThiMenuKhachHang();
        cin >> luaChonKH;
        
        // Xử lý lỗi đầu vào
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập số từ 0-6.\n";
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (luaChonKH) {
            case 1:
                hienThiDanhSachKhachHang(dsKhachHang);
                break;
            case 2:
                themKhachHang(dsKhachHang);
                break;
            case 3:
                suaKhachHang(dsKhachHang);
                break;
            case 4:
                xoaKhachHang(dsKhachHang);
                break;
            case 5:
                timKiemKhachHang(dsKhachHang);
                break;
            case 6:
                sapXepKhachHang(dsKhachHang);
                break;
            case 0:
                cout << "Quay lại menu chính.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng chọn từ 0-6.\n";
        }
        
        if (luaChonKH != 0) {
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
        }
    } while (luaChonKH != 0);
}

// Hàm để xử lý lựa chọn thống kê
void xuLyThongKe() {
    int luaChonTK;
    
    do {
        system("cls"); // Xóa màn hình (Windows)
        // Nếu dùng Linux/Mac, thay bằng system("clear");
        
        hienThiMenuThongKe();
        cin >> luaChonTK;
        
        // Xử lý lỗi đầu vào
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập số từ 0-3.\n";
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (luaChonTK) {
            case 1:
                thongKeVonNhap(dsSanPham);
                break;
            case 2:
                thongKeTienBanRa(dsKhachHang);
                break;
            case 3:
                thongKeTinhTrangCuaHang(dsSanPham, dsKhachHang);
                break;
            case 0:
                cout << "Quay lại menu chính.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng chọn từ 0-3.\n";
        }
        
        if (luaChonTK != 0) {
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
        }
    } while (luaChonTK != 0);
}

// Hàm giải phóng bộ nhớ
void giaiPhongBoNho() {
    // Giải phóng bộ nhớ danh sách sản phẩm
    NodeSanPham* currentSP = dsSanPham;
    while (currentSP != NULL) {
        NodeSanPham* temp = currentSP;
        currentSP = currentSP->next;
        delete temp;
    }
    dsSanPham = NULL;
    
    // Giải phóng bộ nhớ danh sách khách hàng
    NodeKhachHang* currentKH = dsKhachHang;
    while (currentKH != NULL) {
        NodeKhachHang* temp = currentKH;
        currentKH = currentKH->next;
        delete temp;
    }
    dsKhachHang = NULL;
}

// Hàm chính
int main() {
    int luaChon;
    
    // Thêm dữ liệu mẫu (tùy chọn)
    // themDuLieuMau();
    
    do {
        system("cls"); // Xóa màn hình (Windows)
        // Nếu dùng Linux/Mac, thay bằng system("clear");
        
        hienThiMenuChinh();
        cin >> luaChon;
        
        // Xử lý lỗi đầu vào
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập số từ 0-3.\n";
            cout << "\nNhấn Enter để tiếp tục...";
            cin.get();
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (luaChon) {
            case 1:
                xuLyQuanLySanPham();
                break;
            case 2:
                xuLyQuanLyKhachHang();
                break;
            case 3:
                xuLyThongKe();
                break;
            case 0:
                cout << "Cảm ơn bạn đã sử dụng phần mềm. Tạm biệt!\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng chọn từ 0-3.\n";
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
        }
    } while (luaChon != 0);
    
    // Giải phóng bộ nhớ trước khi kết thúc chương trình
    giaiPhongBoNho();
    
    return 0;
}