#ifndef MODELS_H
#define MODELS_H

#include <string>

// Cấu trúc dữ liệu cho Sản phẩm
struct SanPham {
    std::string maSP;
    std::string tenSP;
    std::string maNCC;
    std::string tenNCC;
    std::string ngayNhap;
    int soLuong;
    double donGia;
    double thanhTien;
};

// Cấu trúc node cho danh sách liên kết sản phẩm
struct NodeSanPham {
    SanPham data;
    NodeSanPham* next;
};

// Cấu trúc dữ liệu cho Khách hàng
struct KhachHang {
    std::string maKH;
    std::string tenKH;
    std::string diaChi;
    std::string soDT;
    std::string ngaySinh;
    std::string matHangMua;
    int soLuong;
    double thanhTien;
    std::string ngayGiaoDich;
};

// Cấu trúc node cho danh sách liên kết khách hàng
struct NodeKhachHang {
    KhachHang data;
    NodeKhachHang* next;
};

#endif // MODELS_H