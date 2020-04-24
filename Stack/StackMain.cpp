#include "Stack.hpp"
#include "Stack_LinkedListImplementation.hpp"

int main()
{
    Stack<int> myStack(1);
    cout << "First printStack should print empty: ";
    myStack.printStack();
    
    myStack.push(2);

    cout << "\nNow pushed element 2, it should only print 2: ";
    myStack.printStack();

    myStack.push(4);
    cout << "\nNow pushed element 4 as well, it should print 4 and 2:\n";
    myStack.printStack();
    cout << "\nsize should be 2: " << myStack.returnStackSize() << "\n";

    myStack.push(8); myStack.push(10); myStack.push(20); myStack.push(22); myStack.push(89); myStack.push(90);
    cout << "\nNow size shoulde be 8: " << myStack.returnStackSize() << "\nAnd in this order"
    << "90 89 22 20 10 8 4 2\n";
    myStack.printStack();

    cout << "Popped item should be 90: " << myStack.pop() << "\nNow it should be 89: " << myStack.pop()
    << "\nNow it should be 22: " << myStack.pop() << "\nNow 20: " << myStack.pop();

    cout << "\nNow size should be 4: " << myStack.returnStackSize() 
    << "\n And in this order: 10 8 4 2\n";
    myStack.printStack();

    cout << "peeking at 1st element should give 10: " << myStack.peek() << "\n";

    cout << "Popped one 10: " << myStack.pop() << "\nNow 8: " << myStack.pop() << "\nNow 4: " << myStack.pop();

    cout << "\nNow size should be 1: " << myStack.returnStackSize() 
    << "\n and that should be 2: ";
    myStack.printStack();





    cout <<"\n\n\nNow Second stack of Linked List\n";

    Stack_LL<int> newStack;

    cout << "First printStack should print empty: ";
    newStack.printStack();
    
    newStack.push(2);

    cout << "\nNow pushed element 2, it should only print 2: ";
    newStack.printStack();

    newStack.push(4);
    cout << "\nNow pushed element 4 as well, it should print 4 and 2:\n";
    newStack.printStack();
    cout << "\nsize should be 2: " << newStack.returnStackSize() << "\n";

    newStack.push(8); newStack.push(10); newStack.push(20); newStack.push(22); newStack.push(89); newStack.push(90);
    cout << "\nNow size shoulde be 8: " << newStack.returnStackSize() << "\nAnd in this order"
    << "90 89 22 20 10 8 4 2\n";
    newStack.printStack();

    cout << "Popped item should be 90: " << newStack.pop() << "\nNow it should be 89: " << newStack.pop()
    << "\nNow it should be 22: " << newStack.pop() << "\nNow 20: " << newStack.pop();

    cout << "\nNow size should be 4: " << newStack.returnStackSize() 
    << "\n And in this order: 10 8 4 2\n";
    newStack.printStack();

    cout << "peeking at 1st element should give 10: " << newStack.peek() << "\n";

    cout << "Popped one 10: " << newStack.pop() << "\nNow 8: " << newStack.pop() << "\nNow 4: " << newStack.pop();

    cout << "\nNow size should be 1: " << newStack.returnStackSize() 
    << "\n and that should be 2: ";
    newStack.printStack();
    return 0;
}