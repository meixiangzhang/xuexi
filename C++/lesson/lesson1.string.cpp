#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string s1, s2;

    s1 = "hello";
    s2 = "world";
    cout << "s1 = " << s1 << " size = " << s1.size() << endl;

    s1 += s2;
    cout << "s1 = " << s1 << " size = " << s1.size() << endl;
    cout << "s1 = " << s1 << " size = " << s1.length() << endl;
    cout << "s2 = " << s2 << endl;

    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1[9] = " << s1[9] << endl;
    cout << "s1[10] = " << s1[10] << endl;
    cout << "s1[11] = " << s1[11] << endl;
    cout << "s1[20] = " << s1[20] << endl;
    cout << "s1[120] = " << s1[120] << endl;

    s1[10] = 'H'; // 不会改变字符串及其大小

    cout << "s1 = " << s1 << " size = " << s1.size() << endl;
    cout << "s1[10] = " << s1[10] << endl;
    cout << "s1[11] = " << s1[11] << endl;

    int n = 1000000000;
    while (n--) {
        s1 += '1';
    }
    // cout << "s1 = " << s1 << " size = " << s1.size() << endl;

    // c 语言中，计算字符串长度 strlen 用的是遍历；
    // 而 C++ 中则不同

    long start = clock();
    int size = s1.size();
    cout << "c++ size = " << size << " time = " << clock() - start << endl;

    start = clock();
    size = strlen(s1.c_str());
    cout << "c size = " << size << " time = " << clock() - start << endl;
    
    return 0;
}