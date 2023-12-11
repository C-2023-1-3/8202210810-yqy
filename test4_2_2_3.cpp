#include <iostream>
using namespace std;

void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
int main() {
    int size;
    cout << "请输入数组长度: ";
    cin >> size;
    int* arr = new int[size];
    cout << "请输入数组元素: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
    
    sortArray(arr, size);
    cout << "排序后        : ";
    printArray(arr, size);
    delete[] arr;
    return 0;
}