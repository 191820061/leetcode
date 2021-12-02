#include <iostream>
#include <vector>

using namespace std;

int prim(vector<vector<int> > &points, int start) {
    int n = points.size();
    int res = 0;

    vector<vector<int> > g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            g[i][j] = dist;
            g[j][i] = dist;
        }
    }

    vector<int> lowcost(n, 2147483647);

    vector<int> v(n, -1);

    v[start] = 0;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        lowcost[i] = g[i][start];
    }

    for (int i = 1; i < n; i++) {
        int minIdx = -1;
        int minVal = 2147483647;
        for (int j = 0; j < n; j++) {
            if (v[j] == 0) continue;
            if (lowcost[j] < minVal) {
                minIdx = j;
                minVal = lowcost[j];
            }
        }

        res += minVal;
        v[minIdx] = 0;
        lowcost[minIdx] = -1;

        for (int j = 0; j < n; j++) {
            if (v[j] == -1 && g[j][minIdx] < lowcost[j]) {
                lowcost[j] = g[j][minIdx];
            }
        }
    }
    return res;

}

int minCostConnectPoints(vector<vector<int>> &points) {
    return prim(points, 0);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        vector<int> point;
        point.push_back(x);
        point.push_back(y);
        points.push_back(point);
    }
    cout<<minCostConnectPoints(points)<<endl;
}

