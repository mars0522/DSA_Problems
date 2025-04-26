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

        ListNode *slow,*fast,*prev;
        prev = nullptr;
        slow=fast=head;

        int i=1;
        while(i<=n-1){
            fast = fast->next;
            i++;
        }

        if(fast->next == nullptr) {
            head = slow->next;
            slow->next = nullptr;
            return head;

        }


        while(fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;
        slow->next = nullptr;
        return head;
    }
};