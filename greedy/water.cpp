#include <iostream>

using namespace std;

struct times {
    int wait_time;
    int order;
};


int n;
times all[2000];

void sorted() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if (all[j + 1].wait_time < all[j].wait_time) {
                times cache = all[j + 1];
                all[j + 1] = all[j];
                all[j] = cache;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        all[i].order = i;
        cin >> all[i].wait_time;
    }
    sorted();
    int value = 0;
    double all_time = 0.0;
    for (int i = 1; i <= n; i++) {
        printf("%d ", all[i].order);
        value += all[i - 1].wait_time;
        all_time += (double) value;
    }
    printf("\n%.2f", all_time / (double) n);
}