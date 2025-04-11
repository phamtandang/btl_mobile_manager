#ifndef UTILS_H
#define UTILS_H

#include <string>

// Hàm nhập chuỗi với kiểm tra dữ liệu đầu vào
std::string nhapChuoi(const std::string& thongBao);

// Hàm nhập số nguyên với kiểm tra dữ liệu đầu vào
int nhapSoNguyen(const std::string& thongBao);

// Hàm nhập số thực với kiểm tra dữ liệu đầu vào
double nhapSoThuc(const std::string& thongBao);

// Hàm lấy ngày hiện tại
std::string ngayHienTai();

// Hàm hiển thị menu chính
void hienThiMenuChinh();

// Hàm hiển thị menu sản phẩm
void hienThiMenuSanPham();

// Hàm hiển thị menu khách hàng
void hienThiMenuKhachHang();

// Hàm hiển thị menu thống kê
void hienThiMenuThongKe();

#endif // UTILS_H