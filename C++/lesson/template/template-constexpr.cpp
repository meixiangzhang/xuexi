#include <iostream>

using namespace std;

class AbstractPerson{
public:
    virtual ~AbstractPerson(){}
};
class PersonA : public AbstractPerson{
public:
    void speakEnglish(){
        cout << "call speak english" << endl;
    }
};
class PersonB : public AbstractPerson{
public:
    void speakChinese(){
        cout << "call speak chinese" << endl;
    }
};

template<class T>
void speak(T* t){
    if constexpr(std::is_same<T, PersonA>{}){
        t->speakEnglish();
    }
    else if constexpr(std::is_same<T, PersonB>{}){
        t->speakChinese();
    }
    // PersonA* person = dynamic_cast<PersonA*>(t);
    // if(person){
    //     person->speakEnglish();
    // }else{
    //     PersonB* personB = dynamic_cast<PersonB*>(t);
    //     personB->speakChinese();
    // }
}

template<class T>
void speak(T t){
    t.speakEnglish();
    t.speakChinese();
}

int main(){
    int a = 123;
    int b = 456;
    const int c = a + b;

    constexpr int a1 = 123;
    constexpr int a2 = 456;

    constexpr int d = a1 + a2;

    PersonA* personA = new PersonA();
    PersonB* personB = new PersonB();

    speak(personA);
    speak(personB);


    return 0;
}