from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        dummy = ListNode(0, head)
        prev = dummy
        while prev != slow and prev.next != slow:
            prev = prev.next

        prev.next = slow.next
        return dummy.next
