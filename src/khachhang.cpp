#include "../include/khachhang.h"
#include "../include/utils.h"
#include "../include/constants.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Khởi tạo biến toàn cục
NodeKhachHang* dsKhachHang = NULL;

void themKhachHang(NodeKhachHang*& head) {
    KhachHang kh;
    
    cout << "\n=== THÊM KHÁCH HÀNG MỚI ===\n";
    kh.maKH = nhapChuoi("Nhập mã khách hàng: ");
    
    // Kiểm tra mã khách hàng đã tồn tại chưa
    NodeKhachHang* current = head;
    while (current != NULL) {
        if (current->data.maKH == kh.maKH) {
            cout << "Mã khách hàng đã tồn tại. Vui lòng nhập mã khác.\n";
            return;
        }
        current = current->next;
    }
    
    kh.tenKH = nhapChuoi("Nhập tên khách hàng: ");
    kh.diaChi = nhapChuoi("Nhập địa chỉ: ");
    kh.soDT = nhapChuoi("Nhập số điện thoại: ");
    kh.ngaySinh = nhapChuoi("Nhập ngày sinh (DD/MM/YYYY): ");
    kh.matHangMua = nhapChuoi("Nhập mặt hàng mua: ");
    kh.soLuong = nhapSoNguyen("Nhập số lượng: ");
    kh.thanhTien = nhapSoThuc("Nhập thành tiền: ");
    kh.ngayGiaoDich = ngayHienTai();
    
    // Tạo node mới và thêm vào đầu danh sách
    NodeKhachHang* newNode = new NodeKhachHang;
    newNode->data = kh;
    newNode->next = head;
    head = newNode;
    
    cout << "Thêm khách hàng thành công!\n";
}

void hienThiDanhSachKhachHang(NodeKhachHang* head) {
    if (head == NULL) {
        cout << "\nDanh sách khách hàng trống.\n";
        return;
    }
    
    cout << "\n=== DANH SÁCH KHÁCH HÀNG ===\n";
    cout << left << setw(COL_MA_KH_WIDTH) << "Mã KH" 
         << setw(COL_TEN_KH_WIDTH) << "Tên KH" 
         << setw(COL_DIA_CHI_WIDTH) << "Địa chỉ" 
         << setw(COL_SO_DT_WIDTH) << "Số ĐT" 
         << setw(COL_NGAY_SINH_WIDTH) << "Ngày sinh" 
         << setw(COL_MAT_HANG_MUA_WIDTH) << "Mặt hàng mua" 
         << setw(COL_SO_LUONG_WIDTH) << "Số lượng" 
         << setw(COL_THANH_TIEN_WIDTH) << "Thành tiền" 
         << setw(COL_NGAY_GD_WIDTH) << "Ngày GD" << endl;
    cout << string(150, '-') << endl;
    
    NodeKhachHang* current = head;
    while (current != NULL) {
        cout << left << setw(COL_MA_KH_WIDTH) << current->data.maKH 
             << setw(COL_TEN_KH_WIDTH) << current->data.tenKH 
             << setw(COL_DIA_CHI_WIDTH) << current->data.diaChi 
             << setw(COL_SO_DT_WIDTH) << current->data.soDT 
             << setw(COL_NGAY_SINH_WIDTH) << current->data.ngaySinh 
             << setw(COL_MAT_HANG_MUA_WIDTH) << current->data.matHangMua 
             << setw(COL_SO_LUONG_WIDTH) << current->data.soLuong 
             << setw(COL_THANH_TIEN_WIDTH) << fixed << setprecision(2) << current->data.thanhTien 
             << setw(COL_NGAY_GD_WIDTH) << current->data.ngayGiaoDich << endl;
        current = current->next;
    }
}

void timKiemKhachHang(NodeKhachHang* head) {
    if (head == NULL) {
        cout << "\nDanh sách khách hàng trống.\n";
        return;
    }
    
    cout << "\n=== TÌM KIẾM KHÁCH HÀNG ===\n";
    cout << "1. Tìm theo mã khách hàng\n";
    cout << "2. Tìm theo tên khách hàng\n";
    cout << "3. Tìm theo số điện thoại\n";
    int choice = nhapSoNguyen("Chọn cách tìm kiếm: ");
    
    string searchValue;
    bool found = false;
    
    switch (choice) {
        case 1:
            searchValue = nhapChuoi("Nhập mã khách hàng cần tìm: ");
            break;
        case 2:
            searchValue = nhapChuoi("Nhập tên khách hàng cần tìm: ");
            break;
        case 3:
            searchValue = nhapChuoi("Nhập số điện thoại cần tìm: ");
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
            return;
    }
    
    cout << "\n=== KẾT QUẢ TÌM KIẾM ===\n";
    cout << left << setw(COL_MA_KH_WIDTH) << "Mã KH" 
         << setw(COL_TEN_KH_WIDTH) << "Tên KH" 
         << setw(COL_DIA_CHI_WIDTH) << "Địa chỉ" 
         << setw(COL_SO_DT_WIDTH) << "Số ĐT" 
         << setw(COL_NGAY_SINH_WIDTH) << "Ngày sinh" 
         << setw(COL_MAT_HANG_MUA_WIDTH) << "Mặt hàng mua" 
         << setw(COL_SO_LUONG_WIDTH) << "Số lượng" 
         << setw(COL_THANH_TIEN_WIDTH) << "Thành tiền" 
         << setw(COL_NGAY_GD_WIDTH) << "Ngày GD" << endl;
    cout << string(150, '-') << endl;
    
    NodeKhachHang* current = head;
    while (current != NULL) {
        if ((choice == 1 && current->data.maKH == searchValue) || 
            (choice == 2 && current->data.tenKH.find(searchValue) != string::npos) ||
            (choice == 3 && current->data.soDT == searchValue)) {
            cout << left << setw(COL_MA_KH_WIDTH) << current->data.maKH 
                 << setw(COL_TEN_KH_WIDTH) << current->data.tenKH 
                 << setw(COL_DIA_CHI_WIDTH) << current->data.diaChi 
                 << setw(COL_SO_DT_WIDTH) << current->data.soDT 
                 << setw(COL_NGAY_SINH_WIDTH) << current->data.ngaySinh 
                 << setw(COL_MAT_HANG_MUA_WIDTH) << current->data.matHangMua 
                 << setw(COL_SO_LUONG_WIDTH) << current->data.soLuong 
                 << setw(COL_THANH_TIEN_WIDTH) << fixed << setprecision(2) << current->data.thanhTien 
                 << setw(COL_NGAY_GD_WIDTH) << current->data.ngayGiaoDich << endl;
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "Không tìm thấy khách hàng phù hợp.\n";
    }
}

void suaKhachHang(NodeKhachHang* head) {
    if (head == NULL) {
        cout << "\nDanh sách khách hàng trống.\n";
        return;
    }
    
    string maKH = nhapChuoi("\nNhập mã khách hàng cần sửa: ");
    NodeKhachHang* current = head;
    bool found = false;
    
    while (current != NULL && !found) {
        if (current->data.maKH == maKH) {
            found = true;
            cout << "\n=== THÔNG TIN KHÁCH HÀNG HIỆN TẠI ===\n";
            cout << "Mã KH: " << current->data.maKH << endl;
            cout << "Tên KH: " << current->data.tenKH << endl;
            cout << "Địa chỉ: " << current->data.diaChi << endl;
            cout << "Số ĐT: " << current->data.soDT << endl;
            cout << "Ngày sinh: " << current->data.ngaySinh << endl;
            cout << "Mặt hàng mua: " << current->data.matHangMua << endl;
            cout << "Số lượng: " << current->data.soLuong << endl;
            cout << "Thành tiền: " << current->data.thanhTien << endl;
            cout << "Ngày giao dịch: " << current->data.ngayGiaoDich << endl;
            
            cout << "\n=== CẬP NHẬT THÔNG TIN ===\n";
            cout << "Nhấn Enter để giữ nguyên thông tin cũ\n";
            
            string input;
            
            input = nhapChuoi("Nhập tên khách hàng mới: ");
            if (!input.empty()) current->data.tenKH = input;
            
            input = nhapChuoi("Nhập địa chỉ mới: ");
            if (!input.empty()) current->data.diaChi = input;
            
            input = nhapChuoi("Nhập số điện thoại mới: ");
            if (!input.empty()) current->data.soDT = input;
            
            input = nhapChuoi("Nhập ngày sinh mới (DD/MM/YYYY): ");
            if (!input.empty()) current->data.ngaySinh = input;
            
            input = nhapChuoi("Nhập mặt hàng mua mới: ");
            if (!input.empty()) current->data.matHangMua = input;
            
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
            
            cout << "Nhập thành tiền mới (hiện tại: " << current->data.thanhTien << "): ";
            string thanhTienStr;
            getline(cin, thanhTienStr);
            if (!thanhTienStr.empty()) {
                try {
                    current->data.thanhTien = stod(thanhTienStr);
                } catch (...) {
                    cout << "Giá trị không hợp lệ, giữ nguyên thành tiền cũ.\n";
                }
            }
            
            input = nhapChuoi("Nhập ngày giao dịch mới (DD/MM/YYYY): ");
            if (!input.empty()) current->data.ngayGiaoDich = input;
            
            cout << "Cập nhật thông tin khách hàng thành công!\n";
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "Không tìm thấy khách hàng có mã " << maKH << endl;
    }
}

void xoaKhachHang(NodeKhachHang*& head) {
    if (head == NULL) {
        cout << "\nDanh sách khách hàng trống.\n";
        return;
    }
    
    string maKH = nhapChuoi("\nNhập mã khách hàng cần xóa: ");
    
    // Xử lý trường hợp xóa node đầu tiên
    if (head != NULL && head->data.maKH == maKH) {
        NodeKhachHang* temp = head;
        head = head->next;
        delete temp;
        cout << "Xóa khách hàng thành công!\n";
        return;
    }
    
    // Xử lý các trường hợp khác
    NodeKhachHang* current = head;
    NodeKhachHang* prev = NULL;
    bool found = false;
    
    while (current != NULL && !found) {
        if (current->data.maKH == maKH) {
            found = true;
            prev->next = current->next;
            delete current;
            cout << "Xóa khách hàng thành công!\n";
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    if (!found) {
        cout << "Không tìm thấy khách hàng có mã " << maKH << endl;
    }
}

void sapXepKhachHang(NodeKhachHang*& head) {
    if (head == NULL || head->next == NULL) {
        cout << "\nDanh sách khách hàng trống hoặc chỉ có một phần tử.\n";
        return;
    }
    
    cout << "\n=== SẮP XẾP KHÁCH HÀNG ===\n";
    cout << "1. Sắp xếp theo mã khách hàng\n";
    cout << "2. Sắp xếp theo tên khách hàng\n";
    cout << "3. Sắp xếp theo ngày giao dịch\n";
    cout << "4. Sắp xếp theo thành tiền\n";
    int choice = nhapSoNguyen("Chọn cách sắp xếp: ");
    
    cout << "1. Sắp xếp tăng dần\n";
    cout << "2. Sắp xếp giảm dần\n";
    int order = nhapSoNguyen("Chọn thứ tự sắp xếp: ");
    
    bool ascending = (order == 1);
    
    // Bubble sort
    bool swapped;
    NodeKhachHang* ptr1;
    NodeKhachHang* lptr = NULL;
    
    if (head == NULL)
        return;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            bool shouldSwap = false;
            
            switch (choice) {
                case 1: // Mã khách hàng
                    shouldSwap = ascending ? 
                                (ptr1->data.maKH > ptr1->next->data.maKH) : 
                                (ptr1->data.maKH < ptr1->next->data.maKH);
                    break;
                case 2: // Tên khách hàng
                    shouldSwap = ascending ? 
                                (ptr1->data.tenKH > ptr1->next->data.tenKH) : 
                                (ptr1->data.tenKH < ptr1->next->data.tenKH);
                    break;
                case 3: // Ngày giao dịch
                    shouldSwap = ascending ? 
                                (ptr1->data.ngayGiaoDich > ptr1->next->data.ngayGiaoDich) : 
                                (ptr1->data.ngayGiaoDich < ptr1->next->data.ngayGiaoDich);
                    break;
                case 4: // Thành tiền
                    shouldSwap = ascending ? 
                                (ptr1->data.thanhTien > ptr1->next->data.thanhTien) : 
                                (ptr1->data.thanhTien < ptr1->next->data.thanhTien);
                    break;
                default:
                    cout << "Lựa chọn không hợp lệ.\n";
                    return;
            }
            
            if (shouldSwap) {
                KhachHang temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    
    cout << "Sắp xếp thành công!\n";
    hienThiDanhSachKhachHang(head);
}