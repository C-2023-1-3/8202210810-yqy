#include <iostream>
using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 计算最小公倍数
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}int main_6() {
    int a, b;
    cout << "请输入两个正整数：";
    cin >> a >> b;
    // 调用函数计算最大公约数和最小公倍数
    int greatestCommonDivisor = gcd(a, b);
    int leastCommonMultiple = lcm(a, b);
    cout << "最大公约数：" << greatestCommonDivisor << endl;
    cout << "最小公倍数：" << leastCommonMultiple << endl;
    return 0;
}
