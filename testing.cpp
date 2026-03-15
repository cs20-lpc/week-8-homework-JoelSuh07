#include <iostream>
#include "StackFactory.hpp"

int main()
{
    try {
        cout << "--- Testing LinkedListStack ---" << endl;
        Stack<int>* linkedStack1 = StackFactory<int>::GetStack(); // LinkedList Stack
        Stack<double>* linkedStack2 = StackFactory<double>::GetStack();
        Stack<string>* linkedStack3 = StackFactory<string>::GetStack();

        linkedStack1->push(10);
        linkedStack1->push(20);
        linkedStack1->push(30);
        linkedStack1->print();
        
        cout << "After 3 pushes, length: " << linkedStack1->getLength() << " (Expected: 3)" << endl;
        cout << "Peek top: " << linkedStack1->peek() << " (Expected: 30)" << endl;
        
        linkedStack1->rotate(Stack<int>::LEFT);
        cout << "After rotate LEFT: ";
        linkedStack1->print();

        linkedStack1->pop();
        cout << "After pop, length: " << linkedStack1->getLength() << endl;
        
        linkedStack1->clear();
        linkedStack1->print();
        cout << "After clear, isEmpty: " << (linkedStack1->isEmpty() ? "Yes" : "No") << endl;
        
        linkedStack2->push(10.1);
        linkedStack2->push(10.2);
        linkedStack2->push(10.3);
        //linkedStack1 = linkedStack2; //will not compile
        //linkedStack3->push(1);
        linkedStack3->push("j");

        cout << "Printing double stack: " << endl;
        linkedStack2->print();

        cout << "Printing string stack: " << endl;
        linkedStack3->print();

        delete linkedStack1;
        delete linkedStack2;
        delete linkedStack3;

        cout << "\n--- Testing ArrayStack ---" << endl;
        Stack<int>* arrayStack1 = StackFactory<int>::GetStack(5); // Array Stack with size of 5
        arrayStack1->push(1);
        arrayStack1->push(2);
        arrayStack1->push(3);
        arrayStack1->print();
        
        cout << "Current Stack: ";
        arrayStack1->print();
        
        arrayStack1->rotate(Stack<int>::RIGHT);
        cout << "After rotate RIGHT: ";
        arrayStack1->print();
        
        cout << "Peek: " << arrayStack1->peek() << endl;
        
        arrayStack1->push(4);
        arrayStack1->push(5);
        cout << "Length at full: " << arrayStack1->getLength() << endl;

        try {
            arrayStack1->push(6); // Should throw overflow
        } catch (string& e) {
            cout << "Caught expected overflow: " << e << endl;
        }

        delete arrayStack1;
    } catch (string& e) {
        cerr << "Unexpected Error: " << e << endl;
    }

    return 0;
}