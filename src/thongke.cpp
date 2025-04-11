#include "../include/thongke.h"
#include <iostream>
#include <iomanip>

using namespace std;

void thongKeVonNhap(NodeSanPham* head) {
    if (head == NULL) {
        cout << "\nDanh sách sản phẩm trống, không thể thống kê.\n";
        return;
    }
    
    double tongVonNhap = 0;
    int tongSoSanPham = 0;
    
    NodeSanPham* current = head;
    while (current != NULL) {
        tongVonNhap += current->data.thanhTien;
        tongSoSanPham += current->data.soLuong;
        current = current->next;
    }
    
    cout << "\n=== THỐNG KÊ VỐN NHẬP ===\n";
    cout << "Tổng số lượng sản phẩm: " << tongSoSanPham << endl;
    cout << "Tổng vốn nhập: " << fixed << setprecision(2) << tongVonNhap << endl;
}

void thongKeTienBanRa(NodeKhachHang* head) {
    if (head == NULL) {
        cout << "\nDanh sách khách hàng trống, không thể thống kê.\n";
        return;
    }
    
    double tongTienBanRa = 0;
    int tongSoLuongBan = 0;
    
    NodeKhachHang* current = head;
    while (current != NULL) {
        tongTienBanRa += current->data.thanhTien;
        tongSoLuongBan += current->data.soLuong;
        current = current->next;
    }
    
    cout << "\n=== THỐNG KÊ TIỀN BÁN RA ===\n";
    cout << "Tổng số lượng bán: " << tongSoLuongBan << endl;
    cout << "Tổng tiền bán ra: " << fixed << setprecision(2) << tongTienBanRa << endl;
}

void thongKeTinhTrangCuaHang(NodeSanPham* headSP, NodeKhachHang* headKH) {
    double tongVonNhap = 0;
    double tongTienBanRa = 0;
    
    // Tính tổng vốn nhập
    NodeSanPham* currentSP = headSP;
    while (currentSP != NULL) {
        tongVonNhap += currentSP->data.thanhTien;
        currentSP = currentSP->next;
    }
    
    // Tính tổng tiền bán ra
    NodeKhachHang* currentKH = headKH;
    while (currentKH != NULL) {
        tongTienBanRa += currentKH->data.thanhTien;
        currentKH = currentKH->next;
    }
    
    // Tính lãi/lỗ
    double loiNhuan = tongTienBanRa - tongVonNhap;
    
    cout << "\n=== TÌNH TRẠNG CỬA HÀNG ===\n";
    cout << "Tổng vốn nhập: " << fixed << setprecision(2) << tongVonNhap << endl;
    cout << "Tổng tiền bán ra: " << fixed << setprecision(2) << tongTienBanRa << endl;
    
    if (loiNhuan > 0) {
        cout << "Tình trạng: ĐANG LÃI" << endl;
        cout << "Số tiền lãi: " << fixed << setprecision(2) << loiNhuan << endl;
    } else if (loiNhuan < 0) {
        cout << "Tình trạng: ĐANG LỖ" << endl;
        cout << "Số tiền lỗ: " << fixed << setprecision(2) << -loiNhuan << endl;
    } else {
        cout << "Tình trạng: HÒA VỐN" << endl;
    }
}