#include <iostream>
#include <vector>

using namespace std;

class MyAllocator{
    //相关内存开辟和释放操作相关函数

};

//继承方式
template<typename T, typename Allocator = MyAllocator>
// class MyVector : public MyAllocator{
class MyVector : protected MyAllocator{
    T* _head;
    T* _end;
    T* _capacity;
};

//组合方式
template<typename T, typename Allocator = MyAllocator>
class MyVector2 {
    T* _head;
    T* _end;
    T* _capacity;
    Allocator* alloc;
};

void use_allocator(const MyAllocator& alloc){

}

int main(){
    MyVector<int> vec;
    // use_allocator(vec);//子类无法自动向父类转换

    cout << "sizeof(MyVector<int>) = " << sizeof(MyVector<int>) << endl;
    cout << "sizeof(MyVector2<int>) = " << sizeof(MyVector2<int>) << endl;

    // std::vector

    return 0;
}