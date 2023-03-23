#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class CBook{
private:
    string _name;
    int _price;
public:
    CBook(const char* name, int price): _name(name), _price(price){

    }
    inline string name() {return _name;}
    inline int price() {return _price;}
    virtual string desc() = 0;
};
class CComputer : public CBook{
private:
    string _desc;
public:
    CComputer(const char* name, int price, const char* desc) : CBook(name, price), _desc(desc){

    }
    string desc(){{return _desc;}}
};
class CHistory : public CBook{
private:
    string _data;
public:
    CHistory(const char* name, int price, const char* data) : CBook(name, price), _data(data){

    }
    string desc() {{return "日期：" + _data;}}
};
class CLib{
private:
    vector<CBook*> _books;
public:
    void addBook(CBook* book){
        _books.push_back(book);
    }
    void listBooks(){
        for(auto book : _books) {
            cout << book->name() << " " << book->desc() << endl;
        }
    }
    void listBooksOrderByPrice(){
        sort(_books.begin(), _books.end(), [](CBook* a, CBook* b){
            return a->price() > b->price();
        });
        for(auto book : _books) {
            cout << book->name() << " " << book->price() << endl;
        }
    }
};

int main() {
    CLib lib;
    lib.addBook(new CComputer("C++", 78, "c++高级程序设计"));
    lib.addBook(new CComputer("C语言", 118, "c语言程序设计"));
    lib.addBook(new CComputer("Java", 118, "Java程序设计"));
    lib.addBook(new CComputer("中国历史", 50, "中国历史教程"));
    lib.addBook(new CComputer("世界历史", 78, "世界历史教程"));
    lib.addBook(new CComputer("西方历史", 78, "欧洲历史教程"));

    lib.listBooks();

    cout << "-------------------" << endl;

    lib.listBooksOrderByPrice();

    return 0;
}