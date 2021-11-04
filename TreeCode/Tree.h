//
// Created by 13047 on 2021/10/31.
//

#ifndef TREECODE_TREE_H
#define TREECODE_TREE_H
template<class T>
struct TreeNode {
    T item;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T item, TreeNode<T> *left, TreeNode<T> *right) : item(item), left(left), right(right) {}

    TreeNode(T items) : TreeNode(items, nullptr, nullptr) {}
};

template <class T>
class Tree{
private:
    TreeNode<T>* root;
public:
    explicit Tree(T value);
    TreeNode<T>* insert(T item){
        insert(root,item);
    }

private:
    TreeNode<T>* insert(TreeNode<T>* node,T item);
};

template<class T>
Tree<T>::Tree(T value){
    root = new TreeNode<T>(value);
}

template<class T>
TreeNode<T>* Tree<T>::insert(TreeNode<T>* node,T item){
    if (node==nullptr){
        return new TreeNode<T>(item);
    }
    if (node->left==nullptr){
        node->left=insert(node->left,item);
    }else if(node->right==nullptr){
        node->right=insert(node->right,item);
    }
    return node;
}
#endif //TREECODE_TREE_H
