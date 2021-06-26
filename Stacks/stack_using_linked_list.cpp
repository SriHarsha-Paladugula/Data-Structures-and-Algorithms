#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
class stack_using_linked_list
{
    private:
        Node<T> *top;
    public:
        stack_using_linked_list();
        ~stack_using_linked_list();
        void push(T value);
        T pop();
        T peek(int pos);
        bool isEmpty();
        bool isFull();
        T StackTop();
        void displayStack();
};

template<class T>
stack_using_linked_list<T>::stack_using_linked_list()
{
    top = nullptr;
}

template<class T>
stack_using_linked_list<T>::~stack_using_linked_list()
{
    Node<T>* temp = new Node<T>;
    temp = top;
    while(top)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
}

template<class T>
bool stack_using_linked_list<T>::isEmpty()
{
    if(top == nullptr)
        return true;
    return false;    
}

template<class T>
bool stack_using_linked_list<T>::isFull()
{
    Node<T> *temp= new Node<T>;
    if(temp)
        return false;
    return true;    
}

template<class T>
void stack_using_linked_list<T>::push(T value)
{
    if(isFull())
        cout << "Stack Overflow!" << endl;
    else
    {
        Node<T> *temp= new Node<T>;
        temp->data = value;
        temp->next = top;
        top = temp;
    }    
}

template<class T>
T stack_using_linked_list<T>::pop()
{
    T out;
    if(isEmpty())
        cout << "Stack Underflow!" << endl;
    else
    {    
        Node<T> *temp= new Node<T>;
        temp=top;
        top = top->next;
        temp->next = nullptr;
        out = temp->data;
        delete temp;
    }
    return out;
}

template<class T>
T stack_using_linked_list<T>::peek(int pos)
{
    Node<T> *temp= new Node<T>;
    temp = top;
    while(temp && pos > 1)
    {
        temp = temp->next;
        pos = pos -1;
    }
    if(temp)
        return temp->data;
    else
    {
        cout << "Invalid position" << endl;
        return -1;
    }    
}

template<class T>
T stack_using_linked_list<T>::StackTop()
{
    return top->data;
}

template<class T>
void stack_using_linked_list<T>::displayStack()
{
    while(top)
    {
        cout<<top->data<<flush;
        top= top->next;
    }
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    stack_using_linked_list<int> stk;
 
    // Populate stack
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
 
    cout << "Stack peek at 3rd: " << stk.peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.peek(10) << endl;
    cout << "Stack top: " << stk.StackTop() << endl;
    cout << "Stack full: " << stk.isFull() << endl;
    cout << "Stack empty: " << stk.isEmpty() << endl;
 
    // Pop out elements from stack
    cout << "Popped: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
 
    // Underflow
    cout << stk.pop() << endl;
 
    return 0;
}