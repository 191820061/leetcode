#include <iostream>

using namespace std;

int v;
int n;
int box[100];
int dp[100][30000];

int main() {
    cin >> v >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box[i];
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= box[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - box[i]] + box[i]);
            }
        }
    }
    cout << v - dp[n][v] << endl;
}
