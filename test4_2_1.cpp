#include <iostream>
using namespace std;
int* f()
{
    int* list = new int[4]; // 在堆上动态分配内存
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    list[3] = 4;
    return list;
}
int main()
{
    int* p = f();
    cout << p[0] << endl; // 输出1
    cout << p[1] << endl; // 输出2
    delete[] p; // 释放动态分配的内存
    return 0;
}