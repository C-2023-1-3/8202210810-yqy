#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i*i<=num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int sum = 0;
    int num = 2;
    while (sum < 200) {
        if (is_prime(num)) {
            sum++;
            cout << num << " ";
            if (sum % 10 == 0) cout << endl;
        }
        num++;
    }
    return 0;
}