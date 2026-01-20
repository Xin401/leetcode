from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nums = []
        local_max = []
        ptr = head
        while ptr:
            nums.append(ptr.val)
            ptr = ptr.next
        local_max.append(nums[-1])
        for i in range(1,len(nums)+1):
            if nums[-i] >= local_max[-1]:
                local_max.append(nums[-i])
        ret = ListNode(0, None)
        tmp = ret
        for i in range(1,len(local_max)):
            print(tmp)
            tmp.next = ListNode(local_max[-i],None)
            tmp = tmp.next
        return ret.next




            