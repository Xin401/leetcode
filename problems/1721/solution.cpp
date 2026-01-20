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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        ListNode* target1;
        ListNode* target2;
        int count =1;
        while(temp!=nullptr)
        {
            length++;
            temp = temp->next;
        }
        temp = head;
        while(temp!=nullptr)
        {
            if(count==k)
            {
                target1=temp;
            }
            if(length-count+1==k)
            {
                target2 = temp;
            }
            temp = temp->next;
            count++;
        }
        int val = target1->val;
        target1->val = target2->val;
        target2->val = val;
        return head;
    }
};