#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node() : value(0), left(nullptr), right(nullptr) {}

    Node(int x) : value(x), left(nullptr), right(nullptr) {}

    Node(int x, Node *left, Node *right) : value(x), left(left), right(right) {}
};

int max(int *nums, int l, int r) {
    int max_i = l;
    for (int i = l; i < r; i++) {
        if (nums[max_i] < nums[i])
            max_i = i;
    }
    return max_i;
}

Node *construct(int *nums, int l, int r) {
    if (l == r)
        return new Node(-1);
    int max_i = max(nums, l, r);
    Node *root = new Node(nums[max_i]);
    root->left = construct(nums, l, max_i);
    root->right = construct(nums, max_i + 1, r);
    return root;

}

bool onlyNegative(queue<Node *> q){
    queue<Node *> copy{q};
    if (copy.empty()){
        return false;
    }
    while (!copy.empty()){
        Node* front=copy.front();
        if (front->value>=0){
            return false;
        }
        copy.pop();
    }
    return true;
}

int main(int argc, char *argv[]) {
    int n = 6;
    int array[6] = {3 ,2, 1, 6, 0, 5};
    Node *tree = construct(array, 0, n);
    queue<Node *> q;
    q.push(tree);

    while (!q.empty()) {
        if (onlyNegative(q)){
            break;
        }
        Node *front = q.front();
        cout << front->value << " ";
        q.pop();
        if (front->left != nullptr) {
            q.push(front->left);
        }
        if (front->right != nullptr) {
            q.push(front->right);
        }
    }
}