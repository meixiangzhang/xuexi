#define _NEW_OVERRIDE_IMPLEMENTATION_
#include "memleak.h"
#include <iostream>

// std::unordered_map<void*, MemInfo> MemLeak::memPool;
MemLeak MemLeak::memleak;

MemLeak::MemLeak()
{
    std::cout << "MemLeak Constructor" << std::endl;
}

MemLeak::~MemLeak()
{
    std::cout << "-------------Leak Memory Info Start-------------\n";
    std::cout << "MemLeak Destructor" << std::endl;
    for(auto it : memPool){
        std::cout << "Leak Memory Address [" << it.first << "]";
        std::cout << "File [" << it.second.file << "]";
        std::cout << "Line [" << it.second.line << "]";
        std::cout << "Size [" << it.second.size << "]";
        std::cout << std::endl;
    }
    std::cout << "-------------Leak Memory Info End-------------\n";
}

void MemLeak::setMemInfo(void* p, const char* file, size_t line, size_t size){
    std::cout << "Malloc Address [" << p << "],";
    std::cout << "Size [" << size << "]\n";
    // memPool[p].file = file;
    // memPool[p].line = line;
    // memPool[p].size = size;
    memleak.memPool[p].file = file;
    memleak.memPool[p].line = line;
    memleak.memPool[p].size = size;
}

void MemLeak::deleteMemInfo(void* p){
    std::cout << "Free Adress [" << p << "]\n";
    // auto info = memPool.find(p);
    // if(info != memPool.end()){
    //     memPool.erase(info);
    // }
    auto info = memleak.memPool.find(p);
    if(info != memleak.memPool.end()){
        memleak.memPool.erase(info);
    }
}

void* operator new(size_t size, const char* file, size_t line){
    if(size == 0) size = 1;
    void* p = malloc(size);
    if(p == nullptr){
        std::cout << "ERROR NEW" << std::endl;
    }else{
        MemLeak::setMemInfo(p, file, line, size);
    }
    return p;
}
void* operator new[](size_t size, const char* file, size_t line){
    if(size == 0) size = 1;
    void* p = malloc(size);
    if(p == nullptr){
        std::cout << "ERROR NEW[]" << std::endl;
    }else{
        MemLeak::setMemInfo(p, file, line, size);
    }
    return p;
}
void operator delete(void* p){
    MemLeak::deleteMemInfo(p);
    if(p) free(p);
}
void operator delete[](void* p){
    MemLeak::deleteMemInfo(p);
    if(p) free(p);
}
