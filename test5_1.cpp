#include<iostream>
using namespace std;
class Time             // 定义Time类
{
private:              // 数据成员为公用的
		int hour;
		int minute;
		int sec;
public:
	// 构造函数
	Time() : hour(0), minute(0), sec(0){}

	void setTime();
	void showTime() const {
		cout << hour << ":" << minute << ":" << sec << endl;
	}
};

void Time::setTime() {
    // 输入小时数，检查有效性
    while (true) {
        cout << "Enter hour (0-23): ";
        cin >> hour;
        if (hour >= 0 && hour <= 23) {
            break;
        }
        cout << "Invalid hour. Please try again.\n";
    }

    // 输入分钟数，检查有效性
    while (true) {
        cout << "Enter minute (0-59): ";
        cin >> minute;
        if (minute >= 0 && minute <= 59) {
            break;
        }
        cout << "Invalid minute. Please try again.\n";
    }

    // 输入秒数，检查有效性
    while (true) {
        cout << "Enter second (0-59): ";
        cin >> sec;
        if (sec >= 0 && sec <= 59) {
            break;
        }
        cout << "Invalid second. Please try again.\n";
    }
}

int main()
{
	Time t1;           //定义t1为Time类对象
	t1.setTime();      //输入设定的时间
	t1.showTime();
	return 0;
}
