#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMoneyAmount(int n) {
    vector<vector<int>> status(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (j - i == 1) {
                status[i][j] = i;
            } else {
                int minCost = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = k + max(status[i][k-1], status[k + 1][j]);
                    minCost = min(minCost, cost);
                }
                status[i][j]=minCost;
            }
        }
    }
    return status[1][n];
}

int getMoneyAmount(int begin,int end){
    if (begin>end){
        return 0;
    }
    if (end-begin==1){
        return begin;
    }
    if (end-begin==0){
        return 0;
    }
    int minCost=INT_MAX;
    for (int i=begin;i<end;i++){
        int cost= i+max(getMoneyAmount(begin,i-1), getMoneyAmount(i+1,end));
        minCost= min(cost, minCost);
    }
    return minCost;
}

int main() {
    cout << getMoneyAmount(5);
}