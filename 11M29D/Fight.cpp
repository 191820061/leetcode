#include <iostream>

using namespace std;

int n;
int x;
int fail[2000];
int winner[2000];
int cost[2000];
long long dp[2000];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> fail[i] >> winner[i] >> cost[i];
        fail[i] *= 5;
        winner[i] *= 5;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= cost[i]) {
                dp[j] = max(dp[j] + fail[i], dp[j - cost[i]] + winner[i]);
            } else {
                dp[j] += fail[i];
            }
        }
    }
    printf("%lld\n", dp[x]);
}