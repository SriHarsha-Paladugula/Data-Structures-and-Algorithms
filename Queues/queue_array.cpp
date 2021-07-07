#include <iostream>
using namespace std;

template<typename T>
class Queue
{
    int size;
    int front;
    int rear;
    T *array;

    public:
    Queue();
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        array = new T[size]; 
    }
    ~Queue()
    {
        delete[] array;
    }
    void enqueue(T value);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

template<class T>
bool Queue<T>::isEmpty()
{
    if(front == rear)
        return true;
    return false;    
}

template<class T>
bool Queue<T>::isFull()
{
    if(rear == size-1)
        return true;
    return false;    
}

template<class T>
void Queue<T>::enqueue(T value)
{
    //check for condition if queue is full
    if(isFull())
        cout << "Queue is Full" << endl;
    else
    {
        rear++;
        array[rear] = value;
    }    
}

template<class T>
T Queue<T>::dequeue()
{
    T temp;
    //check fr condition if queue is empty
    if(isEmpty())
        cout<<"Queue is empty"<<endl;
    else
        front++;
        temp = array[front];
        array[front] = NULL;
    return temp;        
}

template<class T>
void Queue<T>::display()
{
    for(int i=front+1; i<=rear; i++)
    {
        cout << array[i] << " ";
    }
    cout<<"\n";
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    int size = sizeof(A)/sizeof(A[0]);
    cout << "size is : " << size << endl;

    Queue<int> q(size);
 
    // Enqueue
    for (int i=0; i<size; i++)
    {
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
    q.display();
 
    // Dequeue
    for (int i=0; i<size; i++){
        q.dequeue();
    }
 
    // Underflow
    q.dequeue();
    return 0;
}