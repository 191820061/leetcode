#include <iostream>

using namespace std;
const int MAXN = 100005;

int fa[MAXN], ranks[MAXN];
int n, k, ans;

void init(int n) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        ranks[i] = 0;
    }

    ans = 0;
}

int find(int x) {
    if (fa[x] == x)
        return x;
    else {
        int temp = fa[x];
        fa[x] = find(fa[x]);
        ranks[x] = (ranks[x] + ranks[temp]) % 3;
        return fa[x];
    }
}

void merge(int r, int u, int v) {
    int fu = find(u);
    int fv = find(v);

    if (fu != fv) {
        fa[fu] = fv;
        ranks[fu] = (ranks[v] - ranks[u] + r + 3) % 3;
    }
}

bool check(int r, int u, int v) {
    if (u > n || v > n)
        return false;
    if (r == 1 && u == v)
        return false;

    int fu = find(u);
    int fv = find(v);

    if (fu == fv)
        return ((ranks[u] - ranks[v]) % 3 + 3) % 3 == r;
    else return true;
}

int main() {
    cin >> n >> k;

    init(n);

    int a, b, c;

    for (int i = 0; i < k; i++) {
        cin >> b >> c;
        a = 2;
        a--;
        if (check(a, b, c))
            merge(a, b, c);
        else
            ans++;
    }

    cout << ans << endl;
}