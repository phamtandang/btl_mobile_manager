CC = g++
CFLAGS = -Wall -std=c++11
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Danh sách các file .cpp
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Tạo danh sách các file .o tương ứng
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
# Tên file thực thi
EXECUTABLE = $(BINDIR)/QuanLyCuaHang

# Tạo thư mục nếu chưa tồn tại
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Rule mặc định
all: $(EXECUTABLE)

# Link các file .o để tạo file thực thi
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Biên dịch các file .cpp thành .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Clean: xóa tất cả các file được tạo ra
clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)

# Rebuild: clean và build lại
rebuild: clean all

# Phụ thuộc cho các file header
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/models.h $(INCDIR)/sanpham.h $(INCDIR)/khachhang.h $(INCDIR)/thongke.h $(INCDIR)/utils.h
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJDIR)/sanpham.o: $(SRCDIR)/sanpham.cpp $(INCDIR)/sanpham.h $(INCDIR)/models.h $(INCDIR)/utils.h $(INCDIR)/constants.h
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJDIR)/khachhang.o: $(SRCDIR)/khachhang.cpp $(INCDIR)/khachhang.h $(INCDIR)/models.h $(INCDIR)/utils.h $(INCDIR)/constants.h
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJDIR)/thongke.o: $(SRCDIR)/thongke.cpp $(INCDIR)/thongke.h $(INCDIR)/models.h
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJDIR)/utils.o: $(SRCDIR)/utils.cpp $(INCDIR)/utils.h
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

.PHONY: all clean rebuild