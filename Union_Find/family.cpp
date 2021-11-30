#include <iostream>

using namespace std;

int n;
int m;
int p;
int family[10000];

int find(int e) {
    if (family[e] == e) {
        return e;
    }
    family[e] = find(family[e]);
    return family[e];
}

void init() {
    for (int i = 0; i <= 10000; i++) {
        family[i] = i;
    }
}

int main() {
    cin >> n >> m >> p;
    init();
    int Mi;
    int Mj;
    int query[p][2];
    for (int i = 0; i < m; i++) {
        cin >> Mi >> Mj;
        family[find(Mi)] = find(Mj);
    }
    for (int i = 0; i < p; i++) {
        cin >> query[i][0] >> query[i][1];
    }

    for (int i = 0; i < p; i++) {
        if (find(query[i][0])== find(query[i][1])){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}