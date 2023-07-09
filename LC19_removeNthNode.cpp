struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy Head
        ListNode* dh = new ListNode(head->val, head);
        ListNode* fast = dh;
        ListNode* slow = dh;
        if (!head -> next) return nullptr;
        while (n != 0) {
            if (!fast -> next) return nullptr;
            fast = fast -> next;
            -- n;
        }
        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next; 
        }
        if (!slow -> next -> next) slow -> next = nullptr;
        else if (slow -> next == head) return head -> next;
        else slow -> next = slow -> next -> next;
        return head;

        // if(head -> next == nullptr) return nullptr;
        // ListNode* dummyhead = new ListNode(0, head);
        // ListNode* fast = dummyhead;
        // ListNode* slow = dummyhead;
        // ListNode* tmp;
        // while(n --){
        //     fast = fast -> next;
        // }
        // while(fast -> next != nullptr){
        //     slow = slow -> next;
        //     fast = fast -> next;
        // }
        // tmp = slow -> next;
        // slow -> next = slow -> next ->next;
        // delete tmp;
        // head = dummyhead -> next;
        // return head;
        
    }
};