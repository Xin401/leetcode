/*
 * Space Complexiyt: O(1)
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListTemplates {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }

  ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode* dummyNodePattern(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* curr = &dummy;

    while (curr->next != nullptr) {
      // 進行節點刪除或插入操作...
      // 例如：if (curr->next->val == target) { curr->next = curr->next->next; }
      curr = curr->next;
    }

    return dummy.next;
  }
};