# Quản Lý Cửa Hàng

Đây là dự án quản lý cửa hàng được xây dựng bằng C++ sử dụng danh sách liên kết đơn để quản lý các đối tượng sản phẩm và khách hàng.

## Cấu trúc dự án

```
QuanLyCuaHang/
│
├── include/                   # Thư mục chứa các file header
│   ├── constants.h            # Các hằng số và định nghĩa chung
│   ├── models.h               # Định nghĩa cấu trúc dữ liệu
│   ├── sanpham.h              # Khai báo hàm liên quan đến sản phẩm
│   ├── khachhang.h            # Khai báo hàm liên quan đến khách hàng
│   ├── thongke.h              # Khai báo hàm thống kê
│   └── utils.h                # Các tiện ích (nhập/xuất, xử lý ngày tháng)
│
├── src/                       # Thư mục chứa các file nguồn
│   ├── sanpham.cpp            # Triển khai quản lý sản phẩm
│   ├── khachhang.cpp          # Triển khai quản lý khách hàng
│   ├── thongke.cpp            # Triển khai thống kê
│   ├── utils.cpp              # Triển khai các tiện ích
│   └── main.cpp               # Chương trình chính
│
├── Makefile                   # File để biên dịch project
│
└── README.md                  # Tài liệu hướng dẫn
```

## Chức năng

### Quản lý Sản phẩm
1. Hiển thị danh sách sản phẩm
2. Thêm sản phẩm
3. Sửa thông tin sản phẩm
4. Xóa sản phẩm
5. Tìm kiếm sản phẩm
6. Sắp xếp sản phẩm
7. Thống kê sản phẩm

### Quản lý Khách hàng
1. Hiển thị danh sách khách hàng
2. Thêm khách hàng
3. Sửa thông tin khách hàng
4. Xóa khách hàng
5. Tìm kiếm khách hàng
6. Sắp xếp khách hàng

### Thống kê
1. Số vốn nhập
2. Số tiền bán ra
3. Tình trạng cửa hàng (lãi/lỗ)

## Cấu trúc dữ liệu

Dự án sử dụng danh sách liên kết đơn để quản lý cả sản phẩm và khách hàng.

### Sản phẩm
- Mã sản phẩm
- Tên sản phẩm
- Mã nhà cung cấp
- Tên nhà cung cấp
- Ngày nhập
- Số lượng
- Đơn giá
- Thành tiền

### Khách hàng
- Mã khách hàng
- Tên khách hàng
- Địa chỉ
- Số điện thoại
- Ngày sinh
- Mặt hàng mua
- Số lượng
- Thành tiền
- Ngày giao dịch

## Cách biên dịch và chạy

1. Tạo thư mục `obj` và `bin` trong thư mục gốc của dự án:
   ```
   mkdir -p obj bin
   ```

2. Biên dịch dự án bằng lệnh:
   ```
   make
   ```

3. Chạy chương trình:
   ```
   ./bin/QuanLyCuaHang
   ```

4. Để clean và build lại:
   ```
   make rebuild
   ```

## Thuật toán được sử dụng
- Thuật toán duyệt danh sách (Traversal)
- Thuật toán tìm kiếm tuyến tính (Linear Search)
- Thuật toán sắp xếp (Bubble Sort)
- Thuật toán tính tổng và thống kê