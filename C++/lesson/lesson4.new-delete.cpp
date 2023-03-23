#include <iostream>
#include <cstring>

using namespace std;

// 对new 和 delete 进行重载，然后判断main函数中有哪些对象只开辟了内存，但是没有释放
//把未释放的内存大小打印出来
struct MemInfo
{
    void* ptr;
    size_t size;
    char file[100];
    size_t line;
};

int MemIndex = 0;
MemInfo MemArray[100];


void* operator new(size_t size, const char* file, size_t line){
    // cout << __LINE__ << endl;
    cout << "operator new " << endl;
    void* p = malloc(size);
    // return nullptr;
    // MemArray[index] = MemInfo{p, size};
    // MemArray[index] = MemInfo{};
    MemArray[MemIndex].ptr = p;
    MemArray[MemIndex].size = size;
    strcpy(MemArray[MemIndex].file, file);
    MemArray[MemIndex].line = line;
    MemIndex++;
    return p;
}

void operator delete(void* p){
    for(int i = 0; i < 100; i++){
        if(MemArray[i].ptr == p)
            MemArray[i].size = 0;
    }
    cout << "operator delete" << endl;
    if(p)
        free(p);
}

class A{
public:
    A(){
        cout << "default constructor" << endl;
    }
    ~A(){
        cout << "destructor" << endl;
    }

};

// char Cache[1024];
#define new new(__FILE__, __LINE__)

int main(){
    

    A* p = new A(); // 1、operator new  2、构造函数
    int* p2 = new int(3);
    delete p;

    // A* p2 = new(Cache) A();
    // A* p3 = new(Cache + sizeof(A)) A();

    size_t size = 0;
    for(auto it : MemArray){
        if(it.size != 0){
            size += it.size;
            cout << " address = " << it.ptr << " size = " << it.size << " file = " << it.file << " line = " << it.line << endl;
        }
    }
    cout << "leaked memory size = " << size << endl;

    return 0;
}