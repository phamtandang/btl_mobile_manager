#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <limits>

namespace Utils {
    // Hàm chuyển đổi chuỗi thành số nguyên
    int stringToInt(const std::string& str);
    
    // Hàm chuyển đổi chuỗi thành số thực
    double stringToDouble(const std::string& str);
    
    // Hàm chuyển đổi số nguyên thành chuỗi
    std::string intToString(int value);
    
    // Hàm chuyển đổi số thực thành chuỗi
    std::string doubleToString(double value, int precision = 2);
    
    // Hàm lấy ngày hiện tại theo định dạng "dd/mm/yyyy"
    std::string getNgayHienTai();
    
    // Hàm kiểm tra chuỗi có phải là số hay không
    bool isNumber(const std::string& str);
    
    // Hàm kiểm tra định dạng ngày (dd/mm/yyyy)
    bool isValidDate(const std::string& date);
    
    // Hàm tách chuỗi thành vector các chuỗi con dựa vào ký tự phân cách
    std::vector<std::string> split(const std::string& str, char delimiter);
    
    // Hàm nhập chuỗi với thông báo
    std::string inputString(const std::string& message);
    
    // Hàm nhập số nguyên với kiểm tra hợp lệ
    int inputInt(const std::string& message, int minValue = INT_MIN, int maxValue = INT_MAX);
    
    // Hàm nhập số thực với kiểm tra hợp lệ
    double inputDouble(const std::string& message, double minValue = -std::numeric_limits<double>::max(), double maxValue = std::numeric_limits<double>::max());
    
    // Hàm nhập ngày với kiểm tra hợp lệ
    std::string inputDate(const std::string& message);
    
    // Hàm tính khoảng cách giữa hai ngày (số ngày)
    int daysBetween(const std::string& date1, const std::string& date2);
    
    // Hàm trích xuất tháng từ chuỗi ngày (dd/mm/yyyy)
    int extractMonth(const std::string& date);
    
    // Hàm trích xuất quý từ chuỗi ngày (dd/mm/yyyy)
    int extractQuarter(const std::string& date);
    
    // Hàm format tiền tệ
    std::string formatCurrency(double value);
    
    // Hàm vẽ đường kẻ ngang
    void drawLine(int length = 80, char c = '-');
    
    // Hàm xóa màn hình
    void clearScreen();
    
    // Hàm tạm dừng chương trình và chờ người dùng nhấn phím bất kỳ
    void pause();
}

#endif // UTILS_H