#include<iostream>
using namespace std;
const double PI = 3.14159; // 定义圆周率为常量

int main2() {
    double radius, height;

    cout << "请输入圆锥底的半径：";
    cin >> radius;
    cout << "请输入圆锥的高：";
    cin >> height;

    double volume = (PI * radius * radius * height) / 3.0; // 计算圆锥体积

    cout << "圆锥的体积为：" << volume << endl;

    return 0;
}