#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    // create a stack with capacity of 5
    Stack myStack<int>(5);

    // push some elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // pop an element from the stack
    cout << "Popped element: " << myStack.pop() << std::endl;

    // push some more elements onto the stack
    myStack.push(40);
    myStack.push(50);

    // try to push another element onto the full stack
    myStack.push(60);

    // print the top element without removing it
    cout << "Top element: " << myStack.peek() << std::endl;

    // pop all elements from the stack
    while (!myStack.isEmpty()) 
    {
        cout << "Popped element: " << myStack.pop() << std::endl;
    }

    


    return 0;
}
