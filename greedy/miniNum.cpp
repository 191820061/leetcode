#include <iostream>

using namespace std;

string num;
int k;
string result;

int main() {
    cin >> num >> k;
    for (int i = 0; i < num.size(); i++) {
        if ((num[i] - '0') < (num[i + 1] - '0')) {
            result += num[i];
            continue;
        }
        k -= 1;
        if (k == 0 && i + 1 != num.size()) {
            result += num.substr(i + 1);
            break;
        }
    }
    cout << result << endl;
}