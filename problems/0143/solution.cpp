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
  void reorderList(ListNode* head) {
    // find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // cut
    ListNode* l2 = slow->next;
    slow->next = nullptr;
    // reverse l2
    ListNode* prev = nullptr;
    ListNode* curr = l2;
    while (curr != nullptr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    l2 = prev;
    // combine
    ListNode* l1 = head;
    while (l2 != nullptr) {
      ListNode* next1 = l1->next;
      ListNode* next2 = l2->next;
      l1->next = l2;
      l2->next = next1;
      l1 = next1;
      l2 = next2;
    }
  }
};