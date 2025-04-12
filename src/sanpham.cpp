#include "SanPham.h"
#include "Utils.h"
#include <sstream>
#include <iomanip>

// Constructor mặc định
SanPham::SanPham() : soLuong(0), donGia(0.0), thanhTien(0.0) {}

// Constructor với tham số
SanPham::SanPham(const std::string& maSP, const std::string& tenSP,
                 const std::string& maNhaCungCap, const std::string& tenNhaCungCap,
                 const std::string& ngayNhap, int soLuong, double donGia, double thanhTien)
    : maSP(maSP), tenSP(tenSP), maNhaCungCap(maNhaCungCap), tenNhaCungCap(tenNhaCungCap),
      ngayNhap(ngayNhap), soLuong(soLuong), donGia(donGia), thanhTien(thanhTien) {}

// Getter methods
std::string SanPham::getMaSP() const { return maSP; }
std::string SanPham::getTenSP() const { return tenSP; }
std::string SanPham::getMaNhaCungCap() const { return maNhaCungCap; }
std::string SanPham::getTenNhaCungCap() const { return tenNhaCungCap; }
std::string SanPham::getNgayNhap() const { return ngayNhap; }
int SanPham::getSoLuong() const { return soLuong; }
double SanPham::getDonGia() const { return donGia; }
double SanPham::getThanhTien() const { return thanhTien; }

// Setter methods
void SanPham::setMaSP(const std::string& maSP) { this->maSP = maSP; }
void SanPham::setTenSP(const std::string& tenSP) { this->tenSP = tenSP; }
void SanPham::setMaNhaCungCap(const std::string& maNhaCungCap) { this->maNhaCungCap = maNhaCungCap; }
void SanPham::setTenNhaCungCap(const std::string& tenNhaCungCap) { this->tenNhaCungCap = tenNhaCungCap; }
void SanPham::setNgayNhap(const std::string& ngayNhap) { this->ngayNhap = ngayNhap; }
void SanPham::setSoLuong(int soLuong) { this->soLuong = soLuong; }
void SanPham::setDonGia(double donGia) { this->donGia = donGia; }
void SanPham::setThanhTien(double thanhTien) { this->thanhTien = thanhTien; }

// Hiển thị thông tin sản phẩm
void SanPham::hienThi() const {
    std::cout << std::left << std::setw(10) << maSP 
              << std::setw(20) << tenSP 
              << std::setw(15) << maNhaCungCap 
              << std::setw(20) << tenNhaCungCap 
              << std::setw(12) << ngayNhap 
              << std::setw(8) << soLuong 
              << std::setw(15) << Utils::formatCurrency(donGia) 
              << std::setw(15) << Utils::formatCurrency(thanhTien) 
              << std::endl;
}

// Nhập thông tin sản phẩm từ người dùng
void SanPham::nhap() {
    std::cout << "Nhập thông tin sản phẩm:" << std::endl;
    
    maSP = Utils::inputString("Mã sản phẩm: ");
    tenSP = Utils::inputString("Tên sản phẩm: ");
    maNhaCungCap = Utils::inputString("Mã nhà cung cấp: ");
    tenNhaCungCap = Utils::inputString("Tên nhà cung cấp: ");
    
    // Nhập và kiểm tra định dạng ngày nhập
    ngayNhap = Utils::inputDate("Ngày nhập (dd/mm/yyyy): ");
    
    soLuong = Utils::inputInt("Số lượng: ", 0);
    donGia = Utils::inputDouble("Đơn giá: ", 0);
    
    // Tính thành tiền
    tinhThanhTien();
}

// Tính thành tiền: thành tiền = số lượng * đơn giá
void SanPham::tinhThanhTien() {
    thanhTien = soLuong * donGia;
}

// Chuyển thông tin sản phẩm thành chuỗi để lưu vào file
std::string SanPham::toString() const {
    std::stringstream ss;
    ss << maSP << "|" << tenSP << "|" << maNhaCungCap << "|" 
       << tenNhaCungCap << "|" << ngayNhap << "|" << soLuong << "|"
       << std::to_string(donGia) << "|" << std::to_string(thanhTien);
    return ss.str();
}

// Khôi phục thông tin sản phẩm từ chuỗi đọc từ file
void SanPham::fromString(const std::string& str) {
    std::vector<std::string> parts = Utils::split(str, '|');
    if (parts.size() >= 8) {
        maSP = parts[0];
        tenSP = parts[1];
        maNhaCungCap = parts[2];
        tenNhaCungCap = parts[3];
        ngayNhap = parts[4];
        soLuong = Utils::stringToInt(parts[5]);
        donGia = Utils::stringToDouble(parts[6]);
        thanhTien = Utils::stringToDouble(parts[7]);
    }
}