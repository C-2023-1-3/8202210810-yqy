#include <iostream>
using namespace std;

int calculatePeaches(int day) {
    // 第十天时，只有1个桃子
    if (day == 10) {
        return 1;
    }
    else {
        // 每天吃剩下的桃子数量是前一天吃剩下的桃子数量的一半减1
        return 2 * (calculatePeaches(day + 1) + 1);
    }
}
int main() {
    int totalPeaches = calculatePeaches(1);
    cout << "第一天猴子共摘了 " << totalPeaches << " 个桃子" << endl;
    return 0;
}