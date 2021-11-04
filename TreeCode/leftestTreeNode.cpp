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

int find_lowest_leftest_node(TreeNode *node) {
    queue<TreeNode *> que;
    int res;
    que.push(node);
    while(!que.empty()){
        int len = que.size();
        res = que.front()->val;//最左边就是每次的队头元素，存入结果数组
        for(int i=0; i<len; i++){
            if(que.front()->left)que.push(que.front()->left);
            if(que.front()->right)que.push(que.front()->right);
            que.pop();
        }
    }
    return res;
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
    cout<<find_lowest_leftest_node(node)<<endl;
}
