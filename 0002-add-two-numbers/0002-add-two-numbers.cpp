/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Create a dummy node to simplify the process and hold the result list.
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Step 2: Initialize carry to handle carry over during addition.
        int carry = 0;

        // Step 3: Iterate while there are nodes to process or we still have a carry.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            // Step 4: Add values from l1 and l2 if they exist.
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Step 5: Update carry for next iteration.
            carry = sum / 10;

            // Step 6: Create a new node for the current digit of the result.
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        // Step 7: The dummy's next node is the head of the resultant list.
        return dummy->next;
    }
};