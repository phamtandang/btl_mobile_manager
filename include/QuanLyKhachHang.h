#ifndef QUAN_LY_KHACH_HANG_H
#define QUAN_LY_KHACH_HANG_H

#include "KhachHang.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class QuanLyKhachHang {
private:
    NodeKhachHang* head;    // Con trỏ đến node đầu tiên trong danh sách
    
public:
    // Constructor
    QuanLyKhachHang();
    
    // Destructor - giải phóng bộ nhớ của danh sách liên kết
    ~QuanLyKhachHang();
    
    // Kiểm tra danh sách rỗng
    bool isEmpty() const;
    
    // Thêm khách hàng vào danh sách
    void themKhachHang(const KhachHang& kh);
    
    // Hiển thị toàn bộ danh sách khách hàng
    void hienThiDanhSach() const;
    
    // Tìm kiếm khách hàng theo mã
    NodeKhachHang* timKiemTheoMa(const std::string& maKH) const;
    
    // Tìm kiếm khách hàng theo tên
    std::vector<NodeKhachHang*> timKiemTheoTen(const std::string& tenKH) const;

    // Tìm kiếm khách hàng theo số điện thoại
    NodeKhachHang* timKiemTheoSDT(const std::string& sdt) const;
    
    // Xóa khách hàng theo mã
    bool xoaKhachHang(const std::string& maKH);
    
    // Sửa thông tin khách hàng
    bool suaKhachHang(const std::string& maKH, const KhachHang& khMoi);
    
    // Đọc dữ liệu từ file
    bool docFile(const std::string& tenFile);
    
    // Ghi dữ liệu vào file
    bool ghiFile(const std::string& tenFile) const;
    
    // Sắp xếp khách hàng theo mã khách hàng tăng dần
    void sapXepTheoMaKH();
    
    // Sắp xếp khách hàng theo tên khách hàng tăng dần
    void sapXepTheoTenKH();
    
    // Sắp xếp khách hàng theo thành tiền giảm dần
    void sapXepTheoThanhTien();
    
    // Sắp xếp khách hàng theo ngày giao dịch tăng dần
    void sapXepTheoNgayGiaoDich();

    // Tìm khách hàng có thành tiền lớn nhất
    KhachHang timKhachHangThanhTienMax() const;
    
    // Tìm khách hàng có thành tiền nhỏ nhất
    KhachHang timKhachHangThanhTienMin() const;

    // Tính tổng tiền của tất cả khách hàng
    double tinhTongTien() const;
    
    // Tính trung bình thành tiền của tất cả khách hàng
    double tinhTrungBinhThanhTien() const;
    
    // Đếm số lượng khách hàng
    int demSoLuongKhachHang() const;
    
    // Thống kê khách hàng theo mặt hàng mua
    std::vector<std::pair<std::string, int>> thongKeTheoMatHang() const;
    
    // Thống kê doanh thu theo ngày
    std::vector<std::pair<std::string, double>> thongKeDoanhThuTheoNgay() const;
    
    // Thống kê số lượng khách hàng theo tháng
    std::vector<std::pair<std::string, int>> thongKeKhachHangTheoThang() const;
    
    // Thống kê khách hàng có thành tiền lớn hơn X
    std::vector<KhachHang> thongKeKhachHangCoThanhTienLonHon(double x) const;
    
    // Thống kê khách hàng có thành tiền nhỏ hơn X
    std::vector<KhachHang> thongKeKhachHangCoThanhTienNhoHon(double x) const;
};

#endif // QUAN_LY_KHACH_HANG_H