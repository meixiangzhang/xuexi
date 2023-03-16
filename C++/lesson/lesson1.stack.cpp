#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "top = " << s.top() << " size = " << s.size() << endl;
    s.pop();
    cout << "top = " << s.top() << " size = " << s.size() << endl;
    s.pop();
    cout << "top = " << s.top() << " size = " << s.size() << endl;
    s.pop();

    // cout << "top = " << s.top() << " size = " << s.size() << endl;
    // 如果不判断是否为空，运行会报错
    if (!s.empty()) {
        cout << "top = " << s.top() << " size = " << s.size() << endl;
    }
    else {
        cout << "stack is empty!\n";
    }

    return 0;
}