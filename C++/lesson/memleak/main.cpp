#include <iostream>
#include "memleak.h"

using namespace std;

class A{
    int a;
    double b;
    float c;
};

int main(){
    int* a = new int{123};
    double* d = new double{3};
    int* arr = new int[100];
    char* ch = new char[32];

    delete[] arr;

    A* p = new A();

    return 0;
}