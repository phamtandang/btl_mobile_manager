#ifndef THONG_KE_H
#define THONG_KE_H

#include "QuanLyKhachHang.h"
#include "QuanLySanPham.h"
#include <string>
#include <utility>
#include <vector>

class ThongKe {
private:
    QuanLyKhachHang& qlKhachHang;  // Tham chiếu đến lớp quản lý khách hàng
    QuanLySanPham& qlSanPham;      // Tham chiếu đến lớp quản lý sản phẩm
    
public:
    // Constructor
    ThongKe(QuanLyKhachHang& qlKH, QuanLySanPham& qlSP);
    
    // Tính tổng vốn nhập hàng
    double tinhTongVonNhap() const;
    
    // Tính tổng tiền bán ra
    double tinhTongTienBanRa() const;
    
    // Tính lãi/lỗ của cửa hàng
    double tinhLaiLo() const;
    
    // Hiển thị tình trạng cửa hàng
    void hienThiTinhTrangCuaHang() const;
    
    // Thống kê sản phẩm bán chạy nhất
    std::vector<std::pair<std::string, int>> thongKeSanPhamBanChayNhat(int topN = 5) const;
    
    // Thống kê khách hàng tiềm năng (mua nhiều nhất)
    std::vector<std::pair<std::string, double>> thongKeKhachHangTiemNang(int topN = 5) const;
    
    // Thống kê doanh thu theo tháng
    std::vector<std::pair<std::string, double>> thongKeDoanhThuTheoThang() const;
    
    // Thống kê doanh thu theo quý
    std::vector<std::pair<int, double>> thongKeDoanhThuTheoQuy() const;
    
    // Thống kê lãi/lỗ theo tháng
    std::vector<std::pair<std::string, double>> thongKeLaiLoTheoThang() const;
};

#endif // THONG_KE_H