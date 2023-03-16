#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> hashmap;
    hashmap["abc"] = 123;
    hashmap["abcd"] = 123;
    hashmap["abcde"] = 123;

    cout << "size = " << hashmap.size() << endl;

    // cout << "hashmap[\"aabc\"] = " << hashmap["aabc"] << endl;
    // 如果不先判断是否存在，要是不存在，将会自动创建，一样能打印出来，并且 hashmap 的长度会加 1
    auto it = hashmap.find("aabc");
    if (it != hashmap.end())
        cout << "hashmap[\"aabc\"] = " << hashmap["aabc"] << endl;
    else
        cout << "hashmap[\"aabc\"] is not exsits" << endl;

    cout << "size = " << hashmap.size() << endl;

    for (unordered_map<string, int>::iterator it = hashmap.begin(); it != hashmap.end(); ++it) {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }

    for (auto it : hashmap) {
        cout << "----key = " << it.first << " value = " << it.second << endl;
    }


    return 0;
}