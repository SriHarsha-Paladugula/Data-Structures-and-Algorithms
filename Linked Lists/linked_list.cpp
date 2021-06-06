#include <iostream>
#include <limits>
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
        int getsize();
        void insert(int pos, T value);
        void reverse();
        void deleteNode(int Pos);
        T Max();
        T Min();
        T Sum();
        T at(int pos);
        void insertInSortedLinkedList(T value);
        bool isSorted();
        void deleteDuplicateInSortedLinkedList();

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
int linked_list<T>::getsize()
{
    cout<< "Size of linked_list is : "<< size <<endl;
    return size;
}

template <class T>
void linked_list<T>::insert(int pos, T value)
{
    Node<T> *temp = head;
    Node<T> *new_node = new Node<T>;

    if(pos > size+1)
        cout << "Insertion is not possible since size of linked list is only " << size << endl;

    if (pos == 1)
    {
        new_node->data = value;
        new_node->next_node = head;
        head = new_node;
        size += 1;
    }

    else
    {
        for (int i=2; i<=size+1; i++)
        {
            if(i == pos)
            {
                new_node->data = value;
                new_node->next_node = temp->next_node;
                temp->next_node = new_node;
                if (i == size+1)
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
    Node<T> *current = head;
    int current_pos =1;

    if (pos < 1 || pos > size) 
        return;

    if(pos ==1)
    {
        head = head->next_node;
        delete current;
    }
    else
    {
        Node<T> *prev;
        while(current_pos < pos)
        {
            prev = current;
            current =  current->next_node;
            current_pos++;
        }

        prev->next_node = current->next_node;
        current->next_node = nullptr;
        size = size -1;
        if (prev->next_node == nullptr)
            tail = prev;
        delete current;
    }
    
}

template <class T>
T linked_list<T>::Max()
{
    Node<T> *temp = head;
    T max_val = std::numeric_limits<T>::min();
    while (temp)
    {
        if(temp->data > max_val)
            max_val = temp->data;
        temp = temp->next_node;    
    }
    return max_val;
}

template <class T>
T linked_list<T>::Min()
{
    Node<T> *temp = head;
    T min_val = std::numeric_limits<T>::max();
    while (temp)
    {
        if(temp->data < min_val)
            min_val = temp->data;
        temp = temp->next_node;    
    }
    return min_val;
}

template <class T>
T linked_list<T>::Sum()
{
    Node<T> *temp = head;
    T sum = 0;
    while (temp)
    {
        sum += temp->data;
        temp = temp->next_node;    
    }
    return sum;
}

template <class T>
T linked_list<T>::at(int pos)
{
    Node<T> *temp = head;
    int current_pos =1;
    if(pos > size)
    {
        cout << "linked list only have " << size << "elements inside it" << endl;
        return size;
    }
    else
    {
        while(current_pos != pos)
        {
            current_pos++;
            temp = temp->next_node;
        }
        return temp->data;
    }
}

template <class T>
void linked_list<T>::insertInSortedLinkedList(T value)
{
    Node<T> *current = head;
    Node<T> *prev = nullptr;

    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next_node = nullptr;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        if(head->data > value)
        {
            temp->next_node = head;
            tail = head;
            head = temp;
        }
        else
        {
            while(current && current->data < value)
            {
                prev = current;
                current = current->next_node;
            }

            temp->next_node = prev->next_node;
            prev->next_node = temp;
        }
    }
    size += 1;
    if(temp->next_node == nullptr)
        tail = temp;
}

template <class T>
bool linked_list<T>::isSorted()
{
    Node<T> *temp = head;
    while(temp->next_node)
    {
        if(temp->data > temp->next_node->data)
            return false;
        temp = temp->next_node;    
    }
    return true;
}

template <class T>
void linked_list<T>::deleteDuplicateInSortedLinkedList()
{
    Node<T> *temp = head;
    int pos =1;
    while(temp->next_node)
    {
        if(temp->data == temp->next_node->data)
        {
            deleteNode(pos+1);
            pos--;
        }
        else
            temp = temp->next_node;
        pos++;    
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

    cout<<"Display insertion of new node at some middle position in linked list:"<<endl;
    llist.insert(5,5);
    llist.display_head();
    llist.display_tail();
    llist.display_all();
    llist.getsize();

    cout<<"Display insertion of new node at tail position in linked list:"<<endl;
    llist.insert(9,9);
    llist.display_head();;
    llist.display_tail();
    llist.display_all();
    llist.getsize();

    cout<<"Display insertion of new node at head position in linked list:"<<endl;
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

    cout << "Maximim value in the linked list is : " << llist.Max() << endl;
    cout << "Minimum value in the linked list is : " << llist.Min() << endl;
    cout << "Sum of all the elements in linked list is : " << llist.Sum() << endl;

    int size = llist.getsize();
    for(int i=1; i <= size; i++)
    {
        cout << "The "<< i << " element inside this linked list is : " << llist.at(i) << endl;
    }

    cout<<"Display Reverse of the linked list:"<<endl;
    llist.reverse();
    llist.display_head();
    llist.display_tail();
    llist.display_all();

    cout<<"Display insertion of new node at tail position in linked list:"<<endl;
    llist.insert(11,10);
    llist.display_head();
    llist.display_tail();
    llist.display_all();

    cout<<"Display deletion of First node  in linked list:"<<endl;
    llist.deleteNode(1);
    llist.display_head();
    llist.display_tail();
    llist.display_all();

    cout<<"Display deletion of middle node  in linked list:"<<endl;
    llist.deleteNode(5);
    llist.display_head();
    llist.display_tail();
    llist.display_all();

    cout<<"Display deletion of end node  in linked list:"<<endl;
    llist.deleteNode(9);
    llist.display_head();
    llist.display_tail();
    llist.display_all();

    cout<<"Display insertion of a node if sorted linked list is empty:"<<endl;
    linked_list<int> llist2;
    llist2.insertInSortedLinkedList(1);
    llist2.display_head();
    llist2.display_tail();
    llist2.display_all();

    cout<<"Display insertion of a node at the start of  in sorted linked list:"<<endl;
    llist2.insertInSortedLinkedList(2);
    llist2.display_head();
    llist2.display_tail();
    llist2.display_all();

    cout<<"Display insertion of a node at the middle of  in sorted linked list:"<<endl;
    llist2.insertInSortedLinkedList(5);
    llist2.display_head();
    llist2.display_tail();
    llist2.display_all();

    cout<<"Display insertion of a node at the end of  in sorted linked list:"<<endl;
    llist2.insertInSortedLinkedList(10);
    llist2.display_head();
    llist2.display_tail();
    llist2.display_all();

    //llist2.add(0);
    llist2.insertInSortedLinkedList(0);
    llist2.display_head();
    llist2.display_tail();
    llist2.display_all();

    cout<<"check is this a sorted linked list:"<<endl;
    if(llist2.isSorted())
       cout << "This linked list is sorted" << endl;
    else
       cout << "This linked list is not sorted" << endl;
    cout << "Display deletion of duplicate nodes in sorted linked list" << endl;
    linked_list<int> llist3;
    llist3.add(0);
    llist3.add(1);
    llist3.add(1);
    llist3.add(2);
    llist3.add(2);
    llist3.add(2);
    llist3.add(3);
    llist3.add(4);
    llist3.add(4);
    llist3.add(4);
    llist3.add(4);
    llist3.add(5);
    llist3.display_head();
    llist3.display_tail();
    llist3.display_all();
    llist3.deleteDuplicateInSortedLinkedList();
    cout << "After deletion of duplicate nodes in sorted linked list" << endl;
    llist3.display_head();
    llist3.display_tail();
    llist3.display_all();



}
