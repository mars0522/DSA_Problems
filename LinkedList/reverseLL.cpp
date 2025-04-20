struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };


    ListNode* ReverseIterative(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *prev,*curr,*temp;
        prev = nullptr;
        curr = head;
        temp = curr->next;
    
        while(curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = temp;
            if (temp != nullptr){
            temp = temp->next;
            }
    
        }
        return prev;
    }


    ListNode* reverseLL(ListNode* head,ListNode* prev) {
        if(head==nullptr) return head;
        if(head->next == nullptr) {
            head->next = prev;
            return head;
        }
        ListNode* newhead = reverseLL(head->next,head);
        head->next = prev;
        return newhead;
    }
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return head;
            ListNode* newhead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newhead;
            
        }
    };