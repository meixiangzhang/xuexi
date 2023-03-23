#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    friend ostream& operator<<(ostream& os, const MyString& s){
        for(int i=0; i<s._length; i++){
            os << s._data[i];
        }
        // os << s._data;
        return os;
    }
private:
    char* _data;// 开辟内存的首地址
    unsigned long _length;// 字符串长度
    unsigned long _capcity;// 开辟的内存数组长度

public:
    MyString():_data(nullptr), _length(0), _capcity(0){

    }
    MyString(const char* s){
        _length = strlen(s);
        _capcity = _length + 1;
        _data = new char[_capcity];
        strncpy(_data, s, _length);
        _data[_length] = '\0';
    }
    MyString(const MyString& s){
        if(&s == this) return;

        _length = s._length;
        _capcity = s._capcity;
        _data = new char[_capcity];
        strncpy(_data, s._data, _length);
        _data[_length] = '\0';
    }

    MyString(MyString&& s){
        // if(this->_data) delete[] _data;
        cout << "move constructor" << endl;
        _data = s._data;//接收右值的堆空间的内存的控制权
        _length = s._length;
        _capcity = s._capcity;
        s._data = nullptr;
        s._length = 0;
        s._capcity = 0;
    }

    MyString& operator=(const MyString& s){
        if(&s == this) return *this;
        if(_data){
            delete[] _data;
        }

        _length = s._length;
        _capcity = s._capcity;
        _data = new char[_capcity];
        strncpy(_data, s._data, _length);
        _data[_length] = '\0';
        return *this;
    }

    MyString& operator=(MyString&& s){
        if(&s == this) return *this;

        if(_data){
            delete[] _data;
        }

        _data = s._data;
        _length = s._length;
        _capcity = s._capcity;
        s._data = nullptr;
        s._length = 0;
        s._capcity = 0;
        return *this;
    }

    MyString& operator=(const char* s){
        if(_data){
            delete[] _data;
        }

        _length = strlen(s);
        _capcity = _length + 1;
        _data = new char[_capcity];
        strncpy(_data, s, _length);
        _data[_length] = '\0';

        return *this;
    }

    ~MyString(){
        if(_data){
            delete[] _data;
        }
    }

public:
    MyString& operator+=(const char* s){
        size_t size = strlen(s);
        if(_data){
            if(_length + size < _capcity){
                strncpy(_data+_length, s, size);
                _length += size;
                _data[_length] = '\0';
            }else{
                size_t newsize = 2*(_length+size);
                char* p = (char*)realloc(_data, newsize);
                if(p){
                    _data = p;
                    strncpy(_data+_length, s, size);
                    _length += size;
                    _data[_length] = '\0';
                }else{
                    p = (char*)malloc(newsize);
                    strncpy(p, _data, _length);
                    strncpy(p+_length, s, size);
                    _length += size;
                    _capcity = newsize;
                    p[_length] = '\0';
                    delete[] _data;
                    _data = p;
                }
            }
        }else{
            _data = (char*)malloc(size+1);
            _capcity = size + 1;
            _length = size;
            strncpy(_data, s, size);
            _data[_length] = '\0';
        }
        return *this;
    }
    MyString& operator+=(const MyString& s){
        char* p = s._data;
        return operator+=(p);
    }

    char& operator[](size_t index){
        return _data[index];
    }
    MyString operator+(const char* s){
        MyString ret(*this);
        ret += s;
        return ret;
    }
    MyString operator+(const MyString& s){
        MyString ret(*this);
        ret += s;
        return ret;
    }
};

int main(){
    MyString s = "123";
    MyString s2 = "kaikeba";
    // MyString s3(move(s));
    s2 = move(s);
    cout << s << endl;
    cout << s2 << endl;

    // cout << s << endl;
    // s += "456";
    // cout << s << endl;
    // s[1] = '9';
    // cout << s << endl;
    // s[16] = '9';
    // cout << s << endl;
    // cout << s + s2 << endl;
    // cout << "s = " << s << endl;
    // cout << "s3 = " << s2 << endl;
    return 0;
}