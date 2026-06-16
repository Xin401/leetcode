/*
 * Space Complexiyt: O(1)
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
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

    // 偶數長度停在左中點:
    // while (fast.next != nullptr && fast->next->next != nullptr)
    // 偶數長度停在右中點:
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