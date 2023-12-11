#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // 字符串的最大尺寸

int indexOf(const char s1[], const char s2[]) {
    int i = 0, j = 0;
    int matchIndex = -1; // 匹配的下标
    int currentIndex = 0;// 当匹配到后，重新匹配的位置
    bool flag = false;//若匹配到了相同的字符串
    while (s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            // 若匹配到相同字符，此时是s1第一个字符匹配，则重置匹配下表为此时s2的下标
            if (i == 0) {
                matchIndex = j;
                currentIndex = j;
            }
            flag = true;
            i++;
        }
        else {
            // 若发现为匹配，则重置匹配状态
            i = 0;
            matchIndex = -1;
            if (flag) {
                j = currentIndex;
                flag = false;
            }
        }
        if (s1[i] == '\0') {
            // s1已经完全匹配
            break;
        }
        j++;
    }
    return matchIndex;
}

int main()
{
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];
    cout << "Enter the first string: ";
    cin.getline(s1, MAX_SIZE);
    cout << "Enter the second string: ";
    cin.getline(s2, MAX_SIZE);
    cout << "indexOf(“" << s1 << "”, “" << s2 << "”) is ";
    int index = indexOf(s1, s2);
    cout << index << endl;
    return 0;
}
