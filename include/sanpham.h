#ifndef SANPHAM_H
#define SANPHAM_H

#include "models.h"

// Khai báo các biến toàn cục ở đây 
extern NodeSanPham* dsSanPham;

// Các hàm xử lý sản phẩm
void themSanPham(NodeSanPham*& head);
void hienThiDanhSachSanPham(NodeSanPham* head);
void timKiemSanPham(NodeSanPham* head);
void suaSanPham(NodeSanPham* head);
void xoaSanPham(NodeSanPham*& head);
void sapXepSanPham(NodeSanPham*& head);
void thongKeSanPham(NodeSanPham* head);

#endif // SANPHAM_H