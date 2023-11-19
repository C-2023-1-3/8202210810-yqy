#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int count = 0;
	int total = 0;
	int i = 1;
	double avg = 0;
	while (true) {
		// 今天买的个数
		count = pow(2, i);
		if (count >= 100) {
			i--;
			avg = total * 0.8 / i;
			break;
		}
		// 总共买的个数
		total += count;
		cout << "第" << i << "天买了" << count << "个苹果" << endl;
		i++;
	}
	cout << "平均花销：" << avg << endl;
	cout << "天数：" << i << endl;
	cout << "苹果数：" << total << endl;
	return 0;
}