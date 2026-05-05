#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        vector<ListNode*> list;
        ListNode * ptr = head;
        while(ptr != nullptr) {
            list.push_back(ptr);
            ptr = ptr->next;
        }
        int m = list.size();
        if (k == 0 || k % m == 0) return head;
        k %= m;
        list[m - 1]->next = list[0];
        list[m - k - 1]->next = nullptr;
        return list[m - k];
    }
};

int main() {
    Solution sol;
    ListNode * head = new ListNode(0, new ListNode(1, new ListNode(2)));
    ListNode * newHead = sol.rotateRight(head, 4);
    while (newHead != nullptr){
        cout << newHead->val << ',' ;
        newHead = newHead->next;
    }
}