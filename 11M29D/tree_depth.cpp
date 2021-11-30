#include <iostream>

using namespace std;

struct Node {
    int left;
    int right;
};

Node tree[2000000];
int n;

int dfs(int begin, int depth) {
    if (tree[begin].left == 0 && tree[begin].right == 0) {
        return depth;
    }
    return max(dfs(tree[begin].left, depth + 1), dfs(tree[begin].right, depth + 1));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    cout<<dfs(1,1)<<endl;
}