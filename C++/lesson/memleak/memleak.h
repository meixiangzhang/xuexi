#ifndef _MEM_LEAK_H_
#define _MEM_LEAK_H_
#include <string>
#include <unordered_map>

struct MemInfo{
    std::string file;
    size_t line;
    size_t size;
};

class MemLeak
{
private:
    // static std::unordered_map<void*, MemInfo> memPool;
    std::unordered_map<void*, MemInfo> memPool;
    static MemLeak memleak;

public:
    MemLeak();
    ~MemLeak();

    static void setMemInfo(void* p, const char* file, size_t line, size_t size);
    static void deleteMemInfo(void* p);
};

void* operator new(size_t size, const char* file, size_t line);
void* operator new[](size_t size, const char* file, size_t line);
void operator delete(void* p);
void operator delete[](void* p);

#ifndef _NEW_OVERRIDE_IMPLEMENTATION_
    #define new new(__FILE__, __LINE__)
#endif

#endif