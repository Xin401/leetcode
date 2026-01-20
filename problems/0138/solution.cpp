/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> mark;
        vector<int> loc;
        Node* ptr = head;
        while(ptr!=nullptr)
        {
            mark.push_back(ptr);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr!=nullptr)
        {
            bool isHave = false;
            for(int i = 0;i<mark.size();i++)
            {
                if(ptr->random==mark[i])
                {
                    loc.push_back(i);
                    isHave = true;
                }
            }
            if(!isHave)
                {
                    loc.push_back(-1);
                }
            ptr = ptr->next;
        }
        if(head!=nullptr)
        {
            vector <Node*> reminder;
            Node* ans = new Node(0);
            for(int i = 0;i<mark.size();i++)
            {
                ans->next = new Node(mark[i]->val);
                ans=ans->next;
                reminder.push_back(ans);
            }
            for(int i = 0;i<mark.size();i++)
            {
                if(loc[i]!=-1)
                {
                    reminder[i]->random = reminder[loc[i]];
                }
            }
            return reminder[0];
        }
        else
        {
            return head;
        }
    }
};