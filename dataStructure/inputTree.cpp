#include <iostream>
#include <queue>
#include "Deque.h"
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : value(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
};

int max(const int *nums, int l, int r) {
    int maxIndex = l;
    for (int i = l; i < r; i++) {
        if (nums[maxIndex] < nums[i])
            maxIndex = i;
    }
    return maxIndex;
}

TreeNode *construct(int *nums, int l, int r) {
    if (l == r)
        return new TreeNode(-1);
    int maxIndex = max(nums, l, r);
    auto *root = new TreeNode(nums[maxIndex]);
    root->left = construct(nums, l, maxIndex);
    root->right = construct(nums, maxIndex + 1, r);
    return root;
}
bool onlyNegative(queue<TreeNode *> q){
    queue<TreeNode *> copy{q};
    if (copy.empty()){
        return false;
    }
    while (!copy.empty()){
        TreeNode* front=copy.front();
        if (front->value>=0){
            return false;
        }
        copy.pop();
    }
    return true;
}

int main(int argc, char *argv[]) {
    int n ;
    cin>>n;
    int array[n];
    for (int i=0;i<n;i++){
        cin>>array[i];
    }
    TreeNode *tree = construct(array, 0, n);
    queue<TreeNode *> q;
    q.push(tree);
    while (!q.empty()) {
        if (onlyNegative(q)){
            break;
        }
        TreeNode *front = q.front();
        cout << front->value << " ";
        if (front->left != nullptr) {
            q.push(front->left);
        }
        if (front->right != nullptr) {
            q.push(front->right);
        }
        q.pop();
    }
}