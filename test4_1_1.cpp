#include <iostream>
using namespace std;

int main() {
    cout << "Enter ten numbers: ";
    int array[10];
    int num;
    int len = 0;
    bool flag;
    for (int i = 0; i < 10; i++) {
        flag = true;
        cin >> num;
        for (int j = 0; j < i; j++) {
            // 判断数组中num是否已存在
            if (array[j] == num) {
                flag = false;
                break;
            }
        }
        // 若数组中不存在num，则将num加入数组
        if (flag) {
            array[len] = num;
            len++;
        }
    }
    cout << "The distinct numbers are: ";
    for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}