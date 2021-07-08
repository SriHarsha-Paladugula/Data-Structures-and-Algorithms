#include<iostream>
#include "circular_queue.h"
using namespace std;

template<typename T>
struct Node
{
    Node* left_node;
    T data;
    Node* right_node;
};

template<typename T>
class Tree
{
    Node<T> *root;
    
    public:
        Tree(){root = nullptr;}
        void create();
        void PreOrderDisplay(Node<T>* p);
        void InOrderDisplay(Node<T>* p);
        void PostOrderDisplay(Node<T>* p);
        void LevelOrderDisplay();
        void Height();
        Node<T>* Getroot(){return root;};
};

template<typename T>
void Tree<T>::create()
{
    Node<T> *p, *temp;
    T x;
    CircularQueue<Node<T>*> q(100);

    cout<<"Enter root value"<<endl;
    
    root = new Node<T>;
    cin >> x;
    root->data = x;
    root->left_node = root->right_node = nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "enter the left child of " << p->data << endl;
        cin >> x;

        if(x != -1)
        {
            temp = new Node<T>;
            temp->data = x;
            temp->left_node = temp->right_node = nullptr;
            p->left_node = temp;
            q.enqueue(temp);
        }

        cout << "enter the right child of " << p->data << endl;
        cin >> x;

        if(x != -1)
        {
            temp = new Node<T>;
            temp->data = x;
            temp->left_node = temp->right_node = nullptr;
            p->right_node = temp;
            q.enqueue(temp);
        }
    }  
}

template<typename T>
void Tree<T>::PreOrderDisplay(Node<T>* p)
{
    if(p)
    {
        cout << p->data << ", " <<flush;
        PreOrderDisplay(p->left_node);
        PreOrderDisplay(p->right_node);
    }
}

template<typename T>
void Tree<T>::InOrderDisplay(Node<T>* p)
{
    if(p)
    {
        InOrderDisplay(p->left_node);
        cout << p->data << ", " <<flush;
        InOrderDisplay(p->right_node);
    }
}

template<typename T>
void Tree<T>::PostOrderDisplay(Node<T>* p)
{
    if(p)
    {
        PostOrderDisplay(p->left_node);
        PostOrderDisplay(p->right_node);
        cout << p->data << ", " <<flush;
    }
}

template<typename T>
void Tree<T>::LevelOrderDisplay()
{
    CircularQueue<Node<T>*> q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        Node<T>* p = q.dequeue();
        if(p->left_node)
        {
            cout<<p->left_node->data<<", "<<flush;
            q.enqueue(p->left_node);
        }
        if(p->right_node)
        {
            cout<<p->right_node->data<<", "<<flush;
            q.enqueue(p->right_node);
        }
    }
}

int main() {
 
    Tree<int> bt;
 
    bt.create();
    cout << endl;
 
    Node<int>* root = bt.Getroot();

    cout << "Preorder: " << flush;
    bt.PreOrderDisplay(root);
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.InOrderDisplay(root);
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.PostOrderDisplay(root);
    cout << endl;
 
    cout << "Levelorder: " << flush;
    bt.LevelOrderDisplay();
    cout << endl;
 
    //cout << "Height: " << bt.Height() << endl;
 
    return 0;
}