#include <iostream>
using namespace std;

// 最大公约数
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// 最小公倍数
void gcdAndLcm(int m, int n, int& gcdResult, int& lcmResult) {
    gcdResult = gcd(m, n);
    lcmResult = m * n / gcdResult;
}
int main() {
    int m, n;
    cout << "请输入两个自然数: ";
    cin >> m >> n;
    int gcdResult, lcmResult;
    gcdAndLcm(m, n, gcdResult, lcmResult);
    cout << m << " 和 " << n << "的最大公约数为" << gcdResult << endl;
    cout << m << " 和 " << n << "的最小公倍数为" << lcmResult << endl;
    return 0;
}