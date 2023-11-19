#include <iostream>
using namespace std;

float f(float x) {
	if (0 < x && x < 1) {
		return 3 - 2 * x;
	}
	else if (1 <= x && x < 5) {
		return 0.5 / x + 1;
	}
	else if (5 <= x && x < 10) {
		return	x * x;
	}
	else {
		return NULL;
	}
}

int main() {
	float x;
	cout << "请输出入一个大于0小于10的数：";
	cin >> x;
	while (true) {
		float y = f(x);
		if (y == NULL) {
			cout << "请重新输入一个大于0小于10的数：";
			cin >> x;
		}
		else {
			cout << "y = " << y << endl;
			break;
		}
	}
	return 0;
}