"""
Space Complexiyt: O(1)
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head

        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp

            # Python 進階語法糖 (可一行寫完，但初學建議寫上面那種幫助理解)：
            # curr.next, prev, curr = prev, curr, curr.next

        return prev

    def findMiddle(self, head: ListNode) -> ListNode:
        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow

    def dummyNodePattern(self, head: ListNode) -> ListNode:
        dummy = ListNode(0, head)
        curr = dummy

        while curr.next:
            # 進行操作...
            curr = curr.next

        return dummy.next
