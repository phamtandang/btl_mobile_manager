#include "../include/utils.h"
#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

// Hàm nhập chuỗi với kiểm tra dữ liệu đầu vào
string nhapChuoi(const string& thongBao) {
    string input;
    cout << thongBao;
    getline(cin, input);
    return input;
}

// Hàm nhập số nguyên với kiểm tra dữ liệu đầu vào
int nhapSoNguyen(const string& thongBao) {
    int input;
    bool valid = false;
    
    do {
        cout << thongBao;
        cin >> input;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lỗi: Vui lòng nhập một số nguyên hợp lệ.\n";
        } else {
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid);
    
    return input;
}

// Hàm nhập số thực với kiểm tra dữ liệu đầu vào
double nhapSoThuc(const string& thongBao) {
    double input;
    bool valid = false;
    
    do {
        cout << thongBao;
        cin >> input;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lỗi: Vui lòng nhập một số thực hợp lệ.\n";
        } else {
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid);
    
    return input;
}

// Hàm lấy ngày hiện tại
string ngayHienTai() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    string ngay = to_string(ltm->tm_mday);
    string thang = to_string(1 + ltm->tm_mon);
    string nam = to_string(1900 + ltm->tm_year);
    
    return ngay + "/" + thang + "/" + nam;
}

// Hàm hiển thị menu chính
void hienThiMenuChinh() {
    cout << "\n===== QUẢN LÝ CỬA HÀNG =====\n";
    cout << "1. Quản lý Sản phẩm\n";
    cout << "2. Quản lý Khách hàng\n";
    cout << "3. Thống kê\n";
    cout << "0. Thoát\n";
    cout << "===========================\n";
    cout << "Lựa chọn của bạn: ";
}

// Hàm hiển thị menu sản phẩm
void hienThiMenuSanPham() {
    cout << "\n===== QUẢN LÝ SẢN PHẨM =====\n";
    cout << "1. Hiển thị danh sách sản phẩm\n";
    cout << "2. Thêm sản phẩm\n";
    cout << "3. Sửa thông tin sản phẩm\n";
    cout << "4. Xóa sản phẩm\n";
    cout << "5. Tìm kiếm sản phẩm\n";
    cout << "6. Sắp xếp sản phẩm\n";
    cout << "7. Thống kê sản phẩm\n";
    cout << "0. Quay lại menu chính\n";
    cout << "===========================\n";
    cout << "Lựa chọn của bạn: ";
}

// Hàm hiển thị menu khách hàng
void hienThiMenuKhachHang() {
    cout << "\n===== QUẢN LÝ KHÁCH HÀNG =====\n";
    cout << "1. Hiển thị danh sách khách hàng\n";
    cout << "2. Thêm khách hàng\n";
    cout << "3. Sửa thông tin khách hàng\n";
    cout << "4. Xóa khách hàng\n";
    cout << "5. Tìm kiếm khách hàng\n";
    cout << "6. Sắp xếp khách hàng\n";
    cout << "0. Quay lại menu chính\n";
    cout << "===========================\n";
    cout << "Lựa chọn của bạn: ";
}

// Hàm hiển thị menu thống kê
void hienThiMenuThongKe() {
    cout << "\n===== THỐNG KÊ =====\n";
    cout << "1. Số vốn nhập\n";
    cout << "2. Số tiền bán ra\n";
    cout << "3. Tình trạng cửa hàng\n";
    cout << "0. Quay lại menu chính\n";
    cout << "===========================\n";
    cout << "Lựa chọn của bạn: ";
}