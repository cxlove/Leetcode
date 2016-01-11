/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        toSmallest (root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty ();
    }

    /** @return the next smallest number */
    int next() {
        if (s.empty ()) return -1;
        TreeNode *top = s.top(); s.pop ();
        int val = top -> val;
        toSmallest (top -> right);
        return val;
    }
    
    void toSmallest (TreeNode *root) {
        while (NULL != root) {
            s.push (root);
            root = root -> left;
        }
    }
private :
    stack <TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
