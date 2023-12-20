#include <iostream> 
using namespace std;
#define SIZE 5

class Point {
private:
	int x, y;
public:
	Point() :x(60), y(80){}
	void setPoint(int i, int j) {
		x += i;
		y += j;
	}
	void display() {
		cout << "Point: (" << x << ", " << y << ")" << endl;
	}
};

int main()
{
	Point point; // 默认构造函数将坐标初始化为(60,80)

	cout << "Initial Point: ";
	point.display(); // 显示初始坐标

	point.setPoint(5, 10); // 修改坐标为(65,90)
	cout << "Modified Point: ";
	point.display(); // 显示修改后的坐标
	return 0;
}
