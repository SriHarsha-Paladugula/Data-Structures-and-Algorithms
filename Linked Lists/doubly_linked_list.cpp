#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    /* data */
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template<class T>
class DoublyLinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int size;

    public:
    DoublyLinkedList() 
    {
        head=nullptr; 
        tail=nullptr; 
        size=0;
    }

    void add(T value);
    void display_head();
    void display_tail();
    void display_all();
    int getsize();
    void insert(int pos, T value);
    void reverse();
    void deleteNode(int Pos);
};

template<class T>
void DoublyLinkedList<T>::add(T value)
{
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size+=1;
}

template<class T>
void DoublyLinkedList<T>::display_head()
{
    if(head == NULL)
        cout<< "Doubly Linked List is empty" <<endl;
    else    
        cout<< "head is : " << head->data <<endl;
}

template <class T>
void DoublyLinkedList<T>::display_tail()
{
    if(head == NULL)
        cout<< "Doubly Linked List is empty" <<endl;
    else    
        cout<<"tail is : " << tail->data <<endl;
}

template <class T>
void DoublyLinkedList<T>::display_all()
{
    if(head == NULL)
        cout<< "Linked List is empty" <<endl;
    else
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
           cout<< temp->data <<" ";
           temp = temp->next;
        }
        cout<<"\n";
    }    
}

template <class T>
int DoublyLinkedList<T>::getsize()
{
    return size;
}

int main()
{
    DoublyLinkedList<int> dll;
    dll.display_head();
    dll.display_tail();
    dll.display_all();

    dll.add(5);
    dll.add(4);
    dll.add(3);

    dll.display_head();
    dll.display_tail();
    dll.display_all();
    cout << "size of doubly linked list is : " << dll.getsize() << endl;;
    return 0;
}