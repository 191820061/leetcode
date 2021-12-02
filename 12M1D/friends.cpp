#include <iostream>

using namespace std;

int n;
int friends[300][300];
int F[300];


int find(int a) {
    if (F[a] == a) {
        return a;
    }
    F[a] = find(F[a]);
    return F[a];
}

void init() {
    for (int i = 1; i < 300; i++) {
        F[i] = i;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> friends[i][j];
        }
    }
    init();

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (friends[i][j] == 1) {
                F[find(i)] = find(j);
            }
        }
    }
    int count=0;
    for (int i = 1; i <= n; i++) {
        if (F[i]==i){
            count++;
        }
    }
    printf("%d\n",count);
}