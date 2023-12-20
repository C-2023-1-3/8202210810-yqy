#include <iostream> 
using namespace std;
#define SIZE 5

class Student {
private:
	int id, score;
public:
	Student() : id(0), score(0){}
	Student(int id, int score) : id(id), score(score) {}
	int getId() {
		return id;
	}
	int getScore() {
		return score;
	}
};

void max(Student* student) {
	if (SIZE <= 0)return;

	int maxIndex = 0;
	int maxScore = student[0].getScore();

	for (int i = 1; i < SIZE; i++) {
		if (maxScore < student[i].getScore()) {
			maxIndex = i;
			maxScore = student[i].getScore();
		}
	}
	cout << "最高分学生信息：" << endl;
	cout << "id：" << student[maxIndex].getId() << " 成绩：" << student[maxIndex].getScore() << endl;
}

int main()
{
	Student students[SIZE] = {
		Student(101, 80),
		Student(102, 85),
		Student(103, 90),
		Student(104, 100),
		Student(105, 95)
	};
	for (int i = 0; i < SIZE; i++) {
		cout << "学生id：" << students[i].getId() << " 成绩：" << students[i].getScore() << endl;
	}
	cout << endl;
	max(students);
	return 0;
}
