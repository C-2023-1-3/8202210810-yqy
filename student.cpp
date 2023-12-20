#include <iostream>
#include <cstring>
#include "student.h" //不要漏写此行，否则编译通不过
using namespace std;

void Student::display()         //在类外定义display类函数
{
    cout << "num：" << num << endl;
    cout << "name："<< name << endl;
    cout << "sex：" << sex << endl;
}

void Student::set_value(int n, const char* nm, char s) {
    num = n;
    strncpy_s(name, nm, 19); // 使用strncpy确保不会超过数组大小
    name[19] = '\0'; // 确保字符串正确结束
    sex = s;
}