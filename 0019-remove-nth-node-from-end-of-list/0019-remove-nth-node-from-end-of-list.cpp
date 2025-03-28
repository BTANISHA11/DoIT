class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // Move fast ahead by n+1 steps
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the target node
        slow->next = slow->next->next;

        // Return the head of modified list
        return dummy->next;
    }
};