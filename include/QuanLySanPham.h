#ifndef QUAN_LY_SAN_PHAM_H
#define QUAN_LY_SAN_PHAM_H

#include "SanPham.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class QuanLySanPham {
private:
    NodeSanPham* head;    // Con trỏ đến node đầu tiên trong danh sách
    
public:
    // Constructor
    QuanLySanPham();
    
    // Destructor - giải phóng bộ nhớ của danh sách liên kết
    ~QuanLySanPham();
    
    // Kiểm tra danh sách rỗng
    bool isEmpty() const;
    
    // Thêm sản phẩm vào danh sách
    void themSanPham(const SanPham& sp);
    
    // Hiển thị toàn bộ danh sách sản phẩm
    void hienThiDanhSach() const;
    
    // Tìm kiếm sản phẩm theo mã
    NodeSanPham* timKiemTheoMa(const std::string& maSP) const;
    
    // Tìm kiếm sản phẩm theo tên
    std::vector<NodeSanPham*> timKiemTheoTen(const std::string& tenSP) const;
    
    // Xóa sản phẩm theo mã
    bool xoaSanPham(const std::string& maSP);
    
    // Sửa thông tin sản phẩm
    bool suaSanPham(const std::string& maSP, const SanPham& spMoi);
    
    // Đọc dữ liệu từ file
    bool docFile(const std::string& tenFile);
    
    // Ghi dữ liệu vào file
    bool ghiFile(const std::string& tenFile) const;
    
    // Sắp xếp sản phẩm theo mã sản phẩm tăng dần
    void sapXepTheoMaSP();
    
    // Sắp xếp sản phẩm theo tên sản phẩm tăng dần
    void sapXepTheoTenSP();
    
    // Sắp xếp sản phẩm theo đơn giá tăng dần
    void sapXepTheoDonGia();
    
    // Sắp xếp sản phẩm theo thành tiền giảm dần
    void sapXepTheoThanhTien();
    
    // Tìm sản phẩm có đơn giá lớn nhất
    SanPham timSanPhamDonGiaMax() const;
    
    // Tìm sản phẩm có đơn giá nhỏ nhất
    SanPham timSanPhamDonGiaMin() const;
    
    // Tìm sản phẩm có thành tiền lớn nhất
    SanPham timSanPhamThanhTienMax() const;
    
    // Tìm sản phẩm có thành tiền nhỏ nhất
    SanPham timSanPhamThanhTienMin() const;
    
    // Tính tổng vốn nhập của tất cả sản phẩm
    double tinhTongVonNhap() const;
    
    // Tính trung bình thành tiền của tất cả sản phẩm
    double tinhTrungBinhThanhTien() const;
    
    // Đếm số lượng sản phẩm
    int demSoLuongSanPham() const;
    
    // Thống kê sản phẩm theo nhà cung cấp
    std::vector<std::pair<std::string, int>> thongKeTheoNhaCungCap() const;
    
    // Thống kê sản phẩm có đơn giá lớn hơn X
    std::vector<SanPham> thongKeSanPhamCoDonGiaLonHon(double x) const;
    
    // Thống kê sản phẩm có đơn giá nhỏ hơn X
    std::vector<SanPham> thongKeSanPhamCoDonGiaNhoHon(double x) const;
    
    // Thống kê tổng giá trị nhập theo ngày
    std::vector<std::pair<std::string, double>> thongKeGiaTriNhapTheoNgay() const;
};

#endif // QUAN_LY_SAN_PHAM_H