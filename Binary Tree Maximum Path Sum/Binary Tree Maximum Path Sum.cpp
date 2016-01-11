/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair <int , int> dfs (TreeNode *root) {
        if (root == NULL) return make_pair (-(1 << 26) , 0);
        pair <int , int> lson = dfs (root -> left);
        pair <int , int> rson = dfs (root -> right);
        return make_pair (max (lson.second + rson.second + root -> val , max (lson.first , rson.first)) , max (0 , max (lson.second , rson.second) + root -> val));
    }
    int maxPathSum(TreeNode* root) {
        return dfs (root).first;
    }
};
