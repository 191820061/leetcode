#include <iostream>

using namespace std;

int n;
int m;
int w;
int count_money[20000];
int value[20000];
int goods[20000];
int dp[20000][20000];

int find(int e) {
    if (goods[e] == e) {
        return e;
    }
    goods[e] = find(goods[e]);
    return goods[e];
}

void init() {
    for (int i = 0; i < 20000; i++) {
        goods[i] = i;
    }
}

int main() {
    cin >> n >> m >> w;
    int x;
    int y;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> count_money[i] >> value[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        goods[find(x)] = goods[find(y)];
    }
    dp[0][0] = 0;
}