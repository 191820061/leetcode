#include <iostream>

using namespace std;

int n;
int m;
int order[10005];
int array[105][105];
int ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> order[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> array[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                array[i][j] = min(array[i][j], array[i][k] + array[k][j]);
            }
        }
    }
    for (int i = 2; i <= m; i++) {
        ans += array[order[i - 1]][order[i]];
    }
    cout << ans << endl;
}