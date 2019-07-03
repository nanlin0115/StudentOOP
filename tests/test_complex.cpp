#include <cassert>
#include <iostream>
#include "../my_code/complex.h"
//#include "complex.h"
using namespace std;

const bool DEBUGG = true;


int main() {
    cout << "Input a complex number:\n";
    Complex c1{12, 13};
    //travis can't cin
    // get a complex from stdin:
    //    cin >> c1;
    //    if(!cin)
    //    {
    //        cerr << "Bad input format\n";
    //        exit(1);
    //    }
    //       if(DEBUGG)
    //        {
    //           cout << "c1 = " << c1 << endl;
    //        }
    
    Complex c2{43.2, 58.9};
    assert(c2.get_real() == 43.2);
    assert(c2.get_imag() == 58.9);
    
    if(DEBUGG)
    {
        cout << "c2 = " << c2 << endl;
    }
    
    // see if `Complex` addition works:
    Complex c3 = c1 + c2;
    assert(c3.get_real() > 43.2);
    cout <<"c3:"<< c3<<endl;
    // see if `Complex` subtraction works:
    Complex c4 = c3 - c2;
    cout<<"c4:"<<c4<<endl;
    //assert(c4 == c1);
    
    Complex c5 = Complex();
    // test pre-increment:
    ++c5;
    ++c5;
    assert(c5.get_real() == 2);
    Complex postinc = c5++;
    assert(postinc.get_real() == 2);
    postinc--;
    assert(postinc.get_real() == 1);
    /*
     * Test equality operator. If we take the `explicit` off of
     * `bool()` in class definition, then this will fail as ambiguous:
     * the compiler won't know if we want a `bool` or `Complex` comparison.
     * */
    if (1 == bool(c5))
        cout << "c5 == 1 is true\n";
    else
        cout << "c5 == 1 is false\n";
    // test bool() operator:
    if (c4) {
        cout << "c5 is true\n";
    }
    else {
        cout << "c5 is false\n";
    }
    assert(c5);
    
    /*
     * The next line of code will implicitly
     * construct a `Complex` out of 14.2 using the default
     * imaginary component of 0.0.
     * */
    Complex c6 = 14.2;
    cout << c6 << endl;
    assert(c6.get_real() == 14.2);
    Complex scalar_prod = c6 * 2;
    assert(scalar_prod.get_real() == 28.4);
    assert(scalar_prod.get_imag() == 0.0);
}
