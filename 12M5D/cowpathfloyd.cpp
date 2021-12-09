#include <iostream>
#include <cstring>

using namespace std;
#define Max 2147483647
int n;
int m;
int b;
int order[505];
int way[505][505];

int main() {
    cin >> n >> b >> m;
    memset(way, 127 / 3, sizeof(way));
    for (int i = 1; i <= n; i++) {
        way[i][i] = 0;
    }
    for (int i = 1; i <= b; i++) {
        cin >> order[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        way[u][v] = w;
        way[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                way[i][j] = min(way[i][j], way[i][k] + way[k][j]);
            }
        }
    }
    int min = Max;
    int result = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        result = 0;
        for (int j = 1; j <= b; j++) {
            result += way[i][order[j]];
        }
        if (result < min) {
            min = result;
            ans = i;
        }
    }
    cout << ans << endl;
}