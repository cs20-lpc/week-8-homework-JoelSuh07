#include <iostream>
#include "StackFactory.hpp"

int main()
{
    try {
        cout << "--- Testing LinkedListStack ---" << endl;
        Stack<int>* linkedStack = StackFactory<int>::GetStack(); // LinkedList Stack
        linkedStack->push(10);
        linkedStack->push(20);
        linkedStack->push(30);
        linkedStack->print();
        cout << "After 3 pushes, length: " << linkedStack->getLength() << " (Expected: 3)" << endl;
        cout << "Peek top: " << linkedStack->peek() << " (Expected: 30)" << endl;
        
        linkedStack->rotate(Stack<int>::LEFT);
        cout << "After rotate LEFT: ";
        linkedStack->print();

        linkedStack->pop();
        cout << "After pop, length: " << linkedStack->getLength() << endl;
        
        linkedStack->clear();
        cout << "After clear, isEmpty: " << (linkedStack->isEmpty() ? "Yes" : "No") << endl;
        delete linkedStack;

        cout << "\n--- Testing ArrayStack ---" << endl;
        Stack<int>* arrayStack = StackFactory<int>::GetStack(5); // Array Stack with size of 5
        arrayStack->push(1);
        arrayStack->push(2);
        arrayStack->push(3);
        arrayStack->print();
        
        cout << "Current Stack: ";
        arrayStack->print();
        
        arrayStack->rotate(Stack<int>::RIGHT);
        cout << "After rotate RIGHT: ";
        arrayStack->print();
        
        cout << "Peek: " << arrayStack->peek() << endl;
        
        arrayStack->push(4);
        arrayStack->push(5);
        cout << "Length at full: " << arrayStack->getLength() << endl;
        
        try {
            arrayStack->push(6); // Should throw overflow
        } catch (string& e) {
            cout << "Caught expected overflow: " << e << endl;
        }

        delete arrayStack;
    } catch (string& e) {
        cerr << "Unexpected Error: " << e << endl;
    }

    return 0;
}