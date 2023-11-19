#include <iostream>
#include <cmath>
using namespace std;

double sqrtByIteration(double a) {
    double x = a; // 初始猜测值
    double epsilon = 1e-5; // 精度控制，小于10^-5
    double diff = epsilon + 1; // 初始差异
    while (diff > epsilon) {
        double nextX = 0.5 * (x + a / x); // 使用牛顿迭代法求下一个估计值
        diff = abs(nextX - x); // 计算差异
        x = nextX; // 更新估计值
    }
    return x;
}

int main() {
	double a;
	cout << "请输入一个大于0的数：";
	cin >> a;
	while (a <= 0) {
		cout << "您的输入有误，请重新输入一个大于0的数：";
		cin >> a;
	}
    double sqrtValue = sqrtByIteration(a);
    cout << a << " 的平方根为: " << sqrtValue << endl;
    return 0;
}