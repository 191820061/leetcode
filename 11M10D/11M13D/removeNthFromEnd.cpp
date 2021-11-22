#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode* cache=new ListNode(0, head);
    ListNode *left = cache;
    ListNode *right = head;
    for (int i = 0; i < n; i++) {
        right = right->next;
    }
    while (right) {
        right = right->next;
        left = left->next;
    }
    left->next=left->next->next;
    ListNode* ans=cache->next;
    delete cache;
    return ans;
}

int main() {
    ListNode* node=new ListNode(45);
    node->next=new ListNode(14);
    node->next->next=new ListNode(18);
    removeNthFromEnd(node,1);
}