#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrder(vector<int> &res, TreeNode *root) {
    if (!root) {
        return;
    }
    inOrder(res, root->left);
    res.push_back(root->val);
    inOrder(res, root->right);
}

void preOrder(vector<int> &res, TreeNode *root){
    if (!root){
        return;
    }
    res.push_back(root->val);
    preOrder(res,root->left);
    preOrder(res,root->right);
}

void postOrder(vector<int> &res, TreeNode *root){
    if (!root){
        return;
    }
    postOrder(res,root->left);
    postOrder(res,root->right);
    res.push_back(root->val);
}

int main() {
    vector<int> res;
    auto *node = new TreeNode(1);
    node->right=new TreeNode(2);
    node->right->left=new TreeNode(3);
    inOrder(res, node);
    for (int re : res){
        cout<<re<<endl;
    }
}