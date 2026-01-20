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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return nullptr;
        }
        else
        {
            ListNode *fast=head;
            ListNode *slow = head;
            ListNode *ret=head;
            while(true)
            {
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow)
                {
                    break;
                }
                else if(fast==nullptr||fast->next==nullptr||fast->next->next==nullptr)
                {
                    return nullptr;
                }
            }
            while(true)
            {
                if(ret==slow)
                {
                    return ret;
                }
                slow=slow->next;
                ret=ret->next;
            }
        }
    }
};