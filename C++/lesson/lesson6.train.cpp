#include <iostream>

using namespace std;

class Animal{
private:
    int _weight, _height, _age;
    string _name;
public:
    Animal():_weight(0), _height(0), _age(0), _name(""){

    }

    void walk(){cout << "Animal walk" << endl;}
    void run(){cout << "Animal run" << endl;}
    void jump(){cout << "Animal jump" << endl;}
    void say(){cout << "Animal say" << endl;}
};
class People : public Animal{
private:
    string _name;
    char _gender;
    int _skin;
    int _nation;
public:
    People():_name(""), _gender(0), _skin(0), _nation(0){

    }

    void walk(){cout << "People walk" << endl;}
    void run(){cout << "People run" << endl;}
    void jump(){cout << "People jump" << endl;}
    void say(){cout << "People say" << endl;}
};

class Teacher : public People{
private:
    int _level, _subject, _teach_years;
public:
    Teacher():_level(0), _subject(0), _teach_years(0){

    }
    void teach(){cout << "Teacher teach" << endl;}
};

int main(){
    // Animal* a = new Teacher();
    // a->run();
    // a->jump();
    // ((Teacher*)a)->teach();
    Teacher* a = new Teacher();
    a->run();
    a->jump();
    a->teach();
    
    return 0;
}