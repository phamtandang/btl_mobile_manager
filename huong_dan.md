# Hướng dẫn sử dụng phần mềm Quản Lý Cửa Hàng

## 1. Cài đặt

### Yêu cầu hệ thống
- Hệ điều hành: Windows, Linux hoặc macOS
- Trình biên dịch C++ (g++ hoặc tương đương) có hỗ trợ C++11
- Make (để biên dịch sử dụng Makefile)

### Biên dịch và chạy
1. Tải về hoặc clone repository về máy tính của bạn
2. Mở terminal/command prompt và di chuyển đến thư mục dự án
3. Chạy lệnh `make` để biên dịch dự án
4. Sau khi biên dịch xong, chạy chương trình bằng lệnh `./bin/QuanLyCuaHang`

## 2. Giao diện và chức năng chính

Khi khởi động, phần mềm sẽ hiển thị menu chính với 3 lựa chọn:
```
===== QUẢN LÝ CỬA HÀNG =====
1. Quản lý Sản phẩm
2. Quản lý Khách hàng
3. Thống kê
0. Thoát
===========================
Lựa chọn của bạn:
```

### 2.1. Quản lý Sản phẩm
Khi chọn mục "Quản lý Sản phẩm", menu sau sẽ hiện lên:
```
===== QUẢN LÝ SẢN PHẨM =====
1. Hiển thị danh sách sản phẩm
2. Thêm sản phẩm
3. Sửa thông tin sản phẩm
4. Xóa sản phẩm
5. Tìm kiếm sản phẩm
6. Sắp xếp sản phẩm
7. Thống kê sản phẩm
0. Quay lại menu chính
===========================
Lựa chọn của bạn:
```

#### 2.1.1. Hiển thị danh sách sản phẩm
- Hiển thị tất cả sản phẩm trong cơ sở dữ liệu dưới dạng bảng.

#### 2.1.2. Thêm sản phẩm
- Nhập thông tin cho sản phẩm mới: mã sản phẩm, tên sản phẩm, thông tin nhà cung cấp, ngày nhập, số lượng, đơn giá.
- Hệ thống kiểm tra mã sản phẩm không trùng lặp.

#### 2.1.3. Sửa thông tin sản phẩm
- Nhập mã sản phẩm cần sửa.
- Chọn thông tin cần sửa và nhập giá trị mới.
- Nếu không muốn thay đổi thông tin nào, chỉ cần nhấn Enter.

#### 2.1.4. Xóa sản phẩm
- Nhập mã sản phẩm cần xóa.
- Xác nhận việc xóa.

#### 2.1.5. Tìm kiếm sản phẩm
- Có thể tìm kiếm theo mã sản phẩm hoặc tên sản phẩm.

#### 2.1.6. Sắp xếp sản phẩm
- Có thể sắp xếp theo nhiều tiêu chí: mã, tên, số lượng, đơn giá, thành tiền.
- Có thể chọn sắp xếp tăng dần hoặc giảm dần.

#### 2.1.7. Thống kê sản phẩm
- Hiển thị tổng số sản phẩm, tổng số lượng và tổng giá trị.

### 2.2. Quản lý Khách hàng
Khi chọn mục "Quản lý Khách hàng", menu sau sẽ hiện lên:
```
===== QUẢN LÝ KHÁCH HÀNG =====
1. Hiển thị danh sách khách hàng
2. Thêm khách hàng
3. Sửa thông tin khách hàng
4. Xóa khách hàng
5. Tìm kiếm khách hàng
6. Sắp xếp khách hàng
0. Quay lại menu chính
===========================
Lựa chọn của bạn:
```

#### 2.2.1. Hiển thị danh sách khách hàng
- Hiển thị tất cả khách hàng trong cơ sở dữ liệu dưới dạng bảng.

#### 2.2.2. Thêm khách hàng
- Nhập thông tin cho khách hàng mới: mã khách hàng, tên, địa chỉ, số điện thoại, ngày sinh, thông tin mua hàng.
- Hệ thống kiểm tra mã khách hàng không trùng lặp.

#### 2.2.3. Sửa thông tin khách hàng
- Nhập mã khách hàng cần sửa.
- Chọn thông tin cần sửa và nhập giá trị mới.
- Nếu không muốn thay đổi thông tin nào, chỉ cần nhấn Enter.

#### 2.2.4. Xóa khách hàng
- Nhập mã khách hàng cần xóa.
- Xác nhận việc xóa.

#### 2.2.5. Tìm kiếm khách hàng
- Có thể tìm kiếm theo mã khách hàng, tên khách hàng hoặc số điện thoại.

#### 2.2.6. Sắp xếp khách hàng
- Có thể sắp xếp theo nhiều tiêu chí: mã, tên, ngày giao dịch, thành tiền.
- Có thể chọn sắp xếp tăng dần hoặc giảm dần.

### 2.3. Thống kê
Khi chọn mục "Thống kê", menu sau sẽ hiện lên:
```
===== THỐNG KÊ =====
1. Số vốn nhập
2. Số tiền bán ra
3. Tình trạng cửa hàng
0. Quay lại menu chính
===========================
Lựa chọn của bạn:
```

#### 2.3.1. Số vốn nhập
- Hiển thị tổng số vốn đã nhập vào (tổng giá trị sản phẩm).

#### 2.3.2. Số tiền bán ra
- Hiển thị tổng số tiền bán ra (tổng thành tiền của các giao dịch khách hàng).

#### 2.3.3. Tình trạng cửa hàng
- So sánh vốn nhập và tiền bán ra để tính lãi/lỗ.
- Hiển thị tình trạng cửa hàng (ĐANG LÃI, ĐANG LỖ hoặc HÒA VỐN).

## 3. Lưu ý khi sử dụng
- Dữ liệu chỉ được lưu trong bộ nhớ, không được lưu vào tệp tin nên sẽ mất khi thoát chương trình.
- Khi nhập giá trị số, phải nhập đúng định dạng, nếu không sẽ được yêu cầu nhập lại.
- Sau mỗi thao tác, nhấn Enter để tiếp tục.