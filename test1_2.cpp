#include<iostream>
using namespace std;
const double PI = 3.14159; // ����Բ����Ϊ����

int main2() {
    double radius, height;

    cout << "������Բ׶�׵İ뾶��";
    cin >> radius;
    cout << "������Բ׶�ĸߣ�";
    cin >> height;

    double volume = (PI * radius * radius * height) / 3.0; // ����Բ׶���

    cout << "Բ׶�����Ϊ��" << volume << endl;

    return 0;
}