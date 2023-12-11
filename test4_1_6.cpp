#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void count(const char s[], int counts[]) {
    int len = strlen(s); // 获取字符串长度
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) { // 检查字符是否为字母
            char c = tolower(s[i]); // 将字符转换为小写
            counts[c - 'a']++; // 增加对应字母的计数
        }
    }
}
int main() {
    const int SIZE = 26;
    int counts[SIZE] = {0}; // 初始化计数数组
    char s[100]; // 假设字符串最大长度为100
    cout << "Enter a string: ";
    cin.getline(s, 100); // 读取输入的字符串
    
    count(s, counts); // 调用计数函数
    for (int i = 0; i < SIZE; i++) {
        if (counts[i] > 0) { // 仅显示非零次数的字母
            char c = 'a' + i;
            cout << c << ": "<< counts[i] << " times" << endl;
        }
    }
    return 0;
}