#include <iostream>

using namespace std;

struct LineSeg {
    int begin;
    int end;
};

int n;
LineSeg line[30000];
int dp[30000][2];
bool isLeft = false;
bool isRight = false;


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> line[i].begin >> line[i].end;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

        }
    }
}