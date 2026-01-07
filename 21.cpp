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
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode* list3 = new ListNode;
        ListNode* r = list3;

        if (!p) return q;
        if (!q) return p;

        if (p->val < q->val) {
            r->val = p->val;
            p = p->next;
        } else {
            r->val = q->val;
            q = q->next;
        }

        while (p || q) {
            r->next = new ListNode;
            r = r->next;

            if (!q || (p && p->val <= q->val)) {
                r->val = p->val;
                p = p->next;
            } else {
                r->val = q->val;
                q = q->next;
            }
        }

        r->next = nullptr;
        return list3;
    }
};