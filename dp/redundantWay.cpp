#include <iostream>

using namespace std;

int array[100001];
int instruct[100001][2];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        array[i] = i;
    }
}

int find(int ele) {
    if (array[ele] == ele) {
        return ele;
    } else {
        return find(array[ele]);
    }
}

void merge(int x, int parent) {
    array[x] = parent;
}

int main() {
    int n;
    cin >> n;
    init(100001);
    for (int i = 0; i < n; i++) {
        int u;
        int v;
        cin >> u >> v;
        instruct[i][0]=u;
        instruct[i][1]=v;
    }
    for (int i=0;i<n;i++){
        int u=instruct[i][0];
        int v=instruct[i][1];
        if (array[u] != u && array[v] != v) {
            if (find(u) == find(v)) {
                cout << u << " " << v;
                break;
            } else {
                merge(find(u), v);
            }
        } else if (array[u] != u) {
            if (find(u) == v) {
                cout << u << " " << v;
                break;
            }
            merge(v, u);
        } else if (array[v] != v) {
            if (find(v) == u) {
                cout << u << " " << v;
                break;
            }
            merge(u, v);
        }else{
            merge(u,v);
        }
    }
}