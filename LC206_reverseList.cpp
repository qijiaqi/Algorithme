struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Dummy Head
        if (!head || !head -> next) return head;
        ListNode* dh = new ListNode(0, head);
        ListNode* cur = head;
        while (cur->next) {
            ListNode* tmp = dh -> next;
            dh -> next = cur -> next;
            cur -> next = cur -> next -> next;
            dh -> next -> next = tmp;
        }
        return dh -> next;

        // Double Pointer
        // ListNode* pre = nullptr;
        // ListNode* cur = head;
        // ListNode* tmp;
        // while(cur != nullptr){
        //     tmp = cur -> next;
        //     cur -> next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }
        // return pre;

        // Stack
        // if (!head) return nullptr;
        // stack<int> st;
        // while (head) {
        //     st.push(head -> val);
        //     head = head -> next;
        // }
        // ListNode* res = new ListNode(st.top());
        // ListNode* rv = res;
        // st.pop();
        // while (!st.empty()) {
        //     rv -> next = new ListNode(st.top()); 
        //     rv = rv -> next;
        //     st.pop();
        // }
        // return res;
    }
};