#include <iostream>

using namespace std;

class A {
public:
    virtual void who(){      //Try to delete or comment "virtual"
        cout << "Base class A.\n";
    }
};

    class B1 : public A {
    public:
        void who(){
            cout << "B1 inheritance from A.\n";
            }
    };
        class D1 : public B1 {
        public:
            void who(){
                cout << "D1 inheritance from B1.\n";
            }
        };


int main() {
    A main_cl;
    A *a;
    B1 inher_cl_B;
    D1 inher_cl_D;

    a = &main_cl;
    a -> who();

    a = &inher_cl_B;
    a -> who();

    a = &inher_cl_D;
    a -> who();


    return 0;
}
