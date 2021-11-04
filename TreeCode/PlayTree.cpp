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

void zigzagLevelOrder(TreeNode *root) {
    if (!root) {
        return;
    }
    queue<TreeNode *> que;
    que.push(root);
    bool isLeft = true;
    while (!que.empty()) {
        deque<int> list;
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            auto node = que.front();
            que.pop();
            if (isLeft) {
                list.push_back(node->val);
            } else {
                list.push_front(node->val);
            }
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        auto begin=list.begin();
        while (begin!=list.end()){
            cout<<*begin<<" ";
            begin++;
        }
        printf("\n");
        isLeft = !isLeft;
    }
}

int main() {
    TreeNode *node = nullptr;
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    node = creat_tree(node, array);
    zigzagLevelOrder(node);
}