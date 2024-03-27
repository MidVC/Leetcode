/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         if (!list1) return list2;
         if (!list2) return list1;

        ListNode* head = new ListNode();
        if (list1->val < list2->val) {
            head->val = list1->val;
            list1 = list1->next;
        } else {
            head->val = list2->val;
            list2 = list2->next;
        }
        ListNode *last = head;
        while (list1 || list2) {
            if (!list1) {
                last->next = list2;
                return head;
            }
            if (!list2) {
                last->next = list1;
                return head;
            }
            if (list1->val < list2->val) {
                last->next = new ListNode(list1->val);
                last = last->next;
                list1 = list1->next;
            } else {
                last->next = new ListNode(list2->val);
                last = last->next;
                list2 = list2->next;
            }
        }

        return head;
    }
};
