// g++ -std=c++11 thisFile.cpp

#include <iostream>
#include <thread>

using namespace std;

// -----------------------------------------------------------------
class Box {
  public:
    function<void(string)> theFunction;
    bool funValid;

    Box() : funValid(false) {}

    void setFun(function<void(string)> f) {
        theFunction = f;
        funValid = true;
    }

    void callIt() {
        if (!funValid)
            return;
        theFunction(" hello from Box ");
    }
}; // class

// -----------------------------------------------------------------
class FunClass {
  public:
    string msg;
    FunClass(string m) : msg(m) {}
    void operator()(string s) { cout << msg << s << endl; }
};

// -----------------------------------------------------------------
void f(string s) { cout << s << endl; } // ()

// -----------------------------------------------------------------
void call_it(void (*pf)(string)) { pf("call_it: hello"); } // ()

// -----------------------------------------------------------------
void call_it1(function<void(string)> pf) { pf("call_it1: hello"); } // ()

// -----------------------------------------------------------------
int main() {

    int a = 1234;

    FunClass fc(" christmas ");

    f("hello");

    call_it(f);

    call_it1(f);

    // conversion ERROR: call_it ( [&] (string s) -> void { cout << s << a <<
    // endl; } );

    call_it1([&](string s) -> void { cout << s << a << endl; });

    Box ca;

    ca.callIt();

    ca.setFun(f);

    ca.callIt();

    ca.setFun([&](string s) -> void { cout << s << a << endl; });

    ca.callIt();

    ca.setFun(fc);

    ca.callIt();

} // ()
