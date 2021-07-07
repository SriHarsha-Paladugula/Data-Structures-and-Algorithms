#include <iostream>
using namespace std;

template<typename T>
class CircularQueue
{
    int size;
    int front;
    int rear;
    T *array;

    public:
    CircularQueue();
    CircularQueue(int size)
    {
        this->size = size;
        front = rear = 0;
        array = new T[this->size];
    }
    ~CircularQueue()
    {
        delete []array;
    }
    void enqueue(T value);
    T dequeue();
    void display();
    bool isFull();
    bool isEmpty(); 
};

template<class T>
bool CircularQueue<T>::isEmpty()
{
    if(rear == front)
        return true;
    return false;    
}

template<class T>
bool CircularQueue<T>::isFull()
{
    if((rear+1)%size == front)
        return true;
    return false;    
}

template<class T>
void CircularQueue<T>::enqueue(T value)
{
    if(isFull())
        cout<<"Queue is Full"<<endl;
    else
    {
        rear = (rear+1)%size;
        array[rear] = value;
    }    
}

template<class T>
T CircularQueue<T>::dequeue()
{
    T temp;
    if(isEmpty())
        cout<<"Queue is Empty"<<endl;
    else
    {
        front = (front+1)%size;
        temp = array[front];
        array[front] = NULL;
    }
    return temp;    
}

template<class T>
void CircularQueue<T>::display() 
{
    int i = front + 1;
    do {
        cout << array[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue<int> cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
 
    // Display
    cq.display();
    cout << endl;
 
    // Overflow
    cq.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
 
    // Underflow
    cq.dequeue();
    return 0;
}