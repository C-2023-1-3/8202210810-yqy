#include <iostream>
using namespace std;

int Main() {
    char ch;

    cout << "请输入一个字符：";
    cin >> ch;

    if (ch >= 'a' && ch <= 'z') {
        // 如果是小写字母，则转换为大写输出
        char upper = ch - 32;
        cout << "转换为大写字母：" << upper << endl;
    }
    else {
        // 如果不是小写字母，则输出后继字符的ASCII码值
        int ascii = ch + 1;
        cout << "后继字符的ASCII码值：" << ascii << endl;
    }

    return 0;
}