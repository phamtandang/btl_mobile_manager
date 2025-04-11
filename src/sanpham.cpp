#include "../include/sanpham.h"
#include "../include/utils.h"
#include "../include/constants.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Khởi tạo biến toàn cục
NodeSanPham* dsSanPham = NULL;

void themSanPham(NodeSanPham*& head) {
    SanPham sp;
    
    cout << "\n=== THÊM SẢN PHẨM MỚI ===\n";
    sp.maSP = nhapChuoi("Nhập mã sản phẩm: ");
    
    // Kiểm tra mã sản phẩm đã tồn tại chưa
    NodeSanPham* current = head;
    while (current != NULL) {
        if (current->data.maSP == sp.maSP) {
            cout << "Mã sản phẩm đã tồn tại. Vui lòng nhập mã khác.\n";
            return;
        }
        current = current->next;
    }
    
    sp.tenSP = nhapChuoi("Nhập tên sản phẩm: ");
    sp.maNCC = nhapChuoi("Nhập mã nhà cung cấp: ");
    sp.tenNCC = nhapChuoi("Nhập tên nhà cung cấp: ");
    sp.ngayNhap = nhapChuoi("Nhập ngày nhập (DD/MM/YYYY): ");
    sp.soLuong = nhapSoNguyen("Nhập số lượng: ");
    sp.donGia = nhapSoThuc("Nhập đơn giá: ");
    sp.thanhTien = sp.soLuong * sp.donGia;
    
    // Tạo node mới và thêm vào đầu danh sách
    NodeSanPham* newNode = new NodeSanPham;
    newNode->data = sp;
    newNode->next = head;
    head = newNode;
    
    cout << "Thêm sản phẩm thành công!\n";
}

void hienThiDanhSachSanPham(NodeSanPham* head) {
    if (head == NULL) {
        cout << "\nDanh sách sản phẩm trống.\n";
        return;
    }
    
    cout << "\n=== DANH SÁCH SẢN PHẨM ===\n";
    cout << left << setw(COL_MA_SP_WIDTH) << "Mã SP" 
         << setw(COL_TEN_SP_WIDTH) << "Tên SP" 
         << setw(COL_MA_NCC_WIDTH) << "Mã NCC" 
         << setw(COL_TEN_NCC_WIDTH) << "Tên NCC" 
         << setw(COL_NGAY_NHAP_WIDTH) << "Ngày nhập" 
         << setw(COL_SO_LUONG_WIDTH) << "Số lượng" 
         << setw(COL_DON_GIA_WIDTH) << "Đơn giá" 
         << setw(COL_THANH_TIEN_WIDTH) << "Thành tiền" << endl;
    cout << string(115, '-') << endl;
    
    NodeSanPham* current = head;
    while (current != NULL) {
        cout << left << setw(COL_MA_SP_WIDTH) << current->data.maSP 
             << setw(COL_TEN_SP_WIDTH) << current->data.tenSP 
             << setw(COL_MA_NCC_WIDTH) << current->data.maNCC 
             << setw(COL_TEN_NCC_WIDTH) << current->data.tenNCC 
             << setw(COL_NGAY_NHAP_WIDTH) << current->data.ngayNhap 
             << setw(COL_SO_LUONG_WIDTH) << current->data.soLuong 
             << setw(COL_DON_GIA_WIDTH) << fixed << setprecision(2) << current->data.donGia 
             << setw(COL_THANH_TIEN_WIDTH) << fixed << setprecision(2) << current->data.thanhTien << endl;
        current = current->next;
    }
}

void timKiemSanPham(NodeSanPham* head) {
    if (head == NULL) {
        cout << "\nDanh sách sản phẩm trống.\n";
        return;
    }
    
    cout << "\n=== TÌM KIẾM SẢN PHẨM ===\n";
    cout << "1. Tìm theo mã sản phẩm\n";
    cout << "2. Tìm theo tên sản phẩm\n";
    int choice = nhapSoNguyen("Chọn cách tìm kiếm: ");
    
    string searchValue;
    bool found = false;
    
    switch (choice) {
        case 1:
            searchValue = nhapChuoi("Nhập mã sản phẩm cần tìm: ");
            break;
        case 2:
            searchValue = nhapChuoi("Nhập tên sản phẩm cần tìm: ");
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
            return;
    }
    
    cout << "\n=== KẾT QUẢ TÌM KIẾM ===\n";
    cout << left << setw(COL_MA_SP_WIDTH) << "Mã SP" 
         << setw(COL_TEN_SP_WIDTH) << "Tên SP" 
         << setw(COL_MA_NCC_WIDTH) << "Mã NCC" 
         << setw(COL_TEN_NCC_WIDTH) << "Tên NCC" 
         << setw(COL_NGAY_NHAP_WIDTH) << "Ngày nhập" 
         << setw(COL_SO_LUONG_WIDTH) << "Số lượng" 
         << setw(COL_DON_GIA_WIDTH) << "Đơn giá" 
         << setw(COL_THANH_TIEN_WIDTH) << "Thành tiền" << endl;
    cout << string(115, '-') << endl;
    
    NodeSanPham* current = head;
    while (current != NULL) {
        if ((choice == 1 && current->data.maSP == searchValue) || 
            (choice == 2 && current->data.tenSP.find(searchValue) != string::npos)) {
            cout << left << setw(COL_MA_SP_WIDTH) << current->data.maSP 
                 << setw(COL_TEN_SP_WIDTH) << current->data.tenSP 
                 << setw(COL_MA_NCC_WIDTH) << current->data.maNCC 
                 << setw(COL_TEN_NCC_WIDTH) << current->data.tenNCC 
                 << setw(COL_NGAY_NHAP_WIDTH) << current->data.ngayNhap 
                 << setw(COL_SO_LUONG_WIDTH) << current->data.soLuong 
                 << setw(COL_DON_GIA_WIDTH) << fixed << setprecision(2) << current->data.donGia 
                 << setw(COL_THANH_TIEN_WIDTH) << fixed << setprecision(2) << current->data.thanhTien << endl;
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "Không tìm thấy sản phẩm phù hợp.\n";
    }
}

void suaSanPham(NodeSanPham* head) {
    if (head == NULL) {
        cout << "\nDanh sách sản phẩm trống.\n";
        return;
    }
    
    string maSP = nhapChuoi("\nNhập mã sản phẩm cần sửa: ");
    NodeSanPham* current = head;
    bool found = false;
    
    while (current != NULL && !found) {
        if (current->data.maSP == maSP) {
            found = true;
            cout << "\n=== THÔNG TIN SẢN PHẨM HIỆN TẠI ===\n";
            cout << "Mã SP: " << current->data.maSP << endl;
            cout << "Tên SP: " << current->data.tenSP << endl;
            cout << "Mã NCC: " << current->data.maNCC << endl;
            cout << "Tên NCC: " << current->data.tenNCC << endl;
            cout << "Ngày nhập: " << current->data.ngayNhap << endl;
            cout << "Số lượng: " << current->data.soLuong << endl;
            cout << "Đơn giá: " << current->data.donGia << endl;
            cout << "Thành tiền: " << current->data.thanhTien << endl;
            
            cout << "\n=== CẬP NHẬT THÔNG TIN ===\n";
            cout << "Nhấn Enter để giữ nguyên thông tin cũ\n";
            
            string input;
            
            input = nhapChuoi("Nhập tên sản phẩm mới: ");
            if (!input.empty()) current->data.tenSP = input;
            
            input = nhapChuoi("Nhập mã nhà cung cấp mới: ");
            if (!input.empty()) current->data.maNCC = input;
            
            input = nhapChuoi("Nhập tên nhà cung cấp mới: ");
            if (!input.empty()) current->data.tenNCC = input;
            
            input = nhapChuoi("Nhập ngày nhập mới (DD/MM/YYYY): ");
            if (!input.empty()) current->data.ngayNhap = input;
            
            cout << "Nhập số lượng mới (hiện tại: " << current->data.soLuong << "): ";
            string soLuongStr;
            getline(cin, soLuongStr);
            if (!soLuongStr.empty()) {
                try {
                    current->data.soLuong = stoi(soLuongStr);
                } catch (...) {
                    cout << "Giá trị không hợp lệ, giữ nguyên số lượng cũ.\n";
                }
            }
            
            cout << "Nhập đơn giá mới (hiện tại: " << current->data.donGia << "): ";
            string donGiaStr;
            getline(cin, donGiaStr);
            if (!donGiaStr.empty()) {
                try {
                    current->data.donGia = stod(donGiaStr);
                } catch (...) {
                    cout << "Giá trị không hợp lệ, giữ nguyên đơn giá cũ.\n";
                }
            }
            
            // Cập nhật thành tiền
            current->data.thanhTien = current->data.soLuong * current->data.donGia;
            
            cout << "Cập nhật thông tin sản phẩm thành công!\n";
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "Không tìm thấy sản phẩm có mã " << maSP << endl;
    }
}

void xoaSanPham(NodeSanPham*& head) {
    if (head == NULL) {
        cout << "\nDanh sách sản phẩm trống.\n";
        return;
    }
    
    string maSP = nhapChuoi("\nNhập mã sản phẩm cần xóa: ");
    
    // Xử lý trường hợp xóa node đầu tiên
    if (head != NULL && head->data.maSP == maSP) {
        NodeSanPham* temp = head;
        head = head->next;
        delete temp;
        cout << "Xóa sản phẩm thành công!\n";
        return;
    }
    
    // Xử lý các trường hợp khác
    NodeSanPham* current = head;
    NodeSanPham* prev = NULL;
    bool found = false;
    
    while (current != NULL && !found) {
        if (current->data.maSP == maSP) {
            found = true;
            prev->next = current->next;
            delete current;
            cout << "Xóa sản phẩm thành công!\n";
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    if (!found) {
        cout << "Không tìm thấy sản phẩm có mã " << maSP << endl;
    }
}

void sapXepSanPham(NodeSanPham*& head) {
    if (head == NULL || head->next == NULL) {
        cout << "\nDanh sách sản phẩm trống hoặc chỉ có một phần tử.\n";
        return;
    }
    
    cout << "\n=== SẮP XẾP SẢN PHẨM ===\n";
    cout << "1. Sắp xếp theo mã sản phẩm\n";
    cout << "2. Sắp xếp theo tên sản phẩm\n";
    cout << "3. Sắp xếp theo số lượng\n";
    cout << "4. Sắp xếp theo đơn giá\n";
    cout << "5. Sắp xếp theo thành tiền\n";
    int choice = nhapSoNguyen("Chọn cách sắp xếp: ");
    
    cout << "1. Sắp xếp tăng dần\n";
    cout << "2. Sắp xếp giảm dần\n";
    int order = nhapSoNguyen("Chọn thứ tự sắp xếp: ");
    
    bool ascending = (order == 1);
    
    // Bubble sort
    bool swapped;
    NodeSanPham* ptr1;
    NodeSanPham* lptr = NULL;
    
    if (head == NULL)
        return;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            bool shouldSwap = false;
            
            switch (choice) {
                case 1: // Mã sản phẩm
                    shouldSwap = ascending ? 
                                (ptr1->data.maSP > ptr1->next->data.maSP) : 
                                (ptr1->data.maSP < ptr1->next->data.maSP);
                    break;
                case 2: // Tên sản phẩm
                    shouldSwap = ascending ? 
                                (ptr1->data.tenSP > ptr1->next->data.tenSP) : 
                                (ptr1->data.tenSP < ptr1->next->data.tenSP);
                    break;
                case 3: // Số lượng
                    shouldSwap = ascending ? 
                                (ptr1->data.soLuong > ptr1->next->data.soLuong) : 
                                (ptr1->data.soLuong < ptr1->next->data.soLuong);
                    break;
                case 4: // Đơn giá
                    shouldSwap = ascending ? 
                                (ptr1->data.donGia > ptr1->next->data.donGia) : 
                                (ptr1->data.donGia < ptr1->next->data.donGia);
                    break;
                case 5: // Thành tiền
                    shouldSwap = ascending ? 
                                (ptr1->data.thanhTien > ptr1->next->data.thanhTien) : 
                                (ptr1->data.thanhTien < ptr1->next->data.thanhTien);
                    break;
                default:
                    cout << "Lựa chọn không hợp lệ.\n";
                    return;
            }
            
            if (shouldSwap) {
                SanPham temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    
    cout << "Sắp xếp thành công!\n";
    hienThiDanhSachSanPham(head);
}

void thongKeSanPham(NodeSanPham* head) {
    if (head == NULL) {
        cout << "\nDanh sách sản phẩm trống.\n";
        return;
    }
    
    int tongSoSP = 0;
    int tongSoLuong = 0;
    double tongGiaTri = 0;
    
    NodeSanPham* current = head;
    while (current != NULL) {
        tongSoSP++;
        tongSoLuong += current->data.soLuong;
        tongGiaTri += current->data.thanhTien;
        current = current->next;
    }
    
    cout << "\n=== THỐNG KÊ SẢN PHẨM ===\n";
    cout << "Tổng số sản phẩm: " << tongSoSP << endl;
    cout << "Tổng số lượng: " << tongSoLuong << endl;
    cout << "Tổng giá trị: " << fixed << setprecision(2) << tongGiaTri << endl;
}