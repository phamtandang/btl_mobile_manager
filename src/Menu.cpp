#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <filesystem>

// Constructor
Menu::Menu() : thongKe(qlKhachHang, qlSanPham) {
    // Tạo thư mục data nếu chưa tồn tại
    // std::filesystem::create_directories("data");
    
    // Đọc dữ liệu từ file khi khởi tạo
    qlKhachHang.docFile(KHACH_HANG_FILE);
    qlSanPham.docFile(SAN_PHAM_FILE);
}

// Hiển thị menu chính
void Menu::hienThiMenuChinh() {
    Utils::clearScreen();
    std::cout << "\n=============== MENU CHÍNH ===============\n";
    std::cout << "1. Quản lý khách hàng\n";
    std::cout << "2. Quản lý sản phẩm\n";
    std::cout << "3. Thống kê\n";
    std::cout << "0. Thoát chương trình\n";
    Utils::drawLine(40);
}

// Xử lý menu chính
void Menu::xuLyMenuChinh() {
    int luaChon;
    bool thoat = false;
    
    while (!thoat) {
        hienThiMenuChinh();
        luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 3);
        
        switch (luaChon) {
            case 1:
                xuLyMenuKhachHang();
                break;
            case 2:
                xuLyMenuSanPham();
                break;
            case 3:
                xuLyMenuThongKe();
                break;
            case 0:
                std::cout << "Đã lưu dữ liệu. Cảm ơn bạn đã sử dụng chương trình!\n";
                // Lưu dữ liệu trước khi thoát
                qlKhachHang.ghiFile(KHACH_HANG_FILE);
                qlSanPham.ghiFile(SAN_PHAM_FILE);
                thoat = true;
                break;
        }
    }
}

// Hiển thị menu quản lý khách hàng
void Menu::hienThiMenuKhachHang() {
    Utils::clearScreen();
    std::cout << "\n=============== QUẢN LÝ KHÁCH HÀNG ===============\n";
    std::cout << "1. Nhập danh sách khách hàng\n";
    std::cout << "2. Hiển thị danh sách khách hàng\n";
    std::cout << "3. Thêm khách hàng\n";
    std::cout << "4. Sửa thông tin khách hàng\n";
    std::cout << "5. Xóa khách hàng\n";
    std::cout << "6. Tìm kiếm khách hàng\n";
    std::cout << "7. Sắp xếp khách hàng\n";
    std::cout << "8. Đọc dữ liệu từ file\n";
    std::cout << "9. Ghi dữ liệu vào file\n";
    std::cout << "0. Quay lại menu chính\n";
    Utils::drawLine(50);
}

// Xử lý menu quản lý khách hàng
void Menu::xuLyMenuKhachHang() {
    int luaChon;
    bool quayLai = false;
    
    while (!quayLai) {
        hienThiMenuKhachHang();
        luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 9);
        
        switch (luaChon) {
            case 1:
                nhapDanhSachKhachHang();
                Utils::pause();
                break;
            case 2:
                qlKhachHang.hienThiDanhSach();
                Utils::pause();
                break;
            case 3: {
                KhachHang kh;
                kh.nhap();
                qlKhachHang.themKhachHang(kh);
                Utils::pause();
                break;
            }
            case 4: {
                std::string maKH = Utils::inputString("Nhập mã khách hàng cần sửa: ");
                NodeKhachHang* node = qlKhachHang.timKiemTheoMa(maKH);
                if (node != nullptr) {
                    std::cout << "Thông tin khách hàng hiện tại:\n";
                    node->data.hienThi();
                    
                    std::cout << "\nNhập thông tin mới:\n";
                    KhachHang khMoi;
                    khMoi.nhap();
                    
                    if (qlKhachHang.suaKhachHang(maKH, khMoi)) {
                        std::cout << "Sửa thông tin khách hàng thành công.\n";
                    } else {
                        std::cout << "Sửa thông tin khách hàng thất bại.\n";
                    }
                } else {
                    std::cout << "Không tìm thấy khách hàng có mã " << maKH << std::endl;
                }
                Utils::pause();
                break;
            }
            case 5: {
                std::string maKH = Utils::inputString("Nhập mã khách hàng cần xóa: ");
                if (qlKhachHang.xoaKhachHang(maKH)) {
                    std::cout << "Xóa khách hàng thành công.\n";
                } else {
                    std::cout << "Không tìm thấy khách hàng có mã " << maKH << std::endl;
                }
                Utils::pause();
                break;
            }
            case 6:
                timKiemKhachHang();
                Utils::pause();
                break;
            case 7:
                sapXepKhachHang();
                Utils::pause();
                break;
            case 8:
                if (qlKhachHang.docFile(KHACH_HANG_FILE)) {
                    std::cout << "Đọc dữ liệu khách hàng từ file thành công.\n";
                } else {
                    std::cout << "Đọc dữ liệu khách hàng từ file thất bại.\n";
                }
                Utils::pause();
                break;
            case 9:
                if (qlKhachHang.ghiFile(KHACH_HANG_FILE)) {
                    std::cout << "Ghi dữ liệu khách hàng vào file thành công.\n";
                } else {
                    std::cout << "Ghi dữ liệu khách hàng vào file thất bại.\n";
                }
                Utils::pause();
                break;
            case 0:
                quayLai = true;
                break;
        }
    }
}

// Hiển thị menu quản lý sản phẩm
void Menu::hienThiMenuSanPham() {
    Utils::clearScreen();
    std::cout << "\n=============== QUẢN LÝ SẢN PHẨM ===============\n";
    std::cout << "1. Nhập danh sách sản phẩm\n";
    std::cout << "2. Hiển thị danh sách sản phẩm\n";
    std::cout << "3. Thêm sản phẩm\n";
    std::cout << "4. Sửa thông tin sản phẩm\n";
    std::cout << "5. Xóa sản phẩm\n";
    std::cout << "6. Tìm kiếm sản phẩm\n";
    std::cout << "7. Sắp xếp sản phẩm\n";
    std::cout << "8. Đọc dữ liệu từ file\n";
    std::cout << "9. Ghi dữ liệu vào file\n";
    std::cout << "0. Quay lại menu chính\n";
    Utils::drawLine(50);
}

// Xử lý menu quản lý sản phẩm
void Menu::xuLyMenuSanPham() {
    int luaChon;
    bool quayLai = false;
    
    while (!quayLai) {
        hienThiMenuSanPham();
        luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 9);
        
        switch (luaChon) {
            case 1:
                nhapDanhSachSanPham();
                Utils::pause();
                break;
            case 2:
                qlSanPham.hienThiDanhSach();
                Utils::pause();
                break;
            case 3: {
                SanPham sp;
                sp.nhap();
                qlSanPham.themSanPham(sp);
                Utils::pause();
                break;
            }
            case 4: {
                std::string maSP = Utils::inputString("Nhập mã sản phẩm cần sửa: ");
                NodeSanPham* node = qlSanPham.timKiemTheoMa(maSP);
                if (node != nullptr) {
                    std::cout << "Thông tin sản phẩm hiện tại:\n";
                    node->data.hienThi();
                    
                    std::cout << "\nNhập thông tin mới:\n";
                    SanPham spMoi;
                    spMoi.nhap();
                    
                    if (qlSanPham.suaSanPham(maSP, spMoi)) {
                        std::cout << "Sửa thông tin sản phẩm thành công.\n";
                    } else {
                        std::cout << "Sửa thông tin sản phẩm thất bại.\n";
                    }
                } else {
                    std::cout << "Không tìm thấy sản phẩm có mã " << maSP << std::endl;
                }
                Utils::pause();
                break;
            }
            case 5: {
                std::string maSP = Utils::inputString("Nhập mã sản phẩm cần xóa: ");
                if (qlSanPham.xoaSanPham(maSP)) {
                    std::cout << "Xóa sản phẩm thành công.\n";
                } else {
                    std::cout << "Không tìm thấy sản phẩm có mã " << maSP << std::endl;
                }
                Utils::pause();
                break;
            }
            case 6:
                timKiemSanPham();
                Utils::pause();
                break;
            case 7:
                sapXepSanPham();
                Utils::pause();
                break;
            case 8:
                if (qlSanPham.docFile(SAN_PHAM_FILE)) {
                    std::cout << "Đọc dữ liệu sản phẩm từ file thành công.\n";
                } else {
                    std::cout << "Đọc dữ liệu sản phẩm từ file thất bại.\n";
                }
                Utils::pause();
                break;
            case 9:
                if (qlSanPham.ghiFile(SAN_PHAM_FILE)) {
                    std::cout << "Ghi dữ liệu sản phẩm vào file thành công.\n";
                } else {
                    std::cout << "Ghi dữ liệu sản phẩm vào file thất bại.\n";
                }
                Utils::pause();
                break;
            case 0:
                quayLai = true;
                break;
        }
    }
}

// Hiển thị menu thống kê
void Menu::hienThiMenuThongKe() {
    Utils::clearScreen();
    std::cout << "\n=============== THỐNG KÊ ===============\n";
    std::cout << "1. Tình trạng cửa hàng (Tổng vốn nhập, tổng tiền bán ra, lãi/lỗ)\n";
    std::cout << "2. Tìm phần tử lớn nhất, nhỏ nhất\n";
    std::cout << "3. Tính tổng, trung bình, đếm\n";
    std::cout << "4. Thống kê theo điều kiện\n";
    std::cout << "5. Thống kê top 5 sản phẩm bán chạy nhất\n";
    std::cout << "6. Thống kê doanh thu theo tháng\n";
    std::cout << "7. Thống kê doanh thu theo quý\n";
    std::cout << "8. Thống kê lãi/lỗ theo tháng\n";
    std::cout << "0. Quay lại menu chính\n";
    Utils::drawLine(70);
}

// Xử lý menu thống kê
void Menu::xuLyMenuThongKe() {
    int luaChon;
    bool quayLai = false;
    
    while (!quayLai) {
        hienThiMenuThongKe();
        luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 8);
        
        switch (luaChon) {
            case 1:
                thongKe.hienThiTinhTrangCuaHang();
                Utils::pause();
                break;
            case 2:
                timPhanTuLonNhatNhoNhat();
                Utils::pause();
                break;
            case 3:
                tinhTongTrungBinhDem();
                Utils::pause();
                break;
            case 4:
                thongKeTheoDieuKien();
                Utils::pause();
                break;
            case 5: {
                auto thongKeSP = thongKe.thongKeSanPhamBanChayNhat(5);
                
                std::cout << "\n========== TOP 5 SẢN PHẨM BÁN CHẠY NHẤT ==========\n";
                std::cout << std::left << std::setw(30) << "Tên sản phẩm" 
                          << std::setw(15) << "Số lượng bán" << std::endl;
                Utils::drawLine(50);
                
                for (const auto& pair : thongKeSP) {
                    std::cout << std::left << std::setw(30) << pair.first 
                              << std::setw(15) << pair.second << std::endl;
                }
                
                Utils::pause();
                break;
            }
            case 6: {
                auto doanhThuThang = thongKe.thongKeDoanhThuTheoThang();
                
                std::cout << "\n========== DOANH THU THEO THÁNG ==========\n";
                std::cout << std::left << std::setw(15) << "Tháng/Năm" 
                          << std::setw(20) << "Doanh thu" << std::endl;
                Utils::drawLine(40);
                
                for (const auto& pair : doanhThuThang) {
                    std::cout << std::left << std::setw(15) << pair.first 
                              << std::setw(20) << Utils::formatCurrency(pair.second) << std::endl;
                }
                
                Utils::pause();
                break;
            }
            case 7: {
                auto doanhThuQuy = thongKe.thongKeDoanhThuTheoQuy();
                
                std::cout << "\n========== DOANH THU THEO QUÝ ==========\n";
                std::cout << std::left << std::setw(10) << "Quý" 
                          << std::setw(20) << "Doanh thu" << std::endl;
                Utils::drawLine(35);
                
                for (const auto& pair : doanhThuQuy) {
                    std::cout << std::left << std::setw(10) << pair.first 
                              << std::setw(20) << Utils::formatCurrency(pair.second) << std::endl;
                }
                
                Utils::pause();
                break;
            }
            case 8: {
                auto laiLoThang = thongKe.thongKeLaiLoTheoThang();
                
                std::cout << "\n========== LÃI/LỖ THEO THÁNG ==========\n";
                std::cout << std::left << std::setw(15) << "Tháng/Năm" 
                          << std::setw(20) << "Lãi/Lỗ" << std::endl;
                Utils::drawLine(40);
                
                for (const auto& pair : laiLoThang) {
                    std::cout << std::left << std::setw(15) << pair.first;
                    
                    if (pair.second >= 0) {
                        std::cout << std::setw(20) << Utils::formatCurrency(pair.second) << " (Lãi)" << std::endl;
                    } else {
                        std::cout << std::setw(20) << Utils::formatCurrency(-pair.second) << " (Lỗ)" << std::endl;
                    }
                }
                
                Utils::pause();
                break;
            }
            case 0:
                quayLai = true;
                break;
        }
    }
}

// Nhập danh sách khách hàng từ bàn phím
void Menu::nhapDanhSachKhachHang() {
    int n = Utils::inputInt("Nhập số lượng khách hàng: ", 0, 100);
    
    for (int i = 0; i < n; i++) {
        std::cout << "\n--- Nhập thông tin khách hàng thứ " << (i + 1) << " ---\n";
        KhachHang kh;
        kh.nhap();
        qlKhachHang.themKhachHang(kh);
    }
    
    std::cout << "Đã nhập xong danh sách " << n << " khách hàng.\n";
}

// Nhập danh sách sản phẩm từ bàn phím
void Menu::nhapDanhSachSanPham() {
    int n = Utils::inputInt("Nhập số lượng sản phẩm: ", 0, 100);
    
    for (int i = 0; i < n; i++) {
        std::cout << "\n--- Nhập thông tin sản phẩm thứ " << (i + 1) << " ---\n";
        SanPham sp;
        sp.nhap();
        qlSanPham.themSanPham(sp);
    }
    
    std::cout << "Đã nhập xong danh sách " << n << " sản phẩm.\n";
}

// Tìm kiếm khách hàng
void Menu::timKiemKhachHang() {
    Utils::clearScreen();
    std::cout << "\n=============== TÌM KIẾM KHÁCH HÀNG ===============\n";
    std::cout << "1. Tìm kiếm theo mã khách hàng\n";
    std::cout << "2. Tìm kiếm theo tên khách hàng\n";
    std::cout << "3. Tìm kiếm theo số điện thoại\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(50);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 3);
    
    switch (luaChon) {
        case 1: {
            std::string maKH = Utils::inputString("Nhập mã khách hàng cần tìm: ");
            NodeKhachHang* node = qlKhachHang.timKiemTheoMa(maKH);
            
            if (node != nullptr) {
                std::cout << "\nKết quả tìm kiếm:\n";
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
                node->data.hienThi();
            } else {
                std::cout << "Không tìm thấy khách hàng có mã " << maKH << std::endl;
            }
            break;
        }
        case 2: {
            std::string tenKH = Utils::inputString("Nhập tên khách hàng cần tìm: ");
            std::vector<NodeKhachHang*> nodes = qlKhachHang.timKiemTheoTen(tenKH);
            
            if (!nodes.empty()) {
                std::cout << "\nKết quả tìm kiếm: " << nodes.size() << " khách hàng\n";
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
                
                for (NodeKhachHang* node : nodes) {
                    node->data.hienThi();
                }
            } else {
                std::cout << "Không tìm thấy khách hàng nào có tên chứa \"" << tenKH << "\"" << std::endl;
            }
            break;
        }
        case 3: {
            std::string sdt = Utils::inputString("Nhập số điện thoại cần tìm: ");
            NodeKhachHang* node = qlKhachHang.timKiemTheoSDT(sdt);
            
            if (node != nullptr) {
                std::cout << "\nKết quả tìm kiếm:\n";
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
                node->data.hienThi();
            } else {
                std::cout << "Không tìm thấy khách hàng có số điện thoại " << sdt << std::endl;
            }
            break;
        }
        case 0:
            // Quay lại
            break;
    }
}

// Tìm kiếm sản phẩm
void Menu::timKiemSanPham() {
    Utils::clearScreen();
    std::cout << "\n=============== TÌM KIẾM SẢN PHẨM ===============\n";
    std::cout << "1. Tìm kiếm theo mã sản phẩm\n";
    std::cout << "2. Tìm kiếm theo tên sản phẩm\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(50);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 2);
    
    switch (luaChon) {
        case 1: {
            std::string maSP = Utils::inputString("Nhập mã sản phẩm cần tìm: ");
            NodeSanPham* node = qlSanPham.timKiemTheoMa(maSP);
            
            if (node != nullptr) {
                std::cout << "\nKết quả tìm kiếm:\n";
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
                node->data.hienThi();
            } else {
                std::cout << "Không tìm thấy sản phẩm có mã " << maSP << std::endl;
            }
            break;
        }
        case 2: {
            std::string tenSP = Utils::inputString("Nhập tên sản phẩm cần tìm: ");
            std::vector<NodeSanPham*> nodes = qlSanPham.timKiemTheoTen(tenSP);
            
            if (!nodes.empty()) {
                std::cout << "\nKết quả tìm kiếm: " << nodes.size() << " sản phẩm\n";
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
                
                for (NodeSanPham* node : nodes) {
                    node->data.hienThi();
                }
            } else {
                std::cout << "Không tìm thấy sản phẩm nào có tên chứa \"" << tenSP << "\"" << std::endl;
            }
            break;
        }
        case 0:
            // Quay lại
            break;
    }
}

// Sắp xếp khách hàng
void Menu::sapXepKhachHang() {
    Utils::clearScreen();
    std::cout << "\n=============== SẮP XẾP KHÁCH HÀNG ===============\n";
    std::cout << "1. Sắp xếp theo mã khách hàng tăng dần\n";
    std::cout << "2. Sắp xếp theo tên khách hàng tăng dần\n";
    std::cout << "3. Sắp xếp theo thành tiền giảm dần\n";
    std::cout << "4. Sắp xếp theo ngày giao dịch tăng dần\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(50);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 4);
    
    switch (luaChon) {
        case 1:
            qlKhachHang.sapXepTheoMaKH();
            qlKhachHang.hienThiDanhSach();
            break;
        case 2:
            qlKhachHang.sapXepTheoTenKH();
            qlKhachHang.hienThiDanhSach();
            break;
        case 3:
            qlKhachHang.sapXepTheoThanhTien();
            qlKhachHang.hienThiDanhSach();
            break;
        case 4:
            qlKhachHang.sapXepTheoNgayGiaoDich();
            qlKhachHang.hienThiDanhSach();
            break;
        case 0:
            // Quay lại
            break;
    }
}

// Sắp xếp sản phẩm
void Menu::sapXepSanPham() {
    Utils::clearScreen();
    std::cout << "\n=============== SẮP XẾP SẢN PHẨM ===============\n";
    std::cout << "1. Sắp xếp theo mã sản phẩm tăng dần\n";
    std::cout << "2. Sắp xếp theo tên sản phẩm tăng dần\n";
    std::cout << "3. Sắp xếp theo đơn giá tăng dần\n";
    std::cout << "4. Sắp xếp theo thành tiền giảm dần\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(50);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 4);
    
    switch (luaChon) {
        case 1:
            qlSanPham.sapXepTheoMaSP();
            qlSanPham.hienThiDanhSach();
            break;
        case 2:
            qlSanPham.sapXepTheoTenSP();
            qlSanPham.hienThiDanhSach();
            break;
        case 3:
            qlSanPham.sapXepTheoDonGia();
            qlSanPham.hienThiDanhSach();
            break;
        case 4:
            qlSanPham.sapXepTheoThanhTien();
            qlSanPham.hienThiDanhSach();
            break;
        case 0:
            // Quay lại
            break;
    }
}

// Tìm phần tử lớn nhất, nhỏ nhất
void Menu::timPhanTuLonNhatNhoNhat() {
    Utils::clearScreen();
    std::cout << "\n=============== TÌM PHẦN TỬ LỚN NHẤT, NHỎ NHẤT ===============\n";
    std::cout << "1. Khách hàng có thành tiền lớn nhất\n";
    std::cout << "2. Khách hàng có thành tiền nhỏ nhất\n";
    std::cout << "3. Sản phẩm có đơn giá lớn nhất\n";
    std::cout << "4. Sản phẩm có đơn giá nhỏ nhất\n";
    std::cout << "5. Sản phẩm có thành tiền lớn nhất\n";
    std::cout << "6. Sản phẩm có thành tiền nhỏ nhất\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(70);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 6);
    
    switch (luaChon) {
        case 1: {
            KhachHang kh = qlKhachHang.timKhachHangThanhTienMax();
            std::cout << "\n========== KHÁCH HÀNG CÓ THÀNH TIỀN LỚN NHẤT ==========\n";
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
            kh.hienThi();
            break;
        }
        case 2: {
            KhachHang kh = qlKhachHang.timKhachHangThanhTienMin();
            std::cout << "\n========== KHÁCH HÀNG CÓ THÀNH TIỀN NHỎ NHẤT ==========\n";
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
            kh.hienThi();
            break;
        }
        case 3: {
            SanPham sp = qlSanPham.timSanPhamDonGiaMax();
            std::cout << "\n========== SẢN PHẨM CÓ ĐƠN GIÁ LỚN NHẤT ==========\n";
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
            sp.hienThi();
            break;
        }
        case 4: {
            SanPham sp = qlSanPham.timSanPhamDonGiaMin();
            std::cout << "\n========== SẢN PHẨM CÓ ĐƠN GIÁ NHỎ NHẤT ==========\n";
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
            sp.hienThi();
            break;
        }
        case 5: {
            SanPham sp = qlSanPham.timSanPhamThanhTienMax();
            std::cout << "\n========== SẢN PHẨM CÓ THÀNH TIỀN LỚN NHẤT ==========\n";
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
            sp.hienThi();
            break;
        }
        case 6: {
            SanPham sp = qlSanPham.timSanPhamThanhTienMin();
            std::cout << "\n========== SẢN PHẨM CÓ THÀNH TIỀN NHỎ NHẤT ==========\n";
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
            sp.hienThi();
            break;
        }
        case 0:
            // Quay lại
            break;
    }
}

// Tính tổng, trung bình, đếm
void Menu::tinhTongTrungBinhDem() {
    Utils::clearScreen();
    std::cout << "\n=============== TÍNH TỔNG, TRUNG BÌNH, ĐẾM ===============\n";
    std::cout << "1. Tổng tiền bán ra\n";
    std::cout << "2. Tổng vốn nhập\n";
    std::cout << "3. Trung bình thành tiền của khách hàng\n";
    std::cout << "4. Trung bình thành tiền của sản phẩm\n";
    std::cout << "5. Đếm số lượng khách hàng\n";
    std::cout << "6. Đếm số lượng sản phẩm\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(70);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 6);
    
    switch (luaChon) {
        case 1: {
            double tongTien = qlKhachHang.tinhTongTien();
            std::cout << "Tổng tiền bán ra: " << Utils::formatCurrency(tongTien) << std::endl;
            break;
        }
        case 2: {
            double tongVon = qlSanPham.tinhTongVonNhap();
            std::cout << "Tổng vốn nhập: " << Utils::formatCurrency(tongVon) << std::endl;
            break;
        }
        case 3: {
            double trungBinh = qlKhachHang.tinhTrungBinhThanhTien();
            std::cout << "Trung bình thành tiền của khách hàng: " << Utils::formatCurrency(trungBinh) << std::endl;
            break;
        }
        case 4: {
            double trungBinh = qlSanPham.tinhTrungBinhThanhTien();
            std::cout << "Trung bình thành tiền của sản phẩm: " << Utils::formatCurrency(trungBinh) << std::endl;
            break;
        }
        case 5: {
            int soLuong = qlKhachHang.demSoLuongKhachHang();
            std::cout << "Số lượng khách hàng: " << soLuong << std::endl;
            break;
        }
        case 6: {
            int soLuong = qlSanPham.demSoLuongSanPham();
            std::cout << "Số lượng sản phẩm: " << soLuong << std::endl;
            break;
        }
        case 0:
            // Quay lại
            break;
    }
}

// Thống kê theo điều kiện
void Menu::thongKeTheoDieuKien() {
    Utils::clearScreen();
    std::cout << "\n=============== THỐNG KÊ THEO ĐIỀU KIỆN ===============\n";
    std::cout << "1. Thống kê khách hàng theo mặt hàng mua\n";
    std::cout << "2. Thống kê doanh thu theo ngày\n";
    std::cout << "3. Thống kê số lượng khách hàng theo tháng\n";
    std::cout << "4. Thống kê sản phẩm theo nhà cung cấp\n";
    std::cout << "5. Thống kê khách hàng có thành tiền lớn hơn X\n";
    std::cout << "6. Thống kê khách hàng có thành tiền nhỏ hơn X\n";
    std::cout << "7. Thống kê sản phẩm có đơn giá lớn hơn X\n";
    std::cout << "8. Thống kê sản phẩm có đơn giá nhỏ hơn X\n";
    std::cout << "0. Quay lại\n";
    Utils::drawLine(70);
    
    int luaChon = Utils::inputInt("Nhập lựa chọn: ", 0, 8);
    
    switch (luaChon) {
        case 1: {
            auto thongKe = qlKhachHang.thongKeTheoMatHang();
            std::cout << "\n========== THỐNG KÊ KHÁCH HÀNG THEO MẶT HÀNG MUA ==========\n";
            std::cout << std::left << std::setw(30) << "Mặt hàng" 
                      << std::setw(15) << "Số lượng khách hàng" << std::endl;
            Utils::drawLine(50);
            
            for (const auto& pair : thongKe) {
                std::cout << std::left << std::setw(30) << pair.first 
                          << std::setw(15) << pair.second << std::endl;
            }
            break;
        }
        case 2: {
            auto thongKe = qlKhachHang.thongKeDoanhThuTheoNgay();
            std::cout << "\n========== THỐNG KÊ DOANH THU THEO NGÀY ==========\n";
            std::cout << std::left << std::setw(15) << "Ngày" 
                      << std::setw(20) << "Doanh thu" << std::endl;
            Utils::drawLine(40);
            
            for (const auto& pair : thongKe) {
                std::cout << std::left << std::setw(15) << pair.first 
                          << std::setw(20) << Utils::formatCurrency(pair.second) << std::endl;
            }
            break;
        }
        case 3: {
            auto thongKe = qlKhachHang.thongKeKhachHangTheoThang();
            std::cout << "\n========== THỐNG KÊ SỐ LƯỢNG KHÁCH HÀNG THEO THÁNG ==========\n";
            std::cout << std::left << std::setw(15) << "Tháng/Năm" 
                      << std::setw(15) << "Số lượng KH" << std::endl;
            Utils::drawLine(40);
            
            for (const auto& pair : thongKe) {
                std::cout << std::left << std::setw(15) << pair.first 
                          << std::setw(15) << pair.second << std::endl;
            }
            break;
        }
        case 4: {
            auto thongKe = qlSanPham.thongKeTheoNhaCungCap();
            std::cout << "\n========== THỐNG KÊ SẢN PHẨM THEO NHÀ CUNG CẤP ==========\n";
            std::cout << std::left << std::setw(30) << "Nhà cung cấp" 
                      << std::setw(15) << "Số lượng SP" << std::endl;
            Utils::drawLine(50);
            
            for (const auto& pair : thongKe) {
                std::cout << std::left << std::setw(30) << pair.first 
                          << std::setw(15) << pair.second << std::endl;
            }
            break;
        }
        case 5: {
            double x = Utils::inputDouble("Nhập giá trị X: ", 0);
            auto thongKe = qlKhachHang.thongKeKhachHangCoThanhTienLonHon(x);
            
            std::cout << "\n========== THỐNG KÊ KHÁCH HÀNG CÓ THÀNH TIỀN > " << Utils::formatCurrency(x) << " ==========\n";
            if (thongKe.empty()) {
                std::cout << "Không có khách hàng nào có thành tiền lớn hơn " << Utils::formatCurrency(x) << std::endl;
                break;
            }
            
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
            
            for (const auto& kh : thongKe) {
                kh.hienThi();
            }
            break;
        }
        case 6: {
            double x = Utils::inputDouble("Nhập giá trị X: ", 0);
            auto thongKe = qlKhachHang.thongKeKhachHangCoThanhTienNhoHon(x);
            
            std::cout << "\n========== THỐNG KÊ KHÁCH HÀNG CÓ THÀNH TIỀN < " << Utils::formatCurrency(x) << " ==========\n";
            if (thongKe.empty()) {
                std::cout << "Không có khách hàng nào có thành tiền nhỏ hơn " << Utils::formatCurrency(x) << std::endl;
                break;
            }
            
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
            
            for (const auto& kh : thongKe) {
                kh.hienThi();
            }
            break;
        }
        case 7: {
            double x = Utils::inputDouble("Nhập giá trị X: ", 0);
            auto thongKe = qlSanPham.thongKeSanPhamCoDonGiaLonHon(x);
            
            std::cout << "\n========== THỐNG KÊ SẢN PHẨM CÓ ĐƠN GIÁ > " << Utils::formatCurrency(x) << " ==========\n";
            if (thongKe.empty()) {
                std::cout << "Không có sản phẩm nào có đơn giá lớn hơn " << Utils::formatCurrency(x) << std::endl;
                break;
            }
            
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
            
            for (const auto& sp : thongKe) {
                sp.hienThi();
            }
            break;
        }
        case 8: {
            double x = Utils::inputDouble("Nhập giá trị X: ", 0);
            auto thongKe = qlSanPham.thongKeSanPhamCoDonGiaNhoHon(x);
            
            std::cout << "\n========== THỐNG KÊ SẢN PHẨM CÓ ĐƠN GIÁ < " << Utils::formatCurrency(x) << " ==========\n";
            if (thongKe.empty()) {
                std::cout << "Không có sản phẩm nào có đơn giá nhỏ hơn " << Utils::formatCurrency(x) << std::endl;
                break;
            }
            
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
            
            for (const auto& sp : thongKe) {
                sp.hienThi();
            }
            break;
        }
        case 0:
            // Quay lại
            break;
    }
}

// Khởi động chương trình
void Menu::run() {
    xuLyMenuChinh();
}