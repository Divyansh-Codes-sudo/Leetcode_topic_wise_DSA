class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *p = NULL;
        ListNode *temp = head;
        ListNode *n = temp->next;

        while(n){
            temp->next = p;
            p = temp;
            temp = n;
            n = n->next;
        }
        temp->next = p;

        return temp;

    }
};