#include <iostream>
#include <vector>
using namespace std;

void find(int x, vector<vector<int>> &edge, vector<int> &vis) {
    vis[x] = true;
    for (auto y : edge[x]) {
        if (!vis[y]) {
            find(y, edge, vis);
        }
    }
}

int eatFish(vector<vector<int>> &fish) {
    int n = (int)fish.size();
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fish[i][0] == fish[j][0] || fish[i][1] == fish[j][1]) {
                edge[i].push_back(j);
            }
        }
    }
    vector<int> vis(n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            num++;
            find(i, edge, vis);
        }
    }
    return n - num;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> fish;
    vector<int> v;
    int value;
    for(int i=0;i<n;i++){
        v.clear();
        for (int j=0;j<2;j++){
            cin>>value;
            v.push_back(value);
        }
        fish.push_back(v);
    }
    cout<<eatFish(fish);
}
