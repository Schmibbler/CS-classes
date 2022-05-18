// C++ program to illustrate
// Overloading this .(dot) operator

#include <iostream>
using namespace std;

class cantover {
public:
    void fun();
};

// assume that you can overload . operator
// Class X below overloads the . operator
class X {

    cantover* p;

    // Overloading the . operator
    cantover& operator.()
    {
        return *p;
    }

    void fun();
};

void g(X& x)
{

    // Now trying to access the fun() method
    // using the . operator
    // But this will throw an error
    // as we have overloaded the . operator above
    // Hence compiler won't allow doing so
    x.fun();
}
