#include <iostream>

using namespace std;

string midOrder;
string behindOrder;

void preOrder(const string &mid, const string &behind) {
    if (mid.empty()){
        return;
    }
    if (behind.empty()){
        return;
    }
    char top = behind[behind.size() - 1];
    cout << top;
    int pos = 0;
    for (int i = 0; i < mid.size(); ++i) {
        if (mid[i] == top) {
            pos = i;
            break;
        }
    }
    preOrder(mid.substr(0, pos), behind.substr(0, pos));
    preOrder(mid.substr(pos + 1), behind.substr(pos, behind.size() - 1 - pos));

}

int main() {
    cin >> midOrder;
    cin >> behindOrder;
    preOrder(midOrder, behindOrder);
}