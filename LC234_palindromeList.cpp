struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    // Vector
      vector<int> v;
      while(head){
          v.push_back(head -> val);
          head = head -> next;
      }
      int j = v.size() - 1;
      for(int i = 0; i < j; ++ i){
          if(v[i] != v[j]) return false;
          else -- j;
      }
      return true;
    }
    // Reverse & Double Pointer
    ListNode* reverse(ListNode* head) {
        // pre = new head
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        while (cur) {
            tmp = cur -> next;
            cur -> next = pre;
            pre = cur;     
            cur = tmp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;   
        }
        slow = reverse(slow);   
        fast = head;
        while (slow) {
            if (slow -> val != fast -> val) return false;
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};