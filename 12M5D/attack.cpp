
#include <iostream>
#include <cmath>

using namespace std;

int n;
int m;
int order[1000005];

void sorted(int x) {
    if (x == 1) {
        return;
    } else {
        int cache_pos = x;
        for (int i = x - 1; i >= 1; i--) {
            if (order[cache_pos] < order[i]) {
                int cache_value = order[cache_pos];
                order[cache_pos] = order[i];
                order[i] = cache_value;
                cache_pos = i;
            } else {
                break;
            }
        }
    }
}

inline int read()//二进制优化的快读
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        order[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        int x = ceil((double) i / m);
        int attack = x == 1 ? i : i - x + 1;
        sorted(i);
        printf("%d ", order[attack]);
    }
}