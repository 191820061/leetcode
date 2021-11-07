#include <iostream>
#include <vector>

using namespace std;

int maxCount(int m, int n, vector<vector<int>> &ops) {
    if (ops.size()==0){
        return m*n;
    }
    vector<int> intersect=ops[0];
    for (int i=1;i<ops.size();i++){
        if (ops[i][0]<intersect[0]){
            intersect[0]=ops[i][0];
        }
        if (ops[i][1]<intersect[1]){
            intersect[1]=ops[i][1];
        }
    }
    return intersect[0]*intersect[1];
}

int main(){
    vector<vector<int>> ops{};
    cout<<maxCount(3,3,ops)<<endl;
}