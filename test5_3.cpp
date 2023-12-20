#include <iostream> 
using namespace std;

class Cuboid {
private:
	int length, width, height;
public:
	void setInfo() {
		cout << "请输入长宽高，并以空格分割: ";
		cin >> length >> width >> height;
	}
	int volume() {
		return length * width * height;
	}
	void display() {
		cout << "volume = " << volume() << endl;
	}

};

int main()
{
	Cuboid cuboid1, cuboid2, cuboid3;

	cout << "请输入第1个长方体的信息:\n";
	cuboid1.setInfo();

	cout << "请输入第2个长方体的信息:\n";
	cuboid2.setInfo();

	cout << "请输入第3个长方体的信息:\n";
	cuboid3.setInfo();

	cout << "3个长方体的体积分别是:\n";
	cuboid1.display();
	cuboid2.display();
	cuboid3.display();
	return 0;
}
