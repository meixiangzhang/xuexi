#include <iostream>

using namespace std;

class Fraction{
    friend ostream& operator<<(ostream& os, const Fraction& f){
        os << f._numerator << "/" << f._denominator;
        return os;
    }
private:
    int _numerator;//分子
    int _denominator;//分母
public:
    Fraction(int x, int y): _numerator(x), _denominator(y){

    }
    int measure(int x, int y){
        int z = y;
        while(x%y != 0){
            z = x%y;
            x = y;
            y = z;
        }
        return z;
    }

    Fraction operator+(const Fraction& f){
        int x = this->_numerator*f._denominator + this->_denominator*f._numerator;
        int y = this->_denominator * f._denominator;
        int z = measure(x, y);
        return Fraction(x/z, y/z);
    }
    Fraction operator*(const Fraction& f){
        int x = this->_numerator*f._denominator + this->_denominator*f._numerator;
        int y = this->_denominator * f._denominator;
        int z = measure(x, y);
        return Fraction(x/z, y/z);
    }
    Fraction& operator-(){
        this->_numerator = -this->_numerator;
        return *this;
    }
    Fraction& operator+=(const Fraction& f){
        int x = this->_numerator*f._denominator + this->_denominator*f._numerator;
        int y = this->_denominator * f._denominator;
        int z = measure(x, y);
        this->_numerator = x/z;
        this->_denominator = y/z;
        return *this;
    }
    Fraction& operator*=(const Fraction& f){
        int x = this->_numerator * f._numerator;
        int y = this->_denominator * f._denominator;
        int z = measure(x, y);
        this->_numerator = x/z;
        this->_denominator = y/z;
        return *this;
    }
    bool operator==(const Fraction& f){
        return this->_numerator*f._denominator == this->_denominator*f._numerator;
    }
    bool operator>(const Fraction& f){
        return this->_numerator*f._denominator > this->_denominator*f._numerator;
    }
    bool operator<(const Fraction& f){
        return this->_numerator*f._denominator < this->_denominator*f._numerator;
    }
};

int main(){
    Fraction f1(1, 6); // f1=1/6
    Fraction f2(1, 4); // f2=1/4
    cout << f1 + f2 << endl; // 输出5/12
    cout << f1 * f2 << endl; // 输出1/24
    cout << -f1 << endl; // 输出-1/6
    f1 += f2; // 等价于f1=f1+f2
    f1 *= f2; // 等价于f1=f1*f2
    if(f1==f2)
        cout << " equalin";
    else if(f1<f2)
        cout << " smaller\n";
    else
        cout << " bigger\n";

    return 0;
}