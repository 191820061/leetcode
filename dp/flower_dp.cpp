#include <iostream>

using namespace std;

int n;
int m;
int array[1000];
int mod = 1000007;
int dp[1000][1000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= min(array[i], j); k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}