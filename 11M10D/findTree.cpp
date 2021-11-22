template<class T>
struct Node {
    T item;
    Node<T> *next;
    Node<T> *prev;

    Node<T>(T value, Node<T> *p, Node<T> *n) : item(value), prev(p), next(n) {};

    Node<T>(T value, Node<T> *n) : item(value), prev(nullptr), next(n) {};

    Node<T>(T value) : item(value), prev(nullptr), next(nullptr) {};
};

template<class T>
class LinkDeque {
private:
    int size;
    Node<T> *sentinel;

public:
    LinkDeque(T value) {
        sentinel = new Node<T>(value);
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }


    void addFirst(T value) {
        sentinel->next = new Node<T>(value, sentinel->next);
        sentinel->next->prev = sentinel;
        sentinel->next->next->prev = sentinel->next;
        size++;
    }

    T removeFirst() {
        size--;
        T item = sentinel->next->item;
        sentinel->next->next->prev = sentinel;
        sentinel->next = sentinel->next->next;
        return item;
    }

    T getFirst() {
        return sentinel->next->item;
    }


    void addLast(T value) {
        size++;
        sentinel->prev->next = new Node<T>(value, sentinel);
        sentinel->prev->next->prev = sentinel->prev;
        sentinel->prev = sentinel->prev->next;
    }

    T removeLast() {
        size--;
        T item = sentinel->prev->item;
        sentinel->prev = sentinel->prev->prev;
        sentinel->prev->next = sentinel;
        return item;
    }

    T getLast() {
        return sentinel->prev->item;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }
};
#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : value(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
};

int indexs = 0;

TreeNode *creat_tree(TreeNode *node, int *c) {
    int element = c[indexs++];
    if (element == -1) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(element);
    root->left = creat_tree(node, c);
    root->right = creat_tree(node, c);
    return root;
}

TreeNode *find_element(TreeNode *root, int p, int q) {
    LinkDeque<TreeNode *> deque(new TreeNode(-1));
    deque.addFirst(root);
    bool array[2]= {false,false};
    while (!deque.empty()) {
        TreeNode *node = deque.getLast();
        if (node->value==p){
            array[0]= true;
        }
        if (node->value==q){
            array[1]= true;
        }
        if (array[0]&&array[1]){
            return root;
        }
        deque.removeLast();
        if (node->left != nullptr) {
            deque.addFirst(node->left);
        }
        if (node->right != nullptr) {
            deque.addFirst(node->right);
        }
    }
    return nullptr;
}

TreeNode *find(TreeNode *root, int p, int q) {
    TreeNode *left = find_element(root->left, p, q);
    TreeNode *right = find_element(root->right, p, q);
    if (left == nullptr && right == nullptr) {
        return root;
    } else if (right == nullptr) {
        return find(root->left, p, q);
    } else {
        return find(root->right, p, q);
    }
}

int main(){
    int c=0;
    int array[20000];
    int index=0;
    while (cin.peek()!='\n'){
        cin>>c;
        array[index++]=c;
    }
    int p;int q;
    cin>>p>>q;
    TreeNode* root= nullptr;
    root=creat_tree(root,array);
    cout<<find(root,p,q)->value;
}

