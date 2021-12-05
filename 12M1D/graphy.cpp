#include<iostream>

using namespace std;

const int maxn = 50005;
int n, cnt = 0;
struct Edge {
    int to, w, next;
};
Edge edge[maxn];
int head[maxn];

void init() {
    for (int i = 0; i <= n; i++) {
        head[i] = -1;
    }
    cnt = 0;
}

void add_edge(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

long long maxs = 0;

long long dfs(int x, long long size) {
    if (head[x] == -1) {
        if (size > maxs) {
            maxs = size;
        }
        return size;
    }
    long long all = 0;
    for (int i = head[x]; i != -1; i = edge[i].next) {
        long long result = dfs(edge[i].to, size + edge[i].w);
        all += result;
    }
    return all;
}

int get[maxn];

bool find(int v) {
    for (int i = 1; i <= n - 1; i++) {
        if (get[i] == v) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    int u, v, w;
    init();
    long long all = 0;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        all += w;
        if (v == 1) {
            add_edge(v, u, w);
            get[i] = u;
        } else if (find(v)) {
            add_edge(v, u, w);
            get[i] = u;
        } else {
            add_edge(u, v, w);
            get[i] = v;
        }
    }
    dfs(1, 0);

    cout << 2 * all - maxs << endl;
}