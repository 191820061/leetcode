#include <iostream>

using namespace std;

int n;
int m;
int F[20000];
int M_Z[300000];
int M_X[300000];
int M_Y[300000];

int find(int e) {
    if (F[e] == e) {
        return e;
    }
    F[e] = find(F[e]);
    return F[e];
}

void init() {
    for (int i = 0; i <= 20000; i++) {
        F[i] = i;
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", M_Z + i, M_X + i, M_Y + i);
    }
    for (int i = 0; i < m; i++) {
        int z = M_Z[i];
        int x = M_X[i];
        int y = M_Y[i];
        if (z == 1) {
            F[find(x)] = find(y);
        } else {
            if (find(x) == find(y)) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
    }
}