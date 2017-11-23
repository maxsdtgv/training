#include <iostream>

using namespace std;

class A {
public:
    virtual void who(){        // Try to delete word virtual
        cout << "Function 'who()' in class A.\n";
    }
};
class B1 : public A {
public:
    void who(){
        cout << "Function 'who()' in class B1, inheritate from class A.\n";
    }
};
class D1 : public B1 {
public:
    void who(){
        cout << "Function 'who()' in class D1, inheritate from class B1.\n";
    }
};


int main(){
    A base_cl;
    A *q;
    B1 inher_cl_B;
    D1 inher_cl_D;

    q = &base_cl;
    q -> who();

    q = &inher_cl_B;
    q -> who();

    q = &inher_cl_D;
    q -> who();


    return 0;
}
