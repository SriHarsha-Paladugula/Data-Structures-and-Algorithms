#include <iostream>
#include "stack.h"
using namespace std;

template<typename T>
struct Node
{
    Node* left_node;
    T data;
    Node* right_node;
};

template<typename T>
class BST
{
    Node<T>* root;

    public:
        BST(){root = nullptr;}
        Node<T>* getRoot(){return root;}
        void setRoot(Node<T>* p){root = p;}
        void Insert(T key);
        Node<T>* RInsert(T key, Node<T>* p);
        void InOrder(Node<T>* p);
        void RInOrder(Node<T>* p );
        void Search(T key);
        void RSearch(T key, Node<T>* p);
        Node<T>* Delete(T key, Node<T>*p);
        int Height(Node<T>* p);
};

template<typename T>
void BST<T>::Insert(T key)
{
    Node<T>* temp = root;
    Node<T>* p;
    Node<T>* r;

    // if root is empty
    if (root == nullptr)
    {
        p = new Node<T>;
        p->data = key;
        p->left_node = nullptr;
        p->right_node = nullptr;
        root = p;
        return;
    }

    //check if the key exists and if it exits don't insert
    while(temp != nullptr)
    {
        r = temp;
        if (key < temp->data)
            temp = temp->left_node;
        else if (key > temp->data)
            temp = temp->right_node;
        else
            return;    
    }

    p = new Node<T>;
    p->data = key;
    p->left_node = nullptr;
    p->right_node = nullptr;

    if(key > r->data)
        r->right_node = p;
    else
        r->left_node = p;    
}

template<typename T>
Node<T>* BST<T>::RInsert(T key, Node<T>* p)
{
    if( p == nullptr)
    {
        Node<T>* temp = new Node<T>;
        temp->data = key;
        temp->left_node = nullptr;
        temp->right_node = nullptr;
        return temp;
    }

    if(key > p->data)
        p->right_node = RInsert(key, p->right_node);
    else if (key < p->data)
        p->left_node = RInsert(key, p->left_node);

    return p;        
}

template<typename T>
void BST<T>::InOrder(Node<T>* p )
{
    StackLL<Node<T>*> s;
    while (p != nullptr || !s.isEmpty())
    {
        if(p)
        {
            s.push(p);
            p = p->left_node;
        }
        else
        {
            p = s.pop();
            cout << p->data << ", " << flush;
            p = p->right_node;
        }
    }
}

template<typename T>
void BST<T>::RInOrder(Node<T>* p)
{
    if (p)
    {
        RInOrder(p->left_node);
        cout << p->data << " ," << flush;
        RInOrder(p->right_node);
    }
}

template<typename T>
void BST<T>:: Search(T key)
{
    Node<T>* p = root;
    while(p)
    {
        if(p->data == key)
        {
            cout << "Element is present" << endl;
            return;
        }
        else if(key > p->data)
            p = p->right_node;
        else
            p = p->left_node;        
    }
}

template<typename T>
void BST<T>::RSearch(T key, Node<T>* p)
{
    if (p == nullptr)
    {
        return;
    }
    if(p->data == key)
    {
        cout << "Element is Present" << endl;
        return;
    }
    else if (key > p->data)
        RSearch(key, p->right_node);
    else
        RSearch(key, p->left_node);    
        
}

template<typename T>
Node<T>* InPre(Node<T>* p)
{
    while(p != nullptr && p->right_node != nullptr)
        p = p->right_node;
    return p;    
}

template<typename T>
Node<T>* InSucc(Node<T>* p)
{
    while(p != nullptr && p->left_node != nullptr)
        p = p->left_node;
    return p;    
}

template<typename T>
int BST<T>::Height(Node<T>*p)
{
    int x,y=0;
    if(p==nullptr)
        return 0;
    Height(p->left_node);    
    Height(p->right_node);

    return x > y ? x+1: y+1;    
}

template<typename T>
Node<T>* BST<T>::Delete(T key, Node<T>*p)
{
    if(p == nullptr)
        return p;
    if(p->left_node == nullptr && p->right_node == nullptr)
    {
        if(p==root)
            root = nullptr;
        delete p;
        return nullptr;
    }    
    if(key > p->data)
        p->right_node = Delete(key, p->right_node);
    else if (key < p->data)
        p->left_node = Delete(key, p->left_node);
    else
    {
        Node<T>* q;
        if(Height(p->left_node) > Height(p->right_node))
        {
            q = InPre(p->left_node);
            p->data = q->data;
            p->left_node = Delete(q->data, p->left_node);
        }
        else
        {
            q = InSucc(p->right_node);
            p->data = q->data;
            p->right_node = Delete(q->data, p->right_node);
        }
    
    }
    return p;        
}

int main()
{
     BST<int> bst;
 
    // Iterative insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
 
    // Inorder traversal
    bst.InOrder(bst.getRoot());
    cout << endl;
 
    // Iterative search
    bst.RSearch(2, bst.getRoot());
 
    // Recursive search
    bst.RSearch(20, bst.getRoot());
   
 
    // Recursive insert
    bst.RInsert(50, bst.getRoot());
    bst.RInsert(70, bst.getRoot());
    bst.RInsert(1, bst.getRoot());
    bst.InOrder(bst.getRoot());
    cout << "\n" << endl;
 
    // InOrder predecessor and InOrder successor
    BST<int> bs;
    bs.Insert(5);
    bs.Insert(2);
    bs.Insert(8);
    bs.Insert(7);
    bs.Insert(9);
    bs.Insert(1);
    
    bs.InOrder(bs.getRoot());
    cout << endl;

    Node<int>* temp;
    temp = InPre(bs.getRoot());
    cout << "InPre: " << temp->data << endl;
 
    temp = InSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;
 
    // Delete
    bs.Delete( 7, bs.getRoot());
    bs.InOrder(bs.getRoot());
    
    return 0;
}