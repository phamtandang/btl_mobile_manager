#include "Menu.h"
#include <iostream>
#include <locale>
#include <cstdlib>

int main() {
    // Thiết lập locale để hỗ trợ tiếng Việt
    try {
        std::locale::global(std::locale(""));
    } catch (const std::exception& e) {
        std::cerr << "Warning: Không thể thiết lập locale, một số ký tự có thể không hiển thị đúng.\n";
    }
    
    // Thiết lập mã hóa console (Windows)
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif
    
    std::cout << "=================================================\n";
    std::cout << "CHƯƠNG TRÌNH QUẢN LÝ CỬA HÀNG\n";
    std::cout << "Sử dụng Danh sách liên kết đơn\n";
    std::cout << "=================================================\n";
    
    // Khởi tạo và chạy menu
    Menu menu;
    menu.run();
    
    return 0;
}