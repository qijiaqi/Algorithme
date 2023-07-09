struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //stack<int> st;
        int t = l1 -> val + l2 -> val;
        ListNode* res = new ListNode(t%10);
        ListNode* l3 = res;
        bool c = false;
        if (t >= 10) c = true;
        while (l1->next || l2->next) {
            // compute the value of the next node
            t = 0;
            if (l1->next) {
                l1 = l1 -> next;
                t += l1 -> val;
            }
            if (l2->next) {
                l2 = l2 -> next;
                t += l2 -> val;
            }
            // add 1 to the result before mod 10 if carry 
            if (c) {
                l3 -> next = new ListNode((t + 1)%10);
            } else { 
                l3 -> next = new ListNode(t%10);
            }
            l3 = l3 -> next;
            // renew the carry for the next node
            if (t >= 10 || (t == 9 && c)) {
                c = true;
            } else {
                c = false;
            }
        }
        if (c) l3 -> next = new ListNode(1); // last carry
        return res;
        // addition in another direction
        
        // ListNode* res = new ListNode(l1->val + l2->val);
        // ListNode* l3 = res;
        // while (l1 -> next && l2 -> next) { 
        //     l1 = l1 -> next;
        //     l2 = l2 -> next; 
        //     l3 -> next = new ListNode(l1->val + l2->val);
        //     l3 = l3 -> next;
        // }
        // if (l1 -> next) l3 -> next = l1 -> next;
        // if (l2 -> next) l3 -> next = l2 -> next;
        // return res;
    }
};