#include <iostream>

using namespace std;

int n;
int m;
int mod = 1000007;
int array[1000];
int meb[1000][1000]={0};

int dfs(int x, int k) {
    if (k > m) {
        return 0;
    }
    if (k == m) {
        return 1;
    }
    if (x >= n) {
        return 0;
    }
    if (meb[x][k]!=0){
        return meb[x][k];
    }
    int ans = 0;
    for (int i = 0; i <= array[x]; i++) {
        ans = (ans + dfs(x + 1, k+i)) % mod;
    }
    meb[x][k]=ans;
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }
    cout << dfs(0, 0);
}