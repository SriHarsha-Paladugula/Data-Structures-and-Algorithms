#include<iostream>
#include<stdint.h>
#include "circular_queue.h"
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
class Tree
{
    Node<T> *root;
    
    public:
        Tree(){root = nullptr;}
        void create();
        void PreOrderDisplay(Node<T>* p);
        void InOrderDisplay(Node<T>* p);
        void PostOrderDisplay(Node<T>* p);
        void IPreOrderDisplay(Node<T>* p);
        void IInOrderDisplay(Node<T>* p);
        void IPostOrderDisplay(Node<T>* p);
        void LevelOrderDisplay();
        int Count(Node<T>* p);
        int Height(Node<T>* p);
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

template<class T>
void Tree<T>::IPreOrderDisplay(Node<T>* p)
{
    StackLL<Node<T>*> st;
    while(p != nullptr || !st.isEmpty())
    {
        if(p)
        {
            cout << p->data << ", " << flush;
            st.push(p);
            p = p->left_node;
        }
        else
        {
            p = st.pop();
            p = p->right_node;
        }
    }
}

template<class T>
void Tree<T>::IInOrderDisplay(Node<T>* p)
{
    StackLL<Node<T>*> st;
    while(p != nullptr || !st.isEmpty())
    {
        if(p)
        {
            st.push(p);
            p = p->left_node;
            
        }
        else
        {
            p = st.pop();
            cout << p->data << ", " << flush;
            p = p->right_node;
        }
    }
}

template<class T>
void Tree<T>::IPostOrderDisplay(Node<T>* p)
{
    StackLL<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.isEmpty())
    {
        if (p != nullptr)
        {
            stk.push(reinterpret_cast<intptr_t>(p));
            p = p->left_node;
        } 
        else 
        {
            temp = stk.pop();
            if (temp > 0)
            {
                stk.push(-temp);
                p = ((Node<T>*)temp)->right_node;
            } 
            else 
            {
                cout << ((Node<T>*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

template<class T>
int Tree<T>::Count(Node<T>* p)
{
    if(p)
        return Count(p->left_node)+Count(p->right_node)+1;
    return 0;    
}

template<class T>
int Tree<T>::Height(Node<T>* p)
{
    int x,y;
    if(p == nullptr)
        return 0;
    x = Height(p->left_node);
    y = Height(p->right_node);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main() {
 
    Tree<int> bt;
 
    bt.create();
    cout << endl;
 
    Node<int>* root = bt.Getroot();

    cout << "Preorder: " << flush;
    bt.PreOrderDisplay(root);
    cout << "IPreorder: " << flush;
    bt.IPreOrderDisplay(root);
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.InOrderDisplay(root);
    cout << "IInorder: " << flush;
    bt.IInOrderDisplay(root);
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.PostOrderDisplay(root);
    cout << "IPostorder: " << flush;
    bt.IPostOrderDisplay(root);
    cout << endl;
 
    cout << "Levelorder: " << flush;
    bt.LevelOrderDisplay();
    cout << endl;

    cout << "No of nodes in this tree is : " << bt.Count(root) << endl;

    cout << "Height this tree is : " << bt.Height(root) << endl;
 
    //cout << "Height: " << bt.Height() << endl;
 
    return 0;
}