#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;
int way[1005][1005];

void init_max() {
    memset(way, 127 / 3, sizeof(way));
    for (int i = 1; i <= n; i++) {
        way[i][i] = 0;
    }
}

int main() {
    cin >> n >> m;
    init_max();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        way[u][v] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                way[i][j] = min(way[i][j], way[i][k] + way[k][j]);
            }
        }
    }
    int all = 0;
    for (int i = 2; i <= n; i++) {
        all += way[1][i] + way[i][1];
    }
    cout << all << endl;
}