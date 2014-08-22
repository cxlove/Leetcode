# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if head == None or head.next == None :
            return head
        newHead = head.next
        pre = None
        while head != None and head.next != None :
            t = head.next
            p = head.next.next
            head.next = p
            t.next = head
            if pre != None :
                pre.next = t
            pre = head
            head = head.next
        return newHead