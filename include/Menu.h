#ifndef MENU_H
#define MENU_H

#include "QuanLyKhachHang.h"
#include "QuanLySanPham.h"
#include "ThongKe.h"

class Menu {
private:
    QuanLyKhachHang qlKhachHang;  // Đối tượng quản lý khách hàng
    QuanLySanPham qlSanPham;      // Đối tượng quản lý sản phẩm
    ThongKe thongKe;              // Đối tượng thống kê
    
    // Các path mặc định đến file
    const std::string KHACH_HANG_FILE = "data/khachhang.txt";
    const std::string SAN_PHAM_FILE = "data/sanpham.txt";
    
public:
    // Constructor
    Menu();
    
    // Hiển thị menu chính
    void hienThiMenuChinh();
    
    // Xử lý menu chính
    void xuLyMenuChinh();
    
    // Hiển thị menu quản lý khách hàng
    void hienThiMenuKhachHang();
    
    // Xử lý menu quản lý khách hàng
    void xuLyMenuKhachHang();
    
    // Hiển thị menu quản lý sản phẩm
    void hienThiMenuSanPham();
    
    // Xử lý menu quản lý sản phẩm
    void xuLyMenuSanPham();
    
    // Hiển thị menu thống kê
    void hienThiMenuThongKe();
    
    // Xử lý menu thống kê
    void xuLyMenuThongKe();
    
    // Nhập danh sách khách hàng từ bàn phím
    void nhapDanhSachKhachHang();
    
    // Nhập danh sách sản phẩm từ bàn phím
    void nhapDanhSachSanPham();
    
    // Tìm kiếm khách hàng
    void timKiemKhachHang();
    
    // Tìm kiếm sản phẩm
    void timKiemSanPham();
    
    // Sắp xếp khách hàng
    void sapXepKhachHang();
    
    // Sắp xếp sản phẩm
    void sapXepSanPham();
    
    // Thực hiện các yêu cầu tìm phần tử lớn nhất, nhỏ nhất
    void timPhanTuLonNhatNhoNhat();
    
    // Thực hiện các yêu cầu tính tổng, trung bình, đếm
    void tinhTongTrungBinhDem();
    
    // Thực hiện các yêu cầu thống kê theo điều kiện
    void thongKeTheoDieuKien();
    
    // Khởi động chương trình
    void run();
};

#endif // MENU_H