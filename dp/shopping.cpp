#include <bits/stdc++.h>

using namespace std;
int sum_money;
int m;
int goods_price[25];
int essential[25];
int meb[25][30000] = {0};

int dfs(int x, int sum) {
    if (sum <= 0) {
        return 0;
    }
    if (x > m) {
        return 0;
    }
    if (meb[x][sum]!=0){
        return meb[x][sum];
    }
    int value = 0;
    if (goods_price[x] <= sum) {
        if (goods_price[x] * essential[x] + dfs(x + 1, sum - goods_price[x]) > dfs(x + 1, sum)) {
            value = goods_price[x] * essential[x] + dfs(x + 1, sum - goods_price[x]);
            meb[x][sum]=value;
            return value;
        } else {
            value = dfs(x + 1, sum);
            meb[x][sum]=value;
            return value;
        }
    } else {
        value =  dfs(x + 1, sum);
        meb[x][sum]=value;
        return value;
    }
}

int main(int argc, char *argv[]) {
    cin >> sum_money >> m;
    for (int i = 1; i <= m; i++) {
        cin >> goods_price[i] >> essential[i];
    }
    cout << dfs(1, sum_money);
}