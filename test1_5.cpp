#include <iostream>
#include <iomanip>
using namespace std;

int main1() {
    double fahrenheit, celsius;

    while (true) {
        char c;
        cout << "�����뻪���¶�: ";
        cin >> fahrenheit;

        celsius = (fahrenheit - 32) * 5 / 9;

        cout << "�����¶�Ϊ: " << fixed << setprecision(2) << celsius << endl;
        cout << endl;
        cout << "�Ƿ����[y/n]��";
        cin >> c;
        cout << endl;
        if (c == 'n')
            break;
    }

    return 0;
}