#include "KhachHang.h"
#include "Utils.h"
#include <sstream>
#include <iomanip>

// Constructor mặc định
KhachHang::KhachHang() : soLuong(0), thanhTien(0.0) {}

// Constructor với tham số
KhachHang::KhachHang(const std::string& maKH, const std::string& tenKH, 
                     const std::string& diaChi, const std::string& soDienThoai,
                     const std::string& ngaySinh, const std::string& matHangMua,
                     int soLuong, double thanhTien, const std::string& ngayGiaoDich)
    : maKH(maKH), tenKH(tenKH), diaChi(diaChi), soDienThoai(soDienThoai),
      ngaySinh(ngaySinh), matHangMua(matHangMua), soLuong(soLuong),
      thanhTien(thanhTien), ngayGiaoDich(ngayGiaoDich) {}

// Getter methods
std::string KhachHang::getMaKH() const { return maKH; }
std::string KhachHang::getTenKH() const { return tenKH; }
std::string KhachHang::getDiaChi() const { return diaChi; }
std::string KhachHang::getSoDienThoai() const { return soDienThoai; }
std::string KhachHang::getNgaySinh() const { return ngaySinh; }
std::string KhachHang::getMatHangMua() const { return matHangMua; }
int KhachHang::getSoLuong() const { return soLuong; }
double KhachHang::getThanhTien() const { return thanhTien; }
std::string KhachHang::getNgayGiaoDich() const { return ngayGiaoDich; }

// Setter methods
void KhachHang::setMaKH(const std::string& maKH) { this->maKH = maKH; }
void KhachHang::setTenKH(const std::string& tenKH) { this->tenKH = tenKH; }
void KhachHang::setDiaChi(const std::string& diaChi) { this->diaChi = diaChi; }
void KhachHang::setSoDienThoai(const std::string& soDienThoai) { this->soDienThoai = soDienThoai; }
void KhachHang::setNgaySinh(const std::string& ngaySinh) { this->ngaySinh = ngaySinh; }
void KhachHang::setMatHangMua(const std::string& matHangMua) { this->matHangMua = matHangMua; }
void KhachHang::setSoLuong(int soLuong) { this->soLuong = soLuong; }
void KhachHang::setThanhTien(double thanhTien) { this->thanhTien = thanhTien; }
void KhachHang::setNgayGiaoDich(const std::string& ngayGiaoDich) { this->ngayGiaoDich = ngayGiaoDich; }

// Hiển thị thông tin khách hàng
void KhachHang::hienThi() const {
    std::cout << std::left << std::setw(10) << maKH 
              << std::setw(20) << tenKH 
              << std::setw(30) << diaChi 
              << std::setw(15) << soDienThoai 
              << std::setw(12) << ngaySinh 
              << std::setw(20) << matHangMua 
              << std::setw(8) << soLuong 
              << std::setw(15) << Utils::formatCurrency(thanhTien) 
              << std::setw(12) << ngayGiaoDich 
              << std::endl;
}

// Nhập thông tin khách hàng từ người dùng
void KhachHang::nhap() {
    std::cout << "Nhập thông tin khách hàng:" << std::endl;
    
    maKH = Utils::inputString("Mã khách hàng: ");
    tenKH = Utils::inputString("Tên khách hàng: ");
    diaChi = Utils::inputString("Địa chỉ: ");
    
    // Nhập và kiểm tra định dạng số điện thoại
    do {
        soDienThoai = Utils::inputString("Số điện thoại: ");
        if (!Utils::isNumber(soDienThoai)) {
            std::cout << "Số điện thoại không hợp lệ. Vui lòng nhập lại.\n";
        }
    } while (!Utils::isNumber(soDienThoai));
    
    // Nhập và kiểm tra định dạng ngày sinh
    ngaySinh = Utils::inputDate("Ngày sinh (dd/mm/yyyy): ");
    
    matHangMua = Utils::inputString("Mặt hàng mua: ");
    soLuong = Utils::inputInt("Số lượng: ", 0);
    thanhTien = Utils::inputDouble("Thành tiền: ", 0);
    
    // Mặc định ngày giao dịch là ngày hiện tại hoặc nhập từ bàn phím
    char option;
    std::cout << "Sử dụng ngày hiện tại làm ngày giao dịch? (y/n): ";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (option == 'y' || option == 'Y') {
        ngayGiaoDich = Utils::getNgayHienTai();
    } else {
        ngayGiaoDich = Utils::inputDate("Ngày giao dịch (dd/mm/yyyy): ");
    }
}

// Chuyển thông tin khách hàng thành chuỗi để lưu vào file
std::string KhachHang::toString() const {
    std::stringstream ss;
    ss << maKH << "|" << tenKH << "|" << diaChi << "|" << soDienThoai << "|"
       << ngaySinh << "|" << matHangMua << "|" << soLuong << "|"
       << thanhTien << "|" << ngayGiaoDich;
    return ss.str();
}

// Khôi phục thông tin khách hàng từ chuỗi đọc từ file
void KhachHang::fromString(const std::string& str) {
    std::vector<std::string> parts = Utils::split(str, '|');
    if (parts.size() >= 9) {
        maKH = parts[0];
        tenKH = parts[1];
        diaChi = parts[2];
        soDienThoai = parts[3];
        ngaySinh = parts[4];
        matHangMua = parts[5];
        soLuong = Utils::stringToInt(parts[6]);
        thanhTien = Utils::stringToDouble(parts[7]);
        ngayGiaoDich = parts[8];
    }
}