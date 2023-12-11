#include <iostream>
using namespace std;

void merge(const int list1[], int size1, const int list2[], int size2, int list3[]) {
    int i = 0; // 指向list1的索引
    int j = 0; // 指向list2的索引
    int k = 0; // 指向list3的索引
    // 比较两个数组，将较小的元素放入list3中，直到一个数组被完全遍历
    while (i < size1 && j < size2) {
        if (list1[i] <= list2[j]) {
            list3[k] = list1[i];
            i++;
        }
        else {
            list3[k] = list2[j];
            j++;
        }
        k++;
    }

    // 将剩余的元素放入list3中
    while (i < size1) {
        list3[k] = list1[i];
        i++;
        k++;
    }
    while (j < size2) {
        list3[k] = list2[j];
        j++;
        k++;
    }
}
int main() {
    int size1, size2;
    cout << "Enter list1: ";
    cin >> size1;
    int list1[80];
    for (int i = 0; i < size1; i++) {
        cin >> list1[i];
    }
    cout << "Enter list2: ";
    cin >> size2;
    int list2[80];
    for (int i = 0; i < size2; i++) {
        cin >> list2[i];
    }
    int list3[160]; // 假设最终的合并数组不会超过160个元素
    // 调用合并函数并输出结果
    merge(list1, size1, list2, size2, list3);
    cout << "The merged list is ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << list3[i] << " ";
    }
    cout << endl;
    return 0;
}