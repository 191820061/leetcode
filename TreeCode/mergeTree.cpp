#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int item, TreeNode *left, TreeNode *right) : val(item), left(left), right(right) {}

    TreeNode(int items) : TreeNode(items, nullptr, nullptr) {}
};

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr) {
        return t2;
    }
    if (t2 == nullptr) {
        return t1;
    }
    auto merged = new TreeNode(t1->val + t2->val);
    auto q = queue<TreeNode *>();
    auto queue1 = queue<TreeNode *>();
    auto queue2 = queue<TreeNode *>();
    q.push(merged);
    queue1.push(t1);
    queue2.push(t2);
    while (!queue1.empty() && !queue2.empty()) {
        auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
        q.pop();
        queue1.pop();
        queue2.pop();
        auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
        if (left1 != nullptr || left2 != nullptr) {
            if (left1 != nullptr && left2 != nullptr) {
                auto left = new TreeNode(left1->val + left2->val);
                node->left = left;
                q.push(left);
                queue1.push(left1);
                queue2.push(left2);
            } else if (left1 != nullptr) {
                node->left = left1;
            } else if (left2 != nullptr) {
                node->left = left2;
            }
        }
        if (right1 != nullptr || right2 != nullptr) {
            if (right1 != nullptr && right2 != nullptr) {
                auto right = new TreeNode(right1->val + right2->val);
                node->right = right;
                q.push(right);
                queue1.push(right1);
                queue2.push(right2);
            } else if (right1 != nullptr) {
                node->right = right1;
            } else {
                node->right = right2;
            }
        }
    }
    return merged;
}

void preorder(TreeNode *root) {
    if (root == nullptr) {
        cout << -1 << " ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

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


int main() {
    TreeNode *node = nullptr;
    TreeNode *node1 = nullptr;
    int c;
    int cache[10000];
    int cache2[10000];
    int index = 0;
    int index2 = 0;
    while (cin.peek() != '\n') {
        cin >> c;
        cache[index++] = c;
    }
    node = creat_tree(node, cache);
    cin >> c;
    cache2[index2++] = c;
    while (cin.peek() != '\n') {
        cin >> c;
        cache2[index2++] = c;
    }
    indexs = 0;
    node1 = creat_tree(node1, cache2);
    TreeNode* node2= mergeTrees(node,node1);
    preorder(node2);
}