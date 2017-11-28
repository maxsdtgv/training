#include <iostream>
using namespace std;

class A {
public:
  virtual void who(){
        cout << "Function in class A\n";
    }
};

class B : public A {
public:
   void who(){
        cout << "Function in class B\n";
    }

};

class C : public B {
public:
    void who(){
        cout << "Function in class C\n";
    }
};

int main(){
    A orig_a;
    A *point;

    B orig_b;
    C orig_c;


    point = &orig_a;
    point -> who();

    point = &orig_b;
    point -> who();

    point = &orig_c;
    point -> who();


    return 0;


}
