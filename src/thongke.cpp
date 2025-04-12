#include "ThongKe.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

// Constructor
ThongKe::ThongKe(QuanLyKhachHang& qlKH, QuanLySanPham& qlSP) 
    : qlKhachHang(qlKH), qlSanPham(qlSP) {}

// Tính tổng vốn nhập hàng
double ThongKe::tinhTongVonNhap() const {
    return qlSanPham.tinhTongVonNhap();
}

// Tính tổng tiền bán ra
double ThongKe::tinhTongTienBanRa() const {
    return qlKhachHang.tinhTongTien();
}

// Tính lãi/lỗ của cửa hàng
double ThongKe::tinhLaiLo() const {
    double tongTienBanRa = tinhTongTienBanRa();
    double tongVonNhap = tinhTongVonNhap();
    return tongTienBanRa - tongVonNhap;
}

// Hiển thị tình trạng cửa hàng
void ThongKe::hienThiTinhTrangCuaHang() const {
    double tongVonNhap = tinhTongVonNhap();
    double tongTienBanRa = tinhTongTienBanRa();
    double laiLo = tinhLaiLo();
    
    std::cout << "\n=============== TÌNH TRẠNG CỬA HÀNG ===============\n";
    std::cout << "Tổng vốn nhập hàng: " << Utils::formatCurrency(tongVonNhap) << std::endl;
    std::cout << "Tổng tiền bán ra: " << Utils::formatCurrency(tongTienBanRa) << std::endl;
    std::cout << "Lãi/Lỗ: " << Utils::formatCurrency(laiLo) << std::endl;
    
    if (laiLo > 0) {
        std::cout << "Cửa hàng đang LÃI " << Utils::formatCurrency(laiLo) << std::endl;
    } else if (laiLo < 0) {
        std::cout << "Cửa hàng đang LỖ " << Utils::formatCurrency(-laiLo) << std::endl;
    } else {
        std::cout << "Cửa hàng đang HÒA VỐN" << std::endl;
    }
    Utils::drawLine(50);
}

// Thống kê sản phẩm bán chạy nhất
std::vector<std::pair<std::string, int>> ThongKe::thongKeSanPhamBanChayNhat(int topN) const {
    std::map<std::string, int> matHangCount;
    
    // Duyệt qua tất cả khách hàng để đếm số lượng mặt hàng đã bán
    NodeKhachHang* current = nullptr;
    // Nếu QuanLyKhachHang cung cấp iterator hoặc phương thức để truy cập nội bộ, sử dụng ở đây
    
    // Dựa vào kết quả thống kê theo mặt hàng từ QuanLyKhachHang
    auto thongKe = qlKhachHang.thongKeTheoMatHang();
    
    // Sắp xếp theo số lượng giảm dần (đã thực hiện trong phương thức thongKeTheoMatHang)
    
    // Trả về topN phần tử đầu tiên
    std::vector<std::pair<std::string, int>> result;
    int count = 0;
    for (const auto& pair : thongKe) {
        result.push_back(pair);
        count++;
        if (count >= topN) break;
    }
    
    return result;
}

// Thống kê khách hàng tiềm năng (mua nhiều nhất)
std::vector<std::pair<std::string, double>> ThongKe::thongKeKhachHangTiemNang(int topN) const {
    std::map<std::string, double> khachHangTongTien;
    
    // Đây chỉ là một cách tiếp cận, bạn cần triển khai theo cách tiếp cận dữ liệu từ cấu trúc của mình
    // Giả sử có thể truy cập vào danh sách khách hàng từ qlKhachHang
    
    // Dựa vào kết quả tính tổng tiền từng khách hàng (cần phải cập nhật lại QuanLyKhachHang để hỗ trợ)
    
    // Tạm thời tạo một giải pháp khác:
    // Giả sử khách hàng tiềm năng là khách hàng có thành tiền lớn
    
    // Tạo vector kết quả
    std::vector<std::pair<std::string, double>> result;
    
    return result;
}

// Thống kê doanh thu theo tháng
std::vector<std::pair<std::string, double>> ThongKe::thongKeDoanhThuTheoThang() const {
    std::map<std::string, double> doanhThuThang;
    
    // Lấy dữ liệu doanh thu theo ngày
    auto doanhThuNgay = qlKhachHang.thongKeDoanhThuTheoNgay();
    
    // Tổng hợp doanh thu theo tháng
    for (const auto& pair : doanhThuNgay) {
        std::string ngay = pair.first;
        double doanhThu = pair.second;
        
        // Trích xuất tháng/năm từ ngày (dd/mm/yyyy -> mm/yyyy)
        std::vector<std::string> parts = Utils::split(ngay, '/');
        if (parts.size() >= 3) {
            std::string thangNam = parts[1] + "/" + parts[2]; // mm/yyyy
            doanhThuThang[thangNam] += doanhThu;
        }
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp
    std::vector<std::pair<std::string, double>> result;
    for (const auto& pair : doanhThuThang) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo thời gian tăng dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
                  std::vector<std::string> parts1 = Utils::split(a.first, '/');
                  std::vector<std::string> parts2 = Utils::split(b.first, '/');
                  
                  if (parts1.size() == 2 && parts2.size() == 2) {
                      // So sánh năm trước
                      if (parts1[1] != parts2[1]) {
                          return parts1[1] < parts2[1];
                      }
                      // Sau đó so sánh tháng
                      return parts1[0] < parts2[0];
                  }
                  return a.first < b.first;
              });
    
    return result;
}

// Thống kê doanh thu theo quý
std::vector<std::pair<int, double>> ThongKe::thongKeDoanhThuTheoQuy() const {
    std::map<int, double> doanhThuQuy;
    
    // Lấy dữ liệu doanh thu theo ngày
    auto doanhThuNgay = qlKhachHang.thongKeDoanhThuTheoNgay();
    
    // Tổng hợp doanh thu theo quý
    for (const auto& pair : doanhThuNgay) {
        std::string ngay = pair.first;
        double doanhThu = pair.second;
        
        // Trích xuất quý từ ngày
        int quy = Utils::extractQuarter(ngay);
        if (quy > 0) {
            doanhThuQuy[quy] += doanhThu;
        }
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp
    std::vector<std::pair<int, double>> result;
    for (const auto& pair : doanhThuQuy) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo quý tăng dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
                  return a.first < b.first;
              });
    
    return result;
}

// Thống kê lãi/lỗ theo tháng
std::vector<std::pair<std::string, double>> ThongKe::thongKeLaiLoTheoThang() const {
    // Lấy doanh thu theo tháng
    auto doanhThuThang = thongKeDoanhThuTheoThang();
    
    // Lấy giá trị nhập theo ngày từ QuanLySanPham
    auto giaTriNhapNgay = qlSanPham.thongKeGiaTriNhapTheoNgay();
    
    // Tổng hợp giá trị nhập theo tháng
    std::map<std::string, double> giaTriNhapThang;
    for (const auto& pair : giaTriNhapNgay) {
        std::string ngay = pair.first;
        double giaTriNhap = pair.second;
        
        // Trích xuất tháng/năm từ ngày (dd/mm/yyyy -> mm/yyyy)
        std::vector<std::string> parts = Utils::split(ngay, '/');
        if (parts.size() >= 3) {
            std::string thangNam = parts[1] + "/" + parts[2]; // mm/yyyy
            giaTriNhapThang[thangNam] += giaTriNhap;
        }
    }
    
    // Tính lãi/lỗ theo tháng
    std::map<std::string, double> laiLoThang;
    
    // Tính lãi/lỗ cho tất cả các tháng có doanh thu
    for (const auto& pair : doanhThuThang) {
        std::string thangNam = pair.first;
        double doanhThu = pair.second;
        double giaTriNhap = giaTriNhapThang[thangNam]; // Nếu không có, mặc định là 0
        laiLoThang[thangNam] = doanhThu - giaTriNhap;
    }
    
    // Tính lãi/lỗ cho tất cả các tháng có giá trị nhập nhưng không có doanh thu
    for (const auto& pair : giaTriNhapThang) {
        std::string thangNam = pair.first;
        if (laiLoThang.find(thangNam) == laiLoThang.end()) {
            laiLoThang[thangNam] = -pair.second; // Tháng chỉ có nhập hàng, không có doanh thu -> lỗ
        }
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp
    std::vector<std::pair<std::string, double>> result;
    for (const auto& pair : laiLoThang) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo thời gian tăng dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
                  std::vector<std::string> parts1 = Utils::split(a.first, '/');
                  std::vector<std::string> parts2 = Utils::split(b.first, '/');
                  
                  if (parts1.size() == 2 && parts2.size() == 2) {
                      // So sánh năm trước
                      if (parts1[1] != parts2[1]) {
                          return parts1[1] < parts2[1];
                      }
                      // Sau đó so sánh tháng
                      return parts1[0] < parts2[0];
                  }
                  return a.first < b.first;
              });
    
    return result;
}