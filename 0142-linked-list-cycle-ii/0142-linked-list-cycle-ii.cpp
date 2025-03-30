class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                slow = head;
                while (slow != fast) { // Find the cycle start node
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr; // No cycle
    }
};