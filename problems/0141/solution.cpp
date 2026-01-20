/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * now;
        now = head;
        while(now!=NULL)
        {
           
            now->val = 100001;
            now = now->next;
            if(now!=NULL&&now->val==100001)
            {
                return true;
            }
            
        }
        return false;
    }
};