# Xác định môi trường và điều chỉnh cờ biên dịch phù hợp
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    # macOS sử dụng clang và không cần -lstdc++fs
    CXX = clang++
    CXXFLAGS = -Wall -Wextra -std=c++17 -I include
    LDFLAGS = -stdlib=libc++
else
    # Linux/Windows sử dụng g++ và cần -lstdc++fs
    CXX = g++
    CXXFLAGS = -Wall -Wextra -std=c++17 -I include
    LDFLAGS = -lstdc++fs
endif

# Thư mục
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DATA_DIR = data

# File
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
EXE = $(BIN_DIR)/store_management

# Mục tiêu chính
all: directories $(EXE)

# Tạo thư mục nếu chưa có
directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(DATA_DIR)

# Tạo thực thi
$(EXE): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Tạo các file object
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Các phụ thuộc
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/KhachHang.o: $(SRC_DIR)/KhachHang.cpp include/KhachHang.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/SanPham.o: $(SRC_DIR)/SanPham.cpp include/SanPham.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/QuanLyKhachHang.o: $(SRC_DIR)/QuanLyKhachHang.cpp include/QuanLyKhachHang.h include/KhachHang.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/QuanLySanPham.o: $(SRC_DIR)/QuanLySanPham.cpp include/QuanLySanPham.h include/SanPham.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/ThongKe.o: $(SRC_DIR)/ThongKe.cpp include/ThongKe.h include/QuanLyKhachHang.h include/QuanLySanPham.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Utils.o: $(SRC_DIR)/Utils.cpp include/Utils.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Menu.o: $(SRC_DIR)/Menu.cpp include/Menu.h include/QuanLyKhachHang.h include/QuanLySanPham.h include/ThongKe.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Chạy chương trình
run: all
	$(EXE)

.PHONY: all clean run directories