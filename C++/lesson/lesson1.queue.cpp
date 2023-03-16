#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "front = " << q.front() << " back= " << q.back() << " size = " << q.size() << endl;
    q.pop();
    cout << "front = " << q.front() << " back = " << q.back() << " size = " << q.size() << endl;
    q.pop();
    cout << "front = " << q.front() << " back = " << q.back() << " size = " << q.size() << endl;
    q.pop();

    // cout << "front = " << q.front() << " back = " << q.back() << " size = " << q.size() << endl;
    // 如果不判断队列是否为空，运行成功，输出结果是错的
    if (!q.empty()) { 
        cout << "front = " << q.front() << " back = " << q.back() << " size = " << q.size() << endl;
    }
    else {
        cout << "queue is empty!! " << endl;
    }
    
    return 0;
}
