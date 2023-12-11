#include <iostream>
#include <cstring>
using namespace std;
int indexof(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i <= len2 - len1; i++) {
        int j;
        for (j = 0; j < len1; j++) {
            if (s2[i + j] != s1[j]) {
                break;
            }
        }
        if (j == len1) {
            return i;
        }
    }
    return -1;
}
int main() {
    const int SIZE = 100;
    char s1[SIZE];
    char s2[SIZE];
    cout << "Enter s1: ";
    cin.getline(s1, SIZE);
    cout << "Enter s2: ";
    cin.getline(s2, SIZE);
    int result = indexof(s1, s2);
    if (result == -1) {
        cout << "s1 不是 s2 的子串" << endl;
    } else {
        cout << "s1 是 s2 的子串，匹配位置: " << result << endl;
    }
    return 0;
}