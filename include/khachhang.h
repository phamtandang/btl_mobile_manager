#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "models.h"

// Khai báo các biến toàn cục ở đây
extern NodeKhachHang* dsKhachHang;

// Các hàm xử lý khách hàng
void themKhachHang(NodeKhachHang*& head);
void hienThiDanhSachKhachHang(NodeKhachHang* head);
void timKiemKhachHang(NodeKhachHang* head);
void suaKhachHang(NodeKhachHang* head);
void xoaKhachHang(NodeKhachHang*& head);
void sapXepKhachHang(NodeKhachHang*& head);

#endif // KHACHHANG_H