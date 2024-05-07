from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        while head:
            tmp = head.next
            head.next = prev
            prev = head
            head = tmp
        return prev
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = self.reverse(head)
        tmp = head
        carry = False
        while tmp:
            tmp.val *= 2
            if carry:
                tmp.val += 1
                carry = False
            if tmp.val >= 10:
                tmp.val -= 10
                carry = True
            if tmp.next is None and carry:
                tmp.next = ListNode(1, None)
                break
            tmp = tmp.next
        head = self.reverse(head)
        return head

if __name__ == '__main__':
    head = ListNode(9, ListNode(9, ListNode(9, None)))
    sol = Solution()
    ret = sol.doubleIt(head)
    while ret:
        print(ret.val)
        ret = ret.next
        