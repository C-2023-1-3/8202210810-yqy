#include <iostream>
using namespace std;

int main()
{
    bool states[101];

    for (int i = 1; i <= 100; i++)
        states[i] = true;

    for (int i = 2; i <= 100; i++) {
        for (int j = i; j <= 100; j += i) {
            states[j] = !states[j];
        }
    }

    cout << "开着的柜子号码为：" << endl;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (states[i]) {
            cout << i << " ";
            sum++;
            if (sum % 10 == 0)
                cout << endl;
        }
    }

    return 0;
}
