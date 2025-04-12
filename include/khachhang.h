#ifndef KHACH_HANG_H
#define KHACH_HANG_H

#include <string>
#include <iostream>
#include <iomanip>

class KhachHang {
private:
    std::string maKH;          // Mã khách hàng
    std::string tenKH;         // Tên khách hàng
    std::string diaChi;        // Địa chỉ
    std::string soDienThoai;   // Số điện thoại
    std::string ngaySinh;      // Ngày sinh
    std::string matHangMua;    // Mặt hàng mua
    int soLuong;               // Số lượng
    double thanhTien;          // Thành tiền
    std::string ngayGiaoDich;  // Ngày giao dịch

public:
    // Constructor mặc định
    KhachHang();
    
    // Constructor với tham số
    KhachHang(const std::string& maKH, const std::string& tenKH, 
              const std::string& diaChi, const std::string& soDienThoai,
              const std::string& ngaySinh, const std::string& matHangMua,
              int soLuong, double thanhTien, const std::string& ngayGiaoDich);
    
    // Getter methods
    std::string getMaKH() const;
    std::string getTenKH() const;
    std::string getDiaChi() const;
    std::string getSoDienThoai() const;
    std::string getNgaySinh() const;
    std::string getMatHangMua() const;
    int getSoLuong() const;
    double getThanhTien() const;
    std::string getNgayGiaoDich() const;
    
    // Setter methods
    void setMaKH(const std::string& maKH);
    void setTenKH(const std::string& tenKH);
    void setDiaChi(const std::string& diaChi);
    void setSoDienThoai(const std::string& soDienThoai);
    void setNgaySinh(const std::string& ngaySinh);
    void setMatHangMua(const std::string& matHangMua);
    void setSoLuong(int soLuong);
    void setThanhTien(double thanhTien);
    void setNgayGiaoDich(const std::string& ngayGiaoDich);
    
    // Hiển thị thông tin khách hàng
    void hienThi() const;
    
    // Nhập thông tin khách hàng từ người dùng
    void nhap();
    
    // Chuyển thông tin khách hàng thành chuỗi để lưu vào file
    std::string toString() const;
    
    // Khôi phục thông tin khách hàng từ chuỗi đọc từ file
    void fromString(const std::string& str);
};

// Cấu trúc node cho danh sách liên kết đơn của khách hàng
struct NodeKhachHang {
    KhachHang data;         // Dữ liệu của node
    NodeKhachHang* next;    // Con trỏ đến node tiếp theo
    
    // Constructor
    NodeKhachHang(const KhachHang& kh) : data(kh), next(nullptr) {}
};

#endif // KHACH_HANG_H