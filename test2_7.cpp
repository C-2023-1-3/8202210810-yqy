#include <iostream>
using namespace std;

int main_7() {
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}