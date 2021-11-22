#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2, ListNode *l3) {
    if (l1 == nullptr && l2 == nullptr) {
        return l3;
    } else if (l1 == nullptr) {
        l3->next = l2;
        return l3;
    } else if (l2 == nullptr) {
        l3->next=l1;
        return l3;
    }
    if (l1->val >= l2->val) {
        l3->next = l2;
        return mergeTwoLists(l1, l2->next, l3->next);
    } else {
        l3->next = l1;
        return mergeTwoLists(l1->next, l2, l3->next);
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *l3 = new ListNode(-1);
    ListNode *cache = l3;
    mergeTwoLists(l1, l2, l3);
    return cache->next;
}

int main() {
    ListNode *l1 = new ListNode(-9);
    l1->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(7);
    ListNode *l3 = mergeTwoLists(l1, l2);
    cout << l3->val << endl;
}