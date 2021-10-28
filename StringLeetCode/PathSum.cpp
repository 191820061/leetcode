#include <iostream>
#include <deque>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : value(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : value(x), left(left), right(right) {}
};

deque<TreeNode*> que;

int rootSum(TreeNode* root, int bloodSum) {
    if (root == nullptr||root->value == 2147483647) {
        return 0;
    }
    int way = 0;
    if (root->value == bloodSum) {
        way++;
    }
    way += rootSum(root->left, bloodSum - root->value);
    way += rootSum(root->right, bloodSum - root->value);
    return way;
}

int pathSum(TreeNode* root, int bloodSum) {
    if (!root||root->value == 2147483647) {
        return 0;
    }
    int ways = rootSum(root, bloodSum);
    ways += pathSum(root->left, bloodSum);
    ways += pathSum(root->right, bloodSum);
    return ways;
}

void TreeInsert(int value) {
    TreeNode* node1 = que.back();
    if (node1->left == nullptr) {
        node1->left = new TreeNode(value);
        que.push_front(node1->left);
    }
    else if (node1->right == nullptr) {
        node1->right = new TreeNode(value);
        que.pop_back();
        que.push_front(node1->right);
    }
}

int main(int argc, char* argv[]) {
    TreeNode* root =nullptr;
    int bloodSum;
    int n;
    string label;
    cin >> bloodSum;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> label;
        if (label == "null") {
            if (root == nullptr) {
                root = new TreeNode(2147483647);
                que.push_front(root);
            }
            else {
                TreeInsert(2147483647);
            }
        }
        else {
            int value = stoi(label);
            if (root == nullptr) {
                root = new TreeNode(value);
                que.push_front(root);
            }
            else {
                TreeInsert(value);
            }
        }
    }

    cout << pathSum(root, bloodSum) << endl;

}