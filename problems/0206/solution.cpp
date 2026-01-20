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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }
        ListNode* builder = new ListNode();
        ListNode* ans = builder;
        vector<int> temp;
        while(head!=nullptr)
        {
            temp.push_back(head->val);
            head = head->next;
        }
        for(int i = temp.size()-1;i>=0;i--)
        {
            builder->next = new ListNode(temp[i]);
            builder = builder->next;
        }
        return ans->next;
    }
};