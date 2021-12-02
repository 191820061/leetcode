#include <iostream>

using namespace std;

int n;
int first[200000];
int second[200000];

int dp[5000][5000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> first[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> second[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][n] << endl;
}