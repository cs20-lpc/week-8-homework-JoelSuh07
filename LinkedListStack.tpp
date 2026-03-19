template <typename T>
LinkedListStack<T>::LinkedListStack()
: top(nullptr)
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    Node<T>* cur;

    while (top != nullptr) {
        cur = top;
        top = top -> next;
        delete cur;
    }

    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    this->clear(); //clears destination stack

    if (copyObj.isEmpty()) return; // if source is empty just like destination, we are done

    LinkedListStack<T> tempStack; //temporary stack to store elements but in reverse order
    Node<T>* curr = copyObj.top; //pointer to traverse

    while (curr != nullptr){
        tempStack.push(curr -> data);
        curr = curr -> next; // traversing and pushing the elements into tempStack
    }
    // after done traversing and pushing, need to put it into this object

    while (!tempStack.isEmpty()){
        this.push(tempStack.top());
        tempStack.pop();
    }
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek

    if (isEmpty()) throw string ("error: stack is empty. No elements to peek.");
    return top -> data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop

    if (isEmpty()) throw string ("error: stack is empty. No elements to pop.");

    Node<T>* cur = top;
    top = top->next; // so top is not nullptr

    delete cur;
    --this->length;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty()) throw string ("error: stack is empty. No elements to rotate.");

    if (this->getLength() < 2) return;

    if (dir == Stack<T>::RIGHT){ //move the top to the bottom. Pushing the nodes to the right

        Node<T>* oldTop = top; //saving top to assign later
        top = top->next;
        Node<T>* cur = top;

        while (cur -> next != nullptr){
            cur = cur -> next; // traverse from top to bottom until last node

        }
        
        cur -> next = oldTop;
        oldTop -> next = nullptr;

    } else if (dir == Stack<T>::LEFT){ //move the bottom to top. Pushing the nodes all to the left
        Node<T>* prev = nullptr;
        Node<T>* cur = top;


        while (cur -> next != nullptr){ // traversing from top to bottom
            prev = cur;
            cur = cur -> next;
        } // prev will be 2nd last, cur will be last

        prev -> next = nullptr;
        cur -> next = top;

        top = cur;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T>* curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
