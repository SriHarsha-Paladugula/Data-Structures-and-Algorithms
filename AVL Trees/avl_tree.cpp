#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    Node<T>* left_node;
    Node<T>* right_node;
    int height;
    T data;
};

template <typename T>
class AVL
{
    public:
        Node<T>* root;
        AVL(){root = nullptr;};
        ~AVL(){delete root;};
        int NodeHeight(Node<T>* p);
        int BalanceFactor(Node<T>* p);
        Node<T>* LLRotation(Node<T>* p);
        Node<T>* RRRotation(Node<T>* p);
        Node<T>* LRRotation(Node<T>* p);
        Node<T>* RLRotation(Node<T>* p);
    
        // Insert
        Node<T>* RInsert(Node<T>* p, int key);
    
        // Traversal
        void Inorder(Node<T>* p);
        void Inorder(){ Inorder(root); }
        Node<T>* getRoot(){ return root; }
};

template <typename T>
int AVL<T>::NodeHeight(Node<T>* p)
{
    int hl=0,hr=0;
    hl = p && p->left_node ? p->left_node->height : 0;
    hr = p && p->right_node ? p->right_node->height : 0;
    
    return hl>hr?hl+1:hr+1;
}

template <typename T>
int AVL<T>::BalanceFactor(Node<T>* p)
{
    int hl=0,hr=0;
    hl = p && p->left_node ? p->left_node->height : 0;
    hr = p && p->right_node ? p->right_node->height : 0;
    
    return hl-hr;
}

template <typename T>
Node<T>* AVL<T>::LLRotation(Node<T>* p)
{
    Node<T>* pl = p->left_node;
    Node<T>* plr = pl->right_node;

    pl->right_node = p;
    p->left_node = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
 
    // Update root
    if (root == p){
        root = pl;
    }

    return pl;    
}

template <typename T>
Node<T>* AVL<T>::LRRotation(Node<T>* p)
{
    Node<T>* pl = p->left_node;
    Node<T>* plr = pl->right_node;

    p->left_node = plr->right_node;
    pl->right_node = plr->left_node;
    plr->left_node = pl;
    plr->right_node = p;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if root == p
        root = plr;

    return plr;
}

template <typename T>
Node<T>* AVL<T>::RRRotation(Node<T>* p)
{
    Node<T>* pr = p->right_node;
    Node<T>* prl = pr->left_node;

    pr->left_node = p;
    p->right_node = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
 
    // Update root
    if (root == p){
        root = pr;
    }

    return pr;
}

template <typename T>
Node<T>* AVL<T>::RLRotation(Node<T>* p)
{
    Node<T>* pr = p->right_node;
    Node<T>* prl = pr->left_node;

    p->right_node = prl->left_node;
    pr->left_node = prl->right_node;
    prl->right_node = pr;
    prl->left_node = p;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if root == p
        root = prl;

    return prl;
}

template <typename T>
Node<T>* AVL<T>::RInsert(Node<T>* p, int key)
{
    if(p==nullptr)
    {
        Node<T>* temp = new Node<T>;
        temp->data = key;
        temp->left_node = nullptr;
        temp->right_node = nullptr;
        temp->height = 1;
        return temp;
    }

    if(key < p->data)
        p->left_node = RInsert(p->left_node, key);
    else if (key > p->data)
        p->right_node = RInsert(p->right_node, key);

    //update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->left_node)==1)
        return LLRotation(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->left_node)==-1)
        return LRRotation(p);
    if(BalanceFactor(p) == -2 && BalanceFactor(p->right_node)==1)
        return RLRotation(p);
    if(BalanceFactor(p) == -2 && BalanceFactor(p->right_node)==-1)
        return RRRotation(p);                    
    
    return p;
}

template <typename T>
void AVL<T>::Inorder(Node<T>* p)
{
    if(p)
    {
        Inorder(p->left_node);
        cout << p->data << ", " << flush;
        Inorder(p->right_node);
    }
}

int main()
{
    // LL Rotation
    AVL<int> tll;
    tll.root = tll.RInsert(tll.root, 30);
    tll.root = tll.RInsert(tll.root, 20);
    tll.root = tll.RInsert(tll.root, 10);
 
    tll.Inorder();
    cout << endl;
    return 0;
}