#include <iostream>
using namespace std;
 
class Node
{
public:
    int data;
    Node* next;
};
 
class CircularLinkedList
{
private:
    Node* head;
public:
    CircularLinkedList() { head = NULL;};
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node* p);
    void create(int A[],int n);
    int Length(struct Node *p);
    void Insert(struct Node *p,int index, int x);
    int Delete(struct Node *p,int index);
    Node* getHead(){ return head; }
    ~CircularLinkedList();

    
};
 
CircularLinkedList::CircularLinkedList(int *A, int n) {
 
    Node* t;
    Node* tail;
 
    head = new Node;
 
    head->data = A[0];
    head->next = head;
    tail = head;
 
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}
 
void CircularLinkedList::Display() 
{
    Node* p = head;
    do 
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}
 
void CircularLinkedList::recursiveDisplay(Node *p) 
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}

void CircularLinkedList::create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head = new Node;
    head->data=A[0];
    head->next=head;
    last=head;
    
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
int CircularLinkedList::Length(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void CircularLinkedList::Insert(struct Node *p,int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index > Length(p))
        return;

    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
                p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
        t= new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int CircularLinkedList::Delete(struct Node *p,int index)
{
    struct Node *q;
    int i,x;

    if(index <0 || index >Length(head))
        return -1;
    if(index==1)
    {
        while(p->next!=head)
            p=p->next;
        x=head->data;
        if(head==p)
        {
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
 return x;
}
CircularLinkedList::~CircularLinkedList() 
{
    Node* p = head;
    while (p->next != head)
    {
        p = p->next;
    }
 
    while (p != head)
    {
        p->next = head->next;
        delete head;
        head = p->next;
    }
 
    if (p == head)
    {
        delete head;
        head = nullptr;
    }
 
}
 
 
int main() 
{
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));
 
    cl.Display();
 
    Node* h = cl.getHead();
    cl.recursiveDisplay(h);
    cout << "\n";

    CircularLinkedList cllist;
    int B[]={2,3,4,5,6};
    cllist.create(B,5);

    cllist.Display();

    cllist.Insert(cllist.getHead(),5,8);
    cllist.Display();

    cllist.Delete(cllist.getHead(),6);
    cllist.Display();
 
    return 0;
}
