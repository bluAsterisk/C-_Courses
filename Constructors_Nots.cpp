#include <iostream>

using namespace std;

class foo{
public:
    foo() { cout << "default constructor called \n";
                    m_int = -1;}
    foo(const foo&other) { cout << "copy constructor called \n";
                    m_int = other.m_int;}
    foo(int var) { cout <, "conversion constructor called \n";
                    m_int = var; }
private:
int m_int;
};

int main(
{
    foo bar = 2;
    cout << "bar = " << bar.get() << endl;
    
    foo bar2;
    cout << "bar2 = " << bar2.get() << endl;
    
    bar2 = bar;
    cout << "bar3 = " << bar3.get() << endl;
    
    bar2 = 2;
    cout << "bar4 = " << bar4.get() << endl;
    
    return 0;
}