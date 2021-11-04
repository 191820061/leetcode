#include <iostream>
#include "Tree.h"

using namespace std;

bool helper(TreeNode<int> *root,int lower,int higher) {
    if (root== nullptr){
        return true;
    }
    if (root->item<=lower||root->item>=higher){
        return false;
    }
    return helper(root->left,lower, root->item)&& helper(root->right,root->item,higher);
}

bool isValidBST(TreeNode<int> *root){
    return helper(root,LONG_MIN,LONG_MAX);
}


int main() {
    TreeNode<int> *root=new TreeNode<int>(5);
    root->left=new TreeNode<int>(1);
    root->right=new TreeNode<int>(4);
    root->right->left=new TreeNode<int>(3);
    root->right->right=new TreeNode<int>(6);
    cout<<LONG_MAX<<endl;
}