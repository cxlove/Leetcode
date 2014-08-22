# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        left , right = head , head
        for i in range (n) :
            right = right.next
        if right == None : return head.next
        while right.next != None :
            left , right = left.next , right.next
        left.next = left.next.next
        return head