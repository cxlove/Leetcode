/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Node {
    int val;
    ListNode *p;
    Node () {}
    Node (int _v , ListNode *q) {
        val = _v;p = q;
    }
    bool operator < (const Node &n) const {
        return val > n.val;
    }
};
priority_queue <Node> que;
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = new ListNode (-1) , *now = head;
        int n = lists.size ();
        for (int i = 0 ; i < n ; i ++) {
            if (lists[i] != NULL)
                que.push (Node (lists[i] -> val , lists[i]));
        }
        while (!que.empty ()) {
            Node top = que.top ();que.pop ();
            now -> next = new ListNode (top.val);
            now = now -> next;
            if (top.p -> next) {
                que.push (Node (top.p -> next -> val , top.p -> next));
            } 
        }
        return head -> next;
    }
};