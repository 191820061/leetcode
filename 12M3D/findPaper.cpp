#include <iostream>
#include <set>
#include <cstring>
#include <deque>

using namespace std;

set<int> edge[1000005];
int n;
int m;
bool via[100005];

void dfs(int x = 1) {
    if (via[x]) {
        return;
    }
    via[x] = true;
    printf("%d ", x);
    for (int i: edge[x]) {
        dfs(i);
    }
}

void bfs(int x = 1) {
    deque<int> que;
    que.push_front(x);
    via[x] = true;
    while (!que.empty()) {
        int element = que.back();
        que.pop_back();
        printf("%d ", element);
        for (int i: edge[element]) {
            if (!via[i]) {
                que.push_front(i);
                via[i] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u;
    int v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        edge[u].insert(v);
    }
    dfs();
    memset(via, 0, sizeof(via));
    printf("\n");
    bfs();
}