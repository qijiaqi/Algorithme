struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iteration 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* list3 = new ListNode(0, nullptr);
        ListNode* head = list3;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                list3 -> next = new ListNode(list1->val);
                list1 = list1 -> next;
            } else {
                list3 -> next = new ListNode(list2->val);
                list2 = list2 -> next;
            }
            list3 = list3 -> next;
        }
        if(list1) list3->next = list1;
        if(list2) list3->next = list2;
        return head->next;
    }
    // Recursion
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val) {
            list1 -> next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2 -> next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val) list1 -> next = mergeTwoLists(list1->next, list2);
        else list2 -> next = mergeTwoLists(list1, list2->next);
        return list1->val < list2->val ? list1: list2;
    }
};