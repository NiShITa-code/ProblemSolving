# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head
        
        length = 1
        curr = head

        while curr.next:
            curr = curr.next
            length += 1
        pos = k % length
        if pos == 0:
            return head
        pos = length - pos
        curr.next = head
        for _ in range (pos):
            curr = curr.next
        new_head = curr.next
        curr.next = None

        return new_head