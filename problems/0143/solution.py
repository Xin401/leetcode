# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find middle
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        # cut
        l2 = slow.next
        slow.next = None
        # reverse
        prev = None
        curr = l2
        while curr != None:
            nextTemp = curr.next
            curr.next = prev
            prev = curr
            curr = nextTemp
        l2 = prev
        # combine
        l1 = head
        while l2 != None:
            next1 = l1.next
            next2 = l2.next
            l1.next = l2
            l2.next = next1
            l1 = next1
            l2 = next2
