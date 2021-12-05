#include <iostream>
#include <set>

using namespace std;


int n;
int m;
set<int> edge[600000];
int eat[600000];
int mod = 80112002;

int dfs(int x, int size) {
    if (edge[x].empty()) {
        return size;
    }
    int max = 0;
    for (int i: edge[x]) {
        int result = dfs(i, (size + 1) % mod);
        if (result > max) {
            max = result;
        }
    }
    return max;
}

int main() {
    cin >> n >> m;
    int a;
    int b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        edge[a].insert(b);
        eat[i] = b;
    }
    for (int i = 1; i <= n; i++) {
        int result= dfs(i,1);
        cout<<result<<endl;
    }
}