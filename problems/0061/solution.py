from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None:
            return None
        array = []
        ptr = head
        while ptr != None:
            array.append(ptr)
            ptr = ptr.next
        m = len(array)
        if k == 0 or k % m == 0:
            return head
        k %= m
        array[m - 1].next = array[0]
        array[m - k - 1].next = None
        return array[m - k]
