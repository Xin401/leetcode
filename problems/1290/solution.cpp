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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        int length=1;
        ListNode* temp =head;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
            length++;
        }
        for(int i = length-1;i>=0;--i)
        {
            ans+=pow(2,i)*head->val;
            head = head->next;
        }
        return ans;
    }
};