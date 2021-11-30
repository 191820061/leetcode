#include <iostream>

using namespace std;

int n;
int tower[2000][2000];
int dp[2000][2000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tower[i][j];
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tower[i][j];
        }
    }
    int max = dp[n][1];
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] > max) {
            max = dp[n][i];
        }
    }
    cout << max << endl;
}
