#ifndef SAN_PHAM_H
#define SAN_PHAM_H

#include <string>
#include <iostream>
#include <iomanip>

class SanPham {
private:
    std::string maSP;            // Mã sản phẩm
    std::string tenSP;           // Tên sản phẩm
    std::string maNhaCungCap;    // Mã nhà cung cấp
    std::string tenNhaCungCap;   // Tên nhà cung cấp
    std::string ngayNhap;        // Ngày nhập
    int soLuong;                 // Số lượng
    double donGia;               // Đơn giá
    double thanhTien;            // Thành tiền

public:
    // Constructor mặc định
    SanPham();
    
    // Constructor với tham số
    SanPham(const std::string& maSP, const std::string& tenSP,
            const std::string& maNhaCungCap, const std::string& tenNhaCungCap,
            const std::string& ngayNhap, int soLuong, double donGia, double thanhTien);
    
    // Getter methods
    std::string getMaSP() const;
    std::string getTenSP() const;
    std::string getMaNhaCungCap() const;
    std::string getTenNhaCungCap() const;
    std::string getNgayNhap() const;
    int getSoLuong() const;
    double getDonGia() const;
    double getThanhTien() const;
    
    // Setter methods
    void setMaSP(const std::string& maSP);
    void setTenSP(const std::string& tenSP);
    void setMaNhaCungCap(const std::string& maNhaCungCap);
    void setTenNhaCungCap(const std::string& tenNhaCungCap);
    void setNgayNhap(const std::string& ngayNhap);
    void setSoLuong(int soLuong);
    void setDonGia(double donGia);
    void setThanhTien(double thanhTien);
    
    // Hiển thị thông tin sản phẩm
    void hienThi() const;
    
    // Nhập thông tin sản phẩm từ người dùng
    void nhap();
    
    // Tính thành tiền: thành tiền = số lượng * đơn giá
    void tinhThanhTien();
    
    // Chuyển thông tin sản phẩm thành chuỗi để lưu vào file
    std::string toString() const;
    
    // Khôi phục thông tin sản phẩm từ chuỗi đọc từ file
    void fromString(const std::string& str);
};

// Cấu trúc node cho danh sách liên kết đơn của sản phẩm
struct NodeSanPham {
    SanPham data;        // Dữ liệu của node
    NodeSanPham* next;   // Con trỏ đến node tiếp theo
    
    // Constructor
    NodeSanPham(const SanPham& sp) : data(sp), next(nullptr) {}
};

#endif // SAN_PHAM_H