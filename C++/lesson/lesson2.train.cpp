#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    // 整数反转
    int n = 123456789, m;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    n = atoi(s.c_str());
    cout << "n = " << n << endl;

    // 判断是否是回文数
    string s1 = "123455654321";
    string s2 = s1;
    reverse(s1.begin(), s1.end());
    if (s1 == s2) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // 排序
    int arr[] = {1, 58, 4, 6, 9, 79, 2, 69, 49, 4};
    int len = sizeof(arr) / sizeof(int);
    // // sort(arr, arr + len); // 从小到大排序
    // // sort(arr, arr + len, greater<int>()); // 从大到小排序
    // stable_sort(arr, arr + len, greater<int>()); // 从大到小排序
    // for (auto i : arr) {
    //     cout << i << " ";
    // }
    cout << endl;

    map<int, int> mymap;
    for (auto i : arr) {
        mymap.insert(pair<int, int>(i, 0));
    }
    // for (auto it : mymap) { // 从小到大排序
    //     cout << it.first << " ";
    // }

    for (auto it = mymap.rbegin(); it != mymap.rend(); ++it) { // 从大到小排序
        cout << it->first << " ";
    }
    cout << endl;

    return 0;
}