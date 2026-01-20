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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }
        vector<int> temp;
        ListNode* builder=new ListNode();
        ListNode*ans =builder;
        while(head!=nullptr)
        {
            temp.push_back(head->val);
            head = head->next;
        }
        temp.resize(distance(temp.begin(),unique(temp.begin(),temp.end())));
        for(int i = 0;i<temp.size();i++)
        {
            builder->next = new ListNode(temp[i]);
            builder = builder->next;
        }
        return ans->next;
    }
};