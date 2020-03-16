#include<iostream>

using namespace std;

class A {};
class B {};

class C {
    public:
        void func1();
        virtual void func2();

    private:
        static int n;
        int m;
};

class D : public A {
    virtual void fun() = 0;
};

class E : public B, public D{};

int main() {
    cout << "sizeof(A):" << sizeof(A) << endl;
    cout << "sizeof(B):" << sizeof(B) << endl;
    cout << "sizeof(C):" << sizeof(C) << endl;
    cout << "sizeof(D):" << sizeof(D) << endl;
    cout << "sizeof(E):" << sizeof(E) << endl;
    return 0;
}

// sizeof(A):1
// sizeof(B):1
// sizeof(C):16
// sizeof(D):8
// sizeof(E):8


