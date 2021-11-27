#include <iostream>

using namespace std;


int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int pos[n];
    string person[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        cin >> pos[index] >> person[index];
        index++;
    }
    int num = 0;
    int direction = 0;
    int begin = 0;
    for (int i = 0; i < m; i++) {
        cin >> direction >> num;
        if (pos[begin] == direction) {
            if (begin >= num) {
                begin -= num;
            } else {
                begin = index - (num - begin);
            }
        } else {
            begin = (begin + num) % index;
        }
    }
    cout<<person[begin]<<endl;
}