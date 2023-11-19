#include <iostream>
#include <iomanip>
using namespace std;

int main1() {
    double fahrenheit, celsius;

    while (true) {
        char c;
        cout << "请输入华氏温度: ";
        cin >> fahrenheit;

        celsius = (fahrenheit - 32) * 5 / 9;

        cout << "摄氏温度为: " << fixed << setprecision(2) << celsius << endl;
        cout << endl;
        cout << "是否继续[y/n]：";
        cin >> c;
        cout << endl;
        if (c == 'n')
            break;
    }

    return 0;
}