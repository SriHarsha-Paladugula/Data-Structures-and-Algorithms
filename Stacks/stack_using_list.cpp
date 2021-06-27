#include <iostream>
#include<cstring>
using namespace std;


template <typename T>
class Stack
{
    T *array; 
    int top;
    int size;

    public:
    Stack();
    Stack(int size);
    ~Stack() ;
    void push(T value);
    T pop();
    T peek(int pos);
    bool isEmpty();
    bool isFull();
    T StackTop();
    void displayStack();
};

template<class T>
Stack<T>::Stack()
{
    size = 0;
    array = nullptr;
    top = -1;
}

template<class T>
Stack<T>::Stack(int size) 
{
    this->size = size;
    array = new T[size];
    top=-1;
}

template<class T>
Stack<T>::~Stack() 
{
    delete[] array;
}

template<class T>
bool Stack<T>::isEmpty()
{
    bool out = false;
    if(top == -1)
    {
        cout << "Stack has nothing!" << endl;
        out = true;
    }
    return out;
}

template<class T>
bool Stack<T>::isFull()
{
    bool out = false;
    if(top == size-1)
    {
        cout << "Stack is Full!"<< endl;
        out = true;
    }
    return out;
}

template<class T>
void Stack<T>::push(T value)
{
    if(isFull())
        cout << "Stack Overflow!" << endl;
    else
    {
        top++;
        array[top] = value;
    }    
}

template<class T>
T Stack<T>::pop()
{
    T out = -1;
    if(isEmpty())
        cout << "Stack Underflow!" << endl;
    else
    {    
        out = array[top];
        top -= 1;
    }
    return out;
}

template<class T>
T Stack<T>::peek(int pos)
{
    int x = -1;
    if (top-pos+1 < 0 || top-pos+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = array[top-pos+1];
    }
    return x;
}

template<class T>
void Stack<T>::displayStack()
{
    for (int i=top; i>=0; i--)
    {
        cout << array[i] << " | " << flush;
    }
    cout << endl;    
}

template<class T>
T Stack<T>::StackTop()
{
    return array[top]; 
}

bool isBalanced(char *exp)
{
    Stack<char> stk(strlen(exp));
    char out;
    cout << "length of the string is : " << strlen(exp) << endl;
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            stk.push(exp[i]); 
        } 
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(!stk.isEmpty())
            {
                out =stk.pop();
                if(out == '(' && exp[i] != ')')
                    return false;
                if(out == '{' && exp[i] != '}')
                    return false;
                if(out == '[' && exp[i] != ']')
                    return false;
            }
            else
                return false;        
        }    
    }
    if(stk.isEmpty())
        return true;
    else
        return false;    
}


int main() 
{
 
    /*int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A)/sizeof(A[0]);
    cout<< "size of array is : " << size << endl;
    Stack<int> stk(size);

     // Populate Stack with array elements
    for (int i=0; i<size; i++)
    {
        stk.push(A[i]);
    }
    stk.push(11);
    

    cout << "Stack full: " << stk.isFull() << endl;
 
    // Display Stack;
    cout << "Stack: " << flush;
    stk.displayStack();
 
    // Peek
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;
 
    // Top element
    cout << "Top element: " << stk.StackTop() << endl;
 
    // Pop out elements from Stack
    cout << "Popped out elements: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();
 
    cout << "Stack empty: " << stk.isEmpty() << endl;*/

    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;
 
    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl;
 
    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;
 
    return 0;
}