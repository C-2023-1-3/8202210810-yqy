#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2, result;
    cout << "请输入运算式: ";
    cin >> num1 >> op >> num2;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
            result = num1 / num2;
        else {
            cout << "错误：除数不能为0！" << endl;
            return 0;
        }
        break;
    case '%':
        if (num2 != 0)
            result = (int)num1 % (int)num2;
        else {
            cout << "错误：除数不能为0！" << endl;
            return 0;
        }
        break;
    default:
        cout << "错误：无效的运算符！" << endl;
        return 0;
    }
    cout << "计算结果: " << result << endl;

    return 0;
}