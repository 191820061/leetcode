#include <bits/stdc++.h>

using namespace std;
int sum_money;
int m;
int goods_price[25];
int essential[25];
int dp[25][30000];


int main(int argc, char *argv[]) {
    cin >> sum_money >> m;
    for (int i = 1; i <= m; i++) {
        cin >> goods_price[i] >> essential[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= sum_money; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= goods_price[i]) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-goods_price[i]]+(goods_price[i]*essential[i]));
            }
        }
    }
    cout<<dp[m][sum_money]<<endl;
}