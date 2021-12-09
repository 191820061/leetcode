#include <iostream>
#include "priority_queue.h"

using namespace std;

struct Node {
    int dis;
    int pos;

    bool operator<(const Node &x) const {
        return x.dis < dis;
    }
};

bool compare(Node &x, Node &y) {
    return y.dis < x.dis;
}

int main() {
    priority_list<Node> name(compare);
    name.push((Node) {105, 45});
    name.push((Node) {45, 18});
    cout << name.top().dis << endl;
}

