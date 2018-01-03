#include <iostream>
#include <string>
#include "LinkedStack.h"
#include "ArrayStack.h"
using namespace std;
int main()
{
    StackInterface<string>* sp = new ArrayStack<string>();
    LinkedStack<string>* sp2 = new LinkedStack<string>();
    string item = "Huong";
    sp->push(item);
    sp2->push(item);
    LinkedStack<string> sp3(*sp2);
    
    cout << sp->peek() << endl;
    cout << sp2->peek() << endl;
    cout << sp3.peek() << endl;

    sp->pop();
    cout << sp->peek() << endl; // will cause Assertion failed
    return 0;
}
