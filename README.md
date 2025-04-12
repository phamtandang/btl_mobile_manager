# Hệ Thống Quản Lý Cửa Hàng

Đây là ứng dụng quản lý cửa hàng được phát triển bằng C++, sử dụng cấu trúc dữ liệu danh sách liên kết để lưu trữ và quản lý thông tin về sản phẩm và khách hàng.

## Tính Năng

* **Quản lý sản phẩm**: Thêm, sửa, xóa, tìm kiếm sản phẩm
* **Quản lý khách hàng**: Thêm, sửa, xóa, tìm kiếm thông tin khách hàng
* **Thống kê**: Theo dõi tình trạng cửa hàng, doanh thu, lãi/lỗ
* **Tìm kiếm nâng cao**: Theo mã, tên, và nhiều tiêu chí khác
* **Sắp xếp dữ liệu**: Theo nhiều tiêu chí khác nhau
* **Lưu trữ dữ liệu**: Tự động lưu và đọc dữ liệu từ file

## Cấu Trúc Dự Án

```
store_management/
│
├── include/
│   ├── KhachHang.h       // Định nghĩa lớp KhachHang và NodeKhachHang
│   ├── SanPham.h         // Định nghĩa lớp SanPham và NodeSanPham
│   ├── QuanLyKhachHang.h // Lớp quản lý danh sách liên kết khách hàng
│   ├── QuanLySanPham.h   // Lớp quản lý danh sách liên kết sản phẩm
│   ├── ThongKe.h         // Lớp thống kê
│   ├── Utils.h           // Các hàm tiện ích
│   └── Menu.h            // Lớp xử lý menu và giao diện
│
├── src/
│   ├── KhachHang.cpp       // Triển khai phương thức của lớp KhachHang
│   ├── SanPham.cpp         // Triển khai phương thức của lớp SanPham
│   ├── QuanLyKhachHang.cpp // Triển khai phương thức quản lý khách hàng
│   ├── QuanLySanPham.cpp   // Triển khai phương thức quản lý sản phẩm
│   ├── ThongKe.cpp         // Triển khai phương thức thống kê
│   ├── Utils.cpp           // Triển khai các hàm tiện ích
│   ├── Menu.cpp            // Triển khai phương thức menu
│   └── main.cpp            // Chương trình chính
│
└── data/
    ├── khachhang.txt       // File lưu trữ dữ liệu khách hàng
    └── sanpham.txt         // File lưu trữ dữ liệu sản phẩm
```

## Yêu Cầu Hệ Thống

* Trình biên dịch C++ hỗ trợ chuẩn C++17 trở lên (g++, clang++)
* Hệ điều hành: Windows, macOS, hoặc Linux

## Hướng Dẫn Cài Đặt

### Sử dụng Make

1. Clone repository về máy của bạn
2. Di chuyển đến thư mục dự án
3. Chạy lệnh biên dịch:
   ```
   make
   ```
4. Chạy chương trình:
   ```
   make run
   ```

### Biên dịch thủ công

```bash
# Tạo thư mục
mkdir -p obj bin data

# Biên dịch
g++ -std=c++17 -I include -c src/*.cpp -o obj/
g++ obj/*.o -o bin/store_management

# Chạy chương trình
./bin/store_management
```

## Hướng Dẫn Sử Dụng

Khi chạy chương trình, bạn sẽ thấy menu chính với các tùy chọn sau:

```
=============== QUẢN LÝ CỬA HÀNG ===============
1. Quản lý sản phẩm
2. Quản lý khách hàng
3. Thống kê
0. Thoát
------------------------------------------------------
Nhập lựa chọn:
```

### Quản Lý Sản Phẩm

Cho phép thêm, sửa, xóa, tìm kiếm và hiển thị thông tin sản phẩm.

### Quản Lý Khách Hàng

Cho phép thêm, sửa, xóa, tìm kiếm và hiển thị thông tin khách hàng.

### Thống Kê

Cung cấp các báo cáo thống kê như tình trạng cửa hàng, sản phẩm bán chạy, doanh thu theo thời gian.

## Quản Lý Dữ Liệu

Dữ liệu được lưu trữ trong các file txt trong thư mục `data/`:
- `sanpham.txt`: Thông tin về sản phẩm
- `khachhang.txt`: Thông tin về khách hàng

Dữ liệu được tự động lưu khi thoát chương trình và đọc khi khởi động.

## Xử Lý Lỗi

Ứng dụng bao gồm xử lý lỗi cơ bản như:
- Kiểm tra dữ liệu đầu vào
- Xử lý các trường hợp không tìm thấy dữ liệu
- Báo lỗi khi thao tác với file không thành công

## Những Người Đóng Góp

- [Tên của bạn] - Phát triển chính
- [Tên thành viên khác] - Thiết kế và kiểm thử

## Giấy Phép

Dự án được phân phối dưới giấy phép [loại giấy phép]. Xem file `LICENSE` để biết thêm chi tiết.