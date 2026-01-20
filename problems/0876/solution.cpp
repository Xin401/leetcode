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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(head->next!=nullptr)
        {
            head = head->next;
            length++;
        }
        length = (length+1)/2;
        for(int i = 0;i<length;i++)
        {
            temp = temp->next;
        }
        return temp;
    }
};