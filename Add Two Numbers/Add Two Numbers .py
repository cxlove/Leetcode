# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        up = 0
        tail , head = None , None
        while l1 != None or l2 != None or up != 0 :
            now = ListNode (up)
            if l1 != None : now.val , l1 = now.val + l1.val , l1.next
            if l2 != None : now.val , l2 = now.val + l2.val , l2.next
            up = now.val / 10
            now.val %= 10
            if tail == None : head , tail = now , now
            else : 
                tail.next = now
                tail = now
        return head