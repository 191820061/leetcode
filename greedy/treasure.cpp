#include <iostream>

using namespace std;

struct coin {
    float weight;
    float value;
};

int n;
float t;
coin all[200];

void sorted() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if ((all[j + 1].value / all[j + 1].weight) > (all[j].value / all[j].weight)) {
                coin cache = all[j + 1];
                all[j + 1] = all[j];
                all[j] = cache;
            }
        }
    }
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> all[i].weight >> all[i].value;
    }
    sorted();
    float value = 0;
    for (int i = 1; i <= n; i++) {
        if (t >= all[i].weight) {
            value += all[i].value;
            t -= all[i].weight;
        } else {
            value += t * (all[i].value / all[i].weight);
            t = 0;
            break;
        }
    }
    printf("%.2f\n",value);
}