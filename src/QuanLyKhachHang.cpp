#include "QuanLyKhachHang.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

// Constructor
QuanLyKhachHang::QuanLyKhachHang() : head(nullptr) {}

// Destructor
QuanLyKhachHang::~QuanLyKhachHang() {
    // Giải phóng bộ nhớ khi kết thúc chương trình
    NodeKhachHang* current = head;
    while (current != nullptr) {
        NodeKhachHang* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Kiểm tra danh sách rỗng
bool QuanLyKhachHang::isEmpty() const {
    return head == nullptr;
}

// Thêm khách hàng vào danh sách
void QuanLyKhachHang::themKhachHang(const KhachHang& kh) {
    // Kiểm tra trùng mã khách hàng
    if (timKiemTheoMa(kh.getMaKH()) != nullptr) {
        std::cout << "Mã khách hàng đã tồn tại. Không thể thêm mới.\n";
        return;
    }
    
    NodeKhachHang* newNode = new NodeKhachHang(kh);
    
    // Nếu danh sách rỗng hoặc thêm vào đầu danh sách
    if (head == nullptr) {
        head = newNode;
    } else {
        // Thêm vào cuối danh sách
        NodeKhachHang* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    std::cout << "Đã thêm khách hàng thành công.\n";
}

// Hiển thị toàn bộ danh sách khách hàng
void QuanLyKhachHang::hienThiDanhSach() const {
    if (isEmpty()) {
        std::cout << "Danh sách khách hàng rỗng.\n";
        return;
    }
    
    std::cout << "\n=============== DANH SÁCH KHÁCH HÀNG ===============\n";
    std::cout << std::left << std::setw(10) << "Mã KH" 
              << std::setw(20) << "Tên KH" 
              << std::setw(30) << "Địa chỉ" 
              << std::setw(15) << "Số điện thoại" 
              << std::setw(12) << "Ngày sinh" 
              << std::setw(20) << "Mặt hàng mua" 
              << std::setw(8) << "SL" 
              << std::setw(15) << "Thành tiền" 
              << std::setw(12) << "Ngày GD" 
              << std::endl;
    Utils::drawLine(150);
    
    NodeKhachHang* current = head;
    while (current != nullptr) {
        current->data.hienThi();
        current = current->next;
    }
    Utils::drawLine(150);
}

// Tìm kiếm khách hàng theo mã
NodeKhachHang* QuanLyKhachHang::timKiemTheoMa(const std::string& maKH) const {
    NodeKhachHang* current = head;
    while (current != nullptr) {
        if (current->data.getMaKH() == maKH) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Tìm kiếm khách hàng theo tên
std::vector<NodeKhachHang*> QuanLyKhachHang::timKiemTheoTen(const std::string& tenKH) const {
    std::vector<NodeKhachHang*> result;
    NodeKhachHang* current = head;
    
    // Chuyển tên cần tìm và tên KH thành chữ thường để so sánh không phân biệt hoa thường
    std::string tenKHLower = tenKH;
    std::transform(tenKHLower.begin(), tenKHLower.end(), tenKHLower.begin(), ::tolower);
    
    while (current != nullptr) {
        std::string currentTenKH = current->data.getTenKH();
        std::transform(currentTenKH.begin(), currentTenKH.end(), currentTenKH.begin(), ::tolower);
        
        if (currentTenKH.find(tenKHLower) != std::string::npos) {
            result.push_back(current);
        }
        current = current->next;
    }
    
    return result;
}

// Tìm kiếm khách hàng theo số điện thoại
NodeKhachHang* QuanLyKhachHang::timKiemTheoSDT(const std::string& sdt) const {
    NodeKhachHang* current = head;
    while (current != nullptr) {
        if (current->data.getSoDienThoai() == sdt) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Xóa khách hàng theo mã
bool QuanLyKhachHang::xoaKhachHang(const std::string& maKH) {
    if (isEmpty()) {
        return false;
    }
    
    // Nếu xóa node đầu
    if (head->data.getMaKH() == maKH) {
        NodeKhachHang* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    // Tìm kiếm và xóa node trong danh sách
    NodeKhachHang* current = head;
    while (current->next != nullptr && current->next->data.getMaKH() != maKH) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        NodeKhachHang* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
    
    return false;
}

// Sửa thông tin khách hàng
bool QuanLyKhachHang::suaKhachHang(const std::string& maKH, const KhachHang& khMoi) {
    NodeKhachHang* node = timKiemTheoMa(maKH);
    if (node == nullptr) {
        return false;
    }
    
    // Không cho phép thay đổi mã khách hàng
    if (khMoi.getMaKH() != maKH) {
        std::cout << "Không được phép thay đổi mã khách hàng.\n";
        return false;
    }
    
    node->data = khMoi;
    return true;
}

// Đọc dữ liệu từ file
bool QuanLyKhachHang::docFile(const std::string& tenFile) {
    std::ifstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Không thể mở file: " << tenFile << std::endl;
        return false;
    }
    
    // Xóa danh sách hiện tại trước khi đọc file
    NodeKhachHang* current = head;
    while (current != nullptr) {
        NodeKhachHang* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        KhachHang kh;
        kh.fromString(line);
        themKhachHang(kh);
    }
    
    file.close();
    return true;
}

// Ghi dữ liệu vào file
bool QuanLyKhachHang::ghiFile(const std::string& tenFile) const {
    std::ofstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Không thể mở file: " << tenFile << std::endl;
        return false;
    }
    
    NodeKhachHang* current = head;
    while (current != nullptr) {
        file << current->data.toString() << std::endl;
        current = current->next;
    }
    
    file.close();
    return true;
}

// Sắp xếp khách hàng theo mã khách hàng tăng dần
void QuanLyKhachHang::sapXepTheoMaKH() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeKhachHang* current;
    NodeKhachHang* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getMaKH() > current->next->data.getMaKH()) {
                // Hoán đổi dữ liệu của hai node
                KhachHang temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp khách hàng theo mã tăng dần.\n";
}

// Sắp xếp khách hàng theo tên khách hàng tăng dần
void QuanLyKhachHang::sapXepTheoTenKH() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeKhachHang* current;
    NodeKhachHang* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getTenKH() > current->next->data.getTenKH()) {
                // Hoán đổi dữ liệu của hai node
                KhachHang temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp khách hàng theo tên tăng dần.\n";
}

// Sắp xếp khách hàng theo thành tiền giảm dần
void QuanLyKhachHang::sapXepTheoThanhTien() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeKhachHang* current;
    NodeKhachHang* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getThanhTien() < current->next->data.getThanhTien()) {
                // Hoán đổi dữ liệu của hai node
                KhachHang temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp khách hàng theo thành tiền giảm dần.\n";
}

// Sắp xếp khách hàng theo ngày giao dịch tăng dần
void QuanLyKhachHang::sapXepTheoNgayGiaoDich() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeKhachHang* current;
    NodeKhachHang* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            // So sánh ngày theo định dạng dd/mm/yyyy
            std::string date1 = current->data.getNgayGiaoDich();
            std::string date2 = current->next->data.getNgayGiaoDich();
            
            // Chuyển đổi định dạng ngày thành yyyymmdd để so sánh
            std::vector<std::string> parts1 = Utils::split(date1, '/');
            std::vector<std::string> parts2 = Utils::split(date2, '/');
            
            if (parts1.size() == 3 && parts2.size() == 3) {
                std::string compare1 = parts1[2] + parts1[1] + parts1[0];
                std::string compare2 = parts2[2] + parts2[1] + parts2[0];
                
                if (compare1 > compare2) {
                    // Hoán đổi dữ liệu của hai node
                    KhachHang temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp khách hàng theo ngày giao dịch tăng dần.\n";
}

// Tìm khách hàng có thành tiền lớn nhất
KhachHang QuanLyKhachHang::timKhachHangThanhTienMax() const {
    if (isEmpty()) {
        return KhachHang();  // Trả về khách hàng rỗng nếu danh sách rỗng
    }
    
    NodeKhachHang* current = head;
    KhachHang maxKH = current->data;
    
    while (current != nullptr) {
        if (current->data.getThanhTien() > maxKH.getThanhTien()) {
            maxKH = current->data;
        }
        current = current->next;
    }
    
    return maxKH;
}

// Tìm khách hàng có thành tiền nhỏ nhất
KhachHang QuanLyKhachHang::timKhachHangThanhTienMin() const {
    if (isEmpty()) {
        return KhachHang();  // Trả về khách hàng rỗng nếu danh sách rỗng
    }
    
    NodeKhachHang* current = head;
    KhachHang minKH = current->data;
    
    while (current != nullptr) {
        if (current->data.getThanhTien() < minKH.getThanhTien()) {
            minKH = current->data;
        }
        current = current->next;
    }
    
    return minKH;
}

// Tính tổng tiền của tất cả khách hàng
double QuanLyKhachHang::tinhTongTien() const {
    double tongTien = 0.0;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        tongTien += current->data.getThanhTien();
        current = current->next;
    }
    
    return tongTien;
}

// Tính trung bình thành tiền của tất cả khách hàng
double QuanLyKhachHang::tinhTrungBinhThanhTien() const {
    if (isEmpty()) {
        return 0.0;
    }
    
    int count = demSoLuongKhachHang();
    return tinhTongTien() / count;
}

// Đếm số lượng khách hàng
int QuanLyKhachHang::demSoLuongKhachHang() const {
    int count = 0;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Thống kê khách hàng theo mặt hàng mua
std::vector<std::pair<std::string, int>> QuanLyKhachHang::thongKeTheoMatHang() const {
    std::map<std::string, int> matHangCount;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        std::string matHang = current->data.getMatHangMua();
        matHangCount[matHang]++;
        current = current->next;
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp sau này
    std::vector<std::pair<std::string, int>> result;
    for (const auto& pair : matHangCount) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo số lượng giảm dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });
    
    return result;
}

// Thống kê doanh thu theo ngày
std::vector<std::pair<std::string, double>> QuanLyKhachHang::thongKeDoanhThuTheoNgay() const {
    std::map<std::string, double> doanhThuNgay;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        std::string ngay = current->data.getNgayGiaoDich();
        doanhThuNgay[ngay] += current->data.getThanhTien();
        current = current->next;
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp sau này
    std::vector<std::pair<std::string, double>> result;
    for (const auto& pair : doanhThuNgay) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo ngày tăng dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
                  std::vector<std::string> parts1 = Utils::split(a.first, '/');
                  std::vector<std::string> parts2 = Utils::split(b.first, '/');
                  
                  if (parts1.size() == 3 && parts2.size() == 3) {
                      std::string compare1 = parts1[2] + parts1[1] + parts1[0];
                      std::string compare2 = parts2[2] + parts2[1] + parts2[0];
                      return compare1 < compare2;
                  }
                  return a.first < b.first;
              });
    
    return result;
}

// Thống kê số lượng khách hàng theo tháng
std::vector<std::pair<std::string, int>> QuanLyKhachHang::thongKeKhachHangTheoThang() const {
    std::map<std::string, int> khachHangThang;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        std::string ngay = current->data.getNgayGiaoDich();
        std::vector<std::string> parts = Utils::split(ngay, '/');
        if (parts.size() >= 3) {
            std::string thang = parts[1] + "/" + parts[2]; // MM/YYYY
            khachHangThang[thang]++;
        }
        current = current->next;
    }
    
    // Chuyển từ map sang vector
    std::vector<std::pair<std::string, int>> result;
    for (const auto& pair : khachHangThang) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo thời gian tăng dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
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

// Thống kê khách hàng có thành tiền lớn hơn X
std::vector<KhachHang> QuanLyKhachHang::thongKeKhachHangCoThanhTienLonHon(double x) const {
    std::vector<KhachHang> result;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        if (current->data.getThanhTien() > x) {
            result.push_back(current->data);
        }
        current = current->next;
    }
    
    // Sắp xếp theo thành tiền giảm dần
    std::sort(result.begin(), result.end(), 
              [](const KhachHang& a, const KhachHang& b) {
                  return a.getThanhTien() > b.getThanhTien();
              });
    
    return result;
}

// Thống kê khách hàng có thành tiền nhỏ hơn X
std::vector<KhachHang> QuanLyKhachHang::thongKeKhachHangCoThanhTienNhoHon(double x) const {
    std::vector<KhachHang> result;
    NodeKhachHang* current = head;
    
    while (current != nullptr) {
        if (current->data.getThanhTien() < x) {
            result.push_back(current->data);
        }
        current = current->next;
    }
    
    // Sắp xếp theo thành tiền tăng dần
    std::sort(result.begin(), result.end(), 
              [](const KhachHang& a, const KhachHang& b) {
                  return a.getThanhTien() < b.getThanhTien();
              });
    
    return result;
}