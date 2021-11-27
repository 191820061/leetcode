#include <cstring>
#include <iostream>

using namespace std;

struct HugeInt {
    int len;
    int num[10001];
};
char a[10001];
char b[10001];
HugeInt x, y, w;

void scanHugeInt() {
    int a_len = (int) strlen(a);
    int b_len = (int) strlen(b);
    for (int i = 0; i < a_len; i++) {
        x.num[a_len - 1 - i] = a[i] - '0';
    }
    x.len = a_len;
    for (int i = 0; i < b_len; i++) {
        y.num[b_len - 1 - i] = b[i] - '0';
    }
    y.len = b_len;
}

void Plus() {
    w.len = max(x.len, y.len);
    for (int i = 0; i < w.len; i++) {
        w.num[i] += x.num[i] + y.num[i];
        w.num[i + 1] += w.num[i] / 10;
        w.num[i] %= 10;
    }
    if (w.num[w.len] != 0) {
        w.len++;
    }
}

void Multiply() {
    int cache = 0;
    for (int i = 0; i < x.len; i++) {
        cache = 0;
        for (int j = 0; j < y.len; j++) {
            w.num[i + j] += x.num[i] * y.num[j] + cache;
            cache = w.num[i + j] / 10;
            w.num[i + j] = w.num[i + j] % 10;
        }
        w.num[y.len + i] = cache;
    }
    w.len = x.len + y.len;
    while (w.num[w.len - 1] == 0 && w.len != 1) {
        w.len--;
    }

}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout<<i<<endl;
    }
}