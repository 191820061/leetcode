#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int item, TreeNode *left, TreeNode *right) : val(item), left(left), right(right) {}

    TreeNode(int items) : TreeNode(items, nullptr, nullptr) {}
};

int get_length(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int x = get_length(root->left);
    int y = get_length(root->right);
    return x + y + 1;
}

TreeNode *create_tree(TreeNode *root, vector<int> &array) {
    int index = 0;
    root = new TreeNode(array[index++]);
    deque<TreeNode *> que;
    que.push_front(root);
    while (!que.empty()) {
        TreeNode *cache = que.back();
        que.pop_back();
        if (index < array.size()) {
            cache->left = new TreeNode(array[index++]);
        }
        if (index < array.size()) {
            cache->right = new TreeNode(array[index++]);
        }
        if (cache->left != nullptr && cache->right != nullptr) {
            que.push_front(cache->left);
            que.push_front(cache->right);
        }
    }
    return root;
}

int main() {
    int x;
    int n;
    cin >> x >> n;
    vector<int> v;
    TreeNode *root = nullptr;
    int ele;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        v.push_back(ele);
    }
    root = create_tree(root, v);
    int left = get_length(root->left);
    int right = get_length(root->right);
    if (left > right && x == 2) {
        cout << false << endl;
    }else if (left == right && x == 1) {
        cout << false << endl;
    } else {
        cout << true << endl;
    }
}