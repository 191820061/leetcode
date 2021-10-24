#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node() : value(0), left(nullptr), right(nullptr) {}

    Node(int x) : value(x), left(nullptr), right(nullptr) {}

    Node(int x, Node *left, Node *right) : value(x), left(left), right(right) {}
};

int main(int argc, char *argv[]) {
    int bloodSum;
    int n;
    cin >> bloodSum;
    cin >> n;
}