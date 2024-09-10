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
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL|| head->next == NULL) {
            return head; 
        }
        
        ListNode* curr = head;
        
        while (curr->next) {
            int ans = gcd(curr->val, curr->next->val);
            
            ListNode* plk = new ListNode(ans);
            plk->next = curr->next;
            curr->next = plk;
            
            curr = plk->next;
        }
        
        return head;
    }


    
};