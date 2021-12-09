#include <iostream>

using namespace std;
struct data {
    int a, b;
};

int n;
data people[20000];
int a[2005], b[2005];
int cnt;

void init() {
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
}

int find(int x) {
    if (a[x] == x) {
        return x;
    }
    a[x] = find(a[x]);
    return a[x];
}

inline void ad(int x, int y)//合并
{
    x = find(a[x]);
    y = find(a[y]);
    a[x] = y;
}

int query(int x, int y) {
    return find(x) == find(y);
}

int main() {
    cin >> n;
    int x, y;
    init();
    while (cin >> x >> y) {
        cnt++;
        people[cnt].a = x;
        people[cnt].b = y;
    }
    for (int i = 1; i <= cnt; i++) {
        if (query(people[i].a, people[i].b)) {
            cout << 0 << endl;
            return 0;
        } else {
            if (!b[people[i].a]) {
                b[people[i].a] = people[i].b;
            } else {
                ad(b[people[i].a], people[i].b);
            }
            if (!b[people[i].b]) {
                b[people[i].b] = people[i].a;
            } else {
                ad(b[people[i].b], people[i].a);
            }
        }
    }
    cout << 1 << endl;
}