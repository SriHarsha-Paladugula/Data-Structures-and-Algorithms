#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node *next_node;
};

template <class T> 
class linked_list
{
    private:
        /* data */
        Node<T> *head, *tail;
        int size;

    public:

        linked_list()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        };

        void add(T value);
        void display_head();
        void display_tail();
        void display_all();
        void getsize();
        void insert(int pos, T value);
        void reverse();
        void deleteNode(int Pos);

        ~linked_list(){};

};

template <class T>
void linked_list<T>::add(T value)
{
    Node<T> *temp = new Node<T>;
    temp->next_node = NULL;
    temp->data = value;
    if (head==NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next_node = temp;
        tail = tail->next_node;
    }
    size += 1;
}

template <class T>
void linked_list<T>::display_head()
{
    if(head == NULL)
        cout<< "Linked List is empty" <<endl;
    else    
        cout<< "head is : " << head->data <<endl;
}

template <class T>
void linked_list<T>::display_tail()
{
    if(head == NULL)
        cout<< "Linked List is empty" <<endl;
    else    
        cout<<"tail is : " << tail->data <<endl;
}

template <class T>
void linked_list<T>::display_all()
{
    if(head == NULL)
        cout<< "Linked List is empty" <<endl;
    else
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
           cout<< temp->data <<" ";
           temp = temp->next_node;
        }
        cout<<"\n";
    }    
}

template <class T>
void linked_list<T>::getsize()
{
    cout<< "Size of linked_list is : "<< size <<endl;
}

template <class T>
void linked_list<T>::insert(int pos, T value)
{
    Node<T> *temp = head;
    Node<T> *new_node = new Node<T>;

    if (pos == 1)
    {
        new_node->data = value;
        new_node->next_node = head;
        head = new_node;
        size += 1;
    }

    else
    {
        for (int i=2; i<=size; i++)
        {
            if(i == pos-1)
            {
                new_node->data = value;
                new_node->next_node = temp->next_node;
                temp->next_node = new_node;
                if (i == size)
                    tail = new_node;
                size += 1;    
            }
            temp = temp->next_node;
        }
    }
}

template <class T>
void linked_list<T>::reverse()
{
    Node<T> *prev = NULL;
    Node<T> *current = head;
    Node<T> *next = NULL;

    while(current)
    {
        next = current->next_node;
        current->next_node = prev;
        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}

template <class T>
void linked_list<T>::deleteNode(int pos)
{
    Node<T> *temp = head;

    if(pos ==1)
    {
        head = head->next_node;
        free(temp);
    }
    else
    {
        for(int i=2; i<=size; i++)
        {
            if(pos == i)
            {
                temp->next_node = temp->next_node->next_node;
                free(temp->next_node);
            }
            
            temp = temp->next_node;
        }
    }
    
}
int main()
{
    linked_list<int> llist;
    llist.display_head();
    llist.add(1.6);
    llist.add(2.4);
    llist.add(3);
    llist.add(4);
    //llist.add(5);
    llist.add(6);
    llist.add(7);
    llist.add(8.64);
    llist.display_head();
    llist.display_tail();
    llist.display_all();
    llist.getsize();
    llist.insert(5,5);
    llist.display_head();
    llist.display_tail();
    llist.display_all();
    llist.getsize();
    llist.insert(9,9);
    llist.display_head();;
    llist.display_tail();
    llist.display_all();
    llist.getsize();

    cout<<"Display insertion of new node at head position linked list:"<<endl;
    llist.insert(1,0);
    llist.display_head();
    llist.display_tail();
    llist.display_all();
    llist.getsize();
    
    cout<<"Display Reverse of the linked list:"<<endl;
    llist.reverse();
    llist.display_head();
    llist.display_tail();
    llist.display_all();
}
