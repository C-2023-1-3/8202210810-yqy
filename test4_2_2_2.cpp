#include <iostream>
using namespace std;

int parseHex(const char* const hexString) {
    int result = 0;
    int i = (hexString[0] == '0' && hexString[1] == 'x') ? 2 : 0;
    
    while (hexString[i] != '\0') {
        int digit;
        
        if (hexString[i] >= '0' && hexString[i] <= '9') {
            digit = hexString[i] - '0';
        } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            digit = hexString[i] - 'A' + 10;
        } else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
            digit = hexString[i] - 'a' + 10;
        } else {
            break;
        }
        
        result = result * 16 + digit;
        i++;
    }
    
    return result;
}
int main() {
    const int SIZE = 100;
    char hexString[SIZE];
    cout<<"16进制数: ";
    cin.getline(hexString, SIZE);
    int result = parseHex(hexString);
    cout << "16进制数 " << hexString << " 表示为10进制为: " << result << endl;
    return 0;
}