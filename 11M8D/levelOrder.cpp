#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
    deque<TreeNode *> deque;
    deque.push_front(root);
    vector<vector<int>> result;
    while (!deque.empty()) {
        int currentSize = (int) deque.size();
        result.push_back(vector<int>());
        for (int i = 0; i < currentSize; i++) {
            TreeNode *node = deque.back();
            result.back().push_back(node->val);
            deque.pop_back();
            if (node->left != nullptr) {
                deque.push_front(node->left);
            }
            if (node->right != nullptr) {
                deque.push_front(node->right);
            }
        }
    }
    return result;
}

int main() {
    auto *root = new TreeNode(3, new TreeNode(9), new TreeNode(20));
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = levelOrder(root);
    cout<<result[0][0]<<endl;
}