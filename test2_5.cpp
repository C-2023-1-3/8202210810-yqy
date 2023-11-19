#include <iostream>
using namespace std;
int main_5() {
    char c;
    int letter_count = 0;
    int space_count = 0;
    int digit_count = 0;
    int other_count = 0;
    cout << "请输入一行字符：\n";
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letter_count++;
        }
        else if (c == ' ') {
            space_count++;
        }
        else if (c >= '0' && c <= '9') {
            digit_count++;
        }
        else {
            other_count++;
        }
    }
    cout << "英文字母个数：" << letter_count << endl;
    cout << "空格个数：" << space_count << endl;
    cout << "数字个数：" << digit_count << endl;
    cout << "其他字符个数：" << other_count << endl;
    return 0;
}