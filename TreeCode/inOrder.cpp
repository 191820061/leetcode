#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

void inOrder(TreeNode<int> *root, vector<int> &res) {
    if (!root) {
        return;
    }
    inOrder(root->left, res);
    res.push_back(root->item);
    inOrder(root->right, res);
}

vector<int> inOrder(TreeNode<int> *root) {
    vector<int> res;
    inOrder(root, res);
    return res;
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(1);
    root->right = new TreeNode<int>(2);
    root->right->left = new TreeNode<int>(3);
    vector<int> result= inOrder(root);
    for (auto i = result.cbegin(); i !=result.cend() ; i++) {
        cout<<*i<<endl;
    }
}