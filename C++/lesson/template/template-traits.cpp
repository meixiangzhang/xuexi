#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class iter>
typename iter::value_type MySum(iter begin, iter end){
    typename iter::value_type ret{0};
    for(iter i = begin; i != end; ++i){
        ret += *i;
    }
    return ret;
}

template<typename iter>
struct metatraits
{
    using value_type = typename iter::value_type;
};

template<typename iter>
struct metatraits<iter*>
{
    using value_type = iter;
};

template<class iter>
typename metatraits<iter>::value_type MySum2(iter begin, iter end){
    typename metatraits<iter>::value_type ret{0};
    for(iter i = begin; i != end; ++i){
        ret += *i;
    }
    return ret;
}

int main(){
    vector<int> arr;
    for(int i=1; i<=100;i++){
        arr.push_back(i);
    }

    //vector<int>::iterator::value_type
    //vector<int>::iterator
    cout << MySum(arr.begin(), arr.end()) << endl;

    int arr2[] = {46,546,9,12,91,64,9,1,4,61,6,18,78,1,65};
    cout << MySum2(arr.begin(), arr.end()) << endl;
    cout << MySum2(arr2, arr2+15) << endl;

    return 0;
}