#include <iostream>

using namespace std;

int times;
int m;
int count_time[200];
int value[200];
int dp[200][2000];

int main() {
    cin >> times >> m;
    for (int i = 1; i <= m; i++) {
        cin >> count_time[i] >> value[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= times; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= count_time[i]) {
                dp[i][j] = max(dp[i][j],dp[i - 1][j - count_time[i]] + value[i]);
            }
        }
    }
    cout << dp[m][times] << endl;
}