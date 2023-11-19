#include <iostream>
using namespace std;

bool isTriangle(int a, int b, int c) {
    //  判断三边是否可以构成三角形
    if (a + b > c && a + c > b && b + c > a)
        return true;

    return false;
}
bool isIsoscelesTriangle(int a, int b, int c) {
    // 判断是否为等腰三角形
    if (a == b || a == c || b == c)
        return true;

    return false;
}
int main() {
    int a, b, c;

    cout << "请输入三角形的三条边：" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    if (isTriangle(a, b, c)) {
        int perimeter = a + b + c; // 计算周长

        cout << "三角形的周长为：" << perimeter << endl;

        if (isIsoscelesTriangle(a, b, c)) {
            cout << "这是一个等腰三角形！" << endl;
        }
        else {
            cout << "这不是一个等腰三角形！" << endl;
        }
    }
    else {
        cout << "这三条边不能构成三角形！" << endl;
    }

    return 0;
}