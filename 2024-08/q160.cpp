#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> hashmap;

        while (headA) {
            hashmap.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (hashmap.find((headB)) != hashmap.end()) return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};