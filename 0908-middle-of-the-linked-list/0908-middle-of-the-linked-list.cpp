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

    int len(ListNode* head){
        if(head ==0)
        return 0;

        if(head->next == 0)
        return 1;
        
        int len =0;
        while(head){
         len++;
         head= head->next;
        }

        return len;
    }
    ListNode* middleNode(ListNode* head) {


      int l = len(head);

      int mid = (l/2) +1;

      ListNode* temp = head;

      while(mid > 1){
        temp= temp->next;
        mid--;
      }

      return temp;
        
}

        
};