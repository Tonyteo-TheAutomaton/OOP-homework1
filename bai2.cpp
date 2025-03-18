#include <iostream>
#include <algorithm> 

using namespace std;

// Hàm tính ước số chung lớn nhất (USCLN)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Hàm rút gọn phân số
void simplifyFraction(int &num, int &den) {
    int divisor = gcd(abs(num), abs(den)); // Tính USCLN của tử và mẫu
    num /= divisor;
    den /= divisor;
    
    // Đảm bảo mẫu số luôn dương
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

int main() {
    int numerator, denominator;
    
    // Nhập phân số
    cout << "Nhập tử số: ";
    cin >> numerator;
    cout << "Nhập mẫu số: ";
    cin >> denominator;
    
    // Kiểm tra mẫu số có hợp lệ không
    if (denominator == 0) {
        cout << "Lỗi: Mẫu số không thể bằng 0." << endl;
        return 1;
    }
    
    // Rút gọn phân số
    simplifyFraction(numerator, denominator);
    
    // Xuất kết quả
    cout << "Phân số sau khi rút gọn: " << numerator << "/" << denominator << endl;
    
    return 0;
}	
