#include "QuanLySanPham.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

// Constructor
QuanLySanPham::QuanLySanPham() : head(nullptr) {}

// Destructor
QuanLySanPham::~QuanLySanPham() {
    // Giải phóng bộ nhớ khi kết thúc chương trình
    NodeSanPham* current = head;
    while (current != nullptr) {
        NodeSanPham* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Kiểm tra danh sách rỗng
bool QuanLySanPham::isEmpty() const {
    return head == nullptr;
}

// Thêm sản phẩm vào danh sách
void QuanLySanPham::themSanPham(const SanPham& sp) {
    // Kiểm tra trùng mã sản phẩm
    if (timKiemTheoMa(sp.getMaSP()) != nullptr) {
        std::cout << "Mã sản phẩm đã tồn tại. Không thể thêm mới.\n";
        return;
    }
    
    NodeSanPham* newNode = new NodeSanPham(sp);
    
    // Nếu danh sách rỗng hoặc thêm vào đầu danh sách
    if (head == nullptr) {
        head = newNode;
    } else {
        // Thêm vào cuối danh sách
        NodeSanPham* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    std::cout << "Đã thêm sản phẩm thành công.\n";
}

// Hiển thị toàn bộ danh sách sản phẩm
void QuanLySanPham::hienThiDanhSach() const {
    if (isEmpty()) {
        std::cout << "Danh sách sản phẩm rỗng.\n";
        return;
    }
    
    std::cout << "\n=============== DANH SÁCH SẢN PHẨM ===============\n";
    std::cout << std::left << std::setw(10) << "Mã SP" 
              << std::setw(20) << "Tên SP" 
              << std::setw(15) << "Mã NCC" 
              << std::setw(20) << "Tên NCC" 
              << std::setw(12) << "Ngày nhập" 
              << std::setw(8) << "SL" 
              << std::setw(15) << "Đơn giá" 
              << std::setw(15) << "Thành tiền" 
              << std::endl;
    Utils::drawLine(120);
    
    NodeSanPham* current = head;
    while (current != nullptr) {
        current->data.hienThi();
        current = current->next;
    }
    Utils::drawLine(120);
}

// Tìm kiếm sản phẩm theo mã
NodeSanPham* QuanLySanPham::timKiemTheoMa(const std::string& maSP) const {
    NodeSanPham* current = head;
    while (current != nullptr) {
        if (current->data.getMaSP() == maSP) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Tìm kiếm sản phẩm theo tên
std::vector<NodeSanPham*> QuanLySanPham::timKiemTheoTen(const std::string& tenSP) const {
    std::vector<NodeSanPham*> result;
    NodeSanPham* current = head;
    
    // Chuyển tên cần tìm và tên SP thành chữ thường để so sánh không phân biệt hoa thường
    std::string tenSPLower = tenSP;
    std::transform(tenSPLower.begin(), tenSPLower.end(), tenSPLower.begin(), ::tolower);
    
    while (current != nullptr) {
        std::string currentTenSP = current->data.getTenSP();
        std::transform(currentTenSP.begin(), currentTenSP.end(), currentTenSP.begin(), ::tolower);
        
        if (currentTenSP.find(tenSPLower) != std::string::npos) {
            result.push_back(current);
        }
        current = current->next;
    }
    
    return result;
}

// Xóa sản phẩm theo mã
bool QuanLySanPham::xoaSanPham(const std::string& maSP) {
    if (isEmpty()) {
        return false;
    }
    
    // Nếu xóa node đầu
    if (head->data.getMaSP() == maSP) {
        NodeSanPham* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    // Tìm kiếm và xóa node trong danh sách
    NodeSanPham* current = head;
    while (current->next != nullptr && current->next->data.getMaSP() != maSP) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        NodeSanPham* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
    
    return false;
}

// Sửa thông tin sản phẩm
bool QuanLySanPham::suaSanPham(const std::string& maSP, const SanPham& spMoi) {
    NodeSanPham* node = timKiemTheoMa(maSP);
    if (node == nullptr) {
        return false;
    }
    
    // Không cho phép thay đổi mã sản phẩm
    if (spMoi.getMaSP() != maSP) {
        std::cout << "Không được phép thay đổi mã sản phẩm.\n";
        return false;
    }
    
    node->data = spMoi;
    return true;
}

// Đọc dữ liệu từ file
bool QuanLySanPham::docFile(const std::string& tenFile) {
    std::ifstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Không thể mở file: " << tenFile << std::endl;
        return false;
    }
    
    // Xóa danh sách hiện tại trước khi đọc file
    NodeSanPham* current = head;
    while (current != nullptr) {
        NodeSanPham* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        SanPham sp;
        sp.fromString(line);
        themSanPham(sp);
    }
    
    file.close();
    return true;
}

// Ghi dữ liệu vào file
bool QuanLySanPham::ghiFile(const std::string& tenFile) const {
    std::ofstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Không thể mở file: " << tenFile << std::endl;
        return false;
    }
    
    NodeSanPham* current = head;
    while (current != nullptr) {
        file << current->data.toString() << std::endl;
        current = current->next;
    }
    
    file.close();
    return true;
}

// Sắp xếp sản phẩm theo mã sản phẩm tăng dần
void QuanLySanPham::sapXepTheoMaSP() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeSanPham* current;
    NodeSanPham* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getMaSP() > current->next->data.getMaSP()) {
                // Hoán đổi dữ liệu của hai node
                SanPham temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp sản phẩm theo mã tăng dần.\n";
}

// Sắp xếp sản phẩm theo tên sản phẩm tăng dần
void QuanLySanPham::sapXepTheoTenSP() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeSanPham* current;
    NodeSanPham* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getTenSP() > current->next->data.getTenSP()) {
                // Hoán đổi dữ liệu của hai node
                SanPham temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp sản phẩm theo tên tăng dần.\n";
}

// Sắp xếp sản phẩm theo đơn giá tăng dần
void QuanLySanPham::sapXepTheoDonGia() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeSanPham* current;
    NodeSanPham* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getDonGia() > current->next->data.getDonGia()) {
                // Hoán đổi dữ liệu của hai node
                SanPham temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp sản phẩm theo đơn giá tăng dần.\n";
}

// Sắp xếp sản phẩm theo thành tiền giảm dần
void QuanLySanPham::sapXepTheoThanhTien() {
    if (isEmpty() || head->next == nullptr) {
        return;  // Danh sách rỗng hoặc chỉ có một phần tử
    }
    
    bool swapped;
    NodeSanPham* current;
    NodeSanPham* last = nullptr;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->data.getThanhTien() < current->next->data.getThanhTien()) {
                // Hoán đổi dữ liệu của hai node
                SanPham temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    std::cout << "Đã sắp xếp sản phẩm theo thành tiền giảm dần.\n";
}

// Tìm sản phẩm có đơn giá lớn nhất
SanPham QuanLySanPham::timSanPhamDonGiaMax() const {
    if (isEmpty()) {
        return SanPham();  // Trả về sản phẩm rỗng nếu danh sách rỗng
    }
    
    NodeSanPham* current = head;
    SanPham maxSP = current->data;
    
    while (current != nullptr) {
        if (current->data.getDonGia() > maxSP.getDonGia()) {
            maxSP = current->data;
        }
        current = current->next;
    }
    
    return maxSP;
}

// Tìm sản phẩm có đơn giá nhỏ nhất
SanPham QuanLySanPham::timSanPhamDonGiaMin() const {
    if (isEmpty()) {
        return SanPham();  // Trả về sản phẩm rỗng nếu danh sách rỗng
    }
    
    NodeSanPham* current = head;
    SanPham minSP = current->data;
    
    while (current != nullptr) {
        if (current->data.getDonGia() < minSP.getDonGia()) {
            minSP = current->data;
        }
        current = current->next;
    }
    
    return minSP;
}

// Tìm sản phẩm có thành tiền lớn nhất
SanPham QuanLySanPham::timSanPhamThanhTienMax() const {
    if (isEmpty()) {
        return SanPham();  // Trả về sản phẩm rỗng nếu danh sách rỗng
    }
    
    NodeSanPham* current = head;
    SanPham maxSP = current->data;
    
    while (current != nullptr) {
        if (current->data.getThanhTien() > maxSP.getThanhTien()) {
            maxSP = current->data;
        }
        current = current->next;
    }
    
    return maxSP;
}

// Tìm sản phẩm có thành tiền nhỏ nhất
SanPham QuanLySanPham::timSanPhamThanhTienMin() const {
    if (isEmpty()) {
        return SanPham();  // Trả về sản phẩm rỗng nếu danh sách rỗng
    }
    
    NodeSanPham* current = head;
    SanPham minSP = current->data;
    
    while (current != nullptr) {
        if (current->data.getThanhTien() < minSP.getThanhTien()) {
            minSP = current->data;
        }
        current = current->next;
    }
    
    return minSP;
}

// Tính tổng vốn nhập của tất cả sản phẩm
double QuanLySanPham::tinhTongVonNhap() const {
    double tongVon = 0.0;
    NodeSanPham* current = head;
    
    while (current != nullptr) {
        tongVon += current->data.getThanhTien();
        current = current->next;
    }
    
    return tongVon;
}

// Tính trung bình thành tiền của tất cả sản phẩm
double QuanLySanPham::tinhTrungBinhThanhTien() const {
    if (isEmpty()) {
        return 0.0;
    }
    
    int count = demSoLuongSanPham();
    return tinhTongVonNhap() / count;
}

// Đếm số lượng sản phẩm
int QuanLySanPham::demSoLuongSanPham() const {
    int count = 0;
    NodeSanPham* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Thống kê sản phẩm theo nhà cung cấp
std::vector<std::pair<std::string, int>> QuanLySanPham::thongKeTheoNhaCungCap() const {
    std::map<std::string, int> nccCount;
    NodeSanPham* current = head;
    
    while (current != nullptr) {
        std::string tenNcc = current->data.getTenNhaCungCap();
        nccCount[tenNcc]++;
        current = current->next;
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp sau này
    std::vector<std::pair<std::string, int>> result;
    for (const auto& pair : nccCount) {
        result.push_back(pair);
    }
    
    // Sắp xếp theo số lượng giảm dần
    std::sort(result.begin(), result.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });
    
    return result;
}

// Thống kê sản phẩm có đơn giá lớn hơn X
std::vector<SanPham> QuanLySanPham::thongKeSanPhamCoDonGiaLonHon(double x) const {
    std::vector<SanPham> result;
    NodeSanPham* current = head;
    
    while (current != nullptr) {
        if (current->data.getDonGia() > x) {
            result.push_back(current->data);
        }
        current = current->next;
    }
    
    // Sắp xếp theo đơn giá giảm dần
    std::sort(result.begin(), result.end(), 
              [](const SanPham& a, const SanPham& b) {
                  return a.getDonGia() > b.getDonGia();
              });
    
    return result;
}

// Thống kê sản phẩm có đơn giá nhỏ hơn X
std::vector<SanPham> QuanLySanPham::thongKeSanPhamCoDonGiaNhoHon(double x) const {
    std::vector<SanPham> result;
    NodeSanPham* current = head;
    
    while (current != nullptr) {
        if (current->data.getDonGia() < x) {
            result.push_back(current->data);
        }
        current = current->next;
    }
    
    // Sắp xếp theo đơn giá tăng dần
    std::sort(result.begin(), result.end(), 
              [](const SanPham& a, const SanPham& b) {
                  return a.getDonGia() < b.getDonGia();
              });
    
    return result;
}

// Thống kê tổng giá trị nhập theo ngày
std::vector<std::pair<std::string, double>> QuanLySanPham::thongKeGiaTriNhapTheoNgay() const {
    std::map<std::string, double> giaTriNhapNgay;
    NodeSanPham* current = head;
    
    while (current != nullptr) {
        std::string ngay = current->data.getNgayNhap();
        giaTriNhapNgay[ngay] += current->data.getThanhTien();
        current = current->next;
    }
    
    // Chuyển từ map sang vector để có thể sắp xếp sau này
    std::vector<std::pair<std::string, double>> result;
    for (const auto& pair : giaTriNhapNgay) {
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