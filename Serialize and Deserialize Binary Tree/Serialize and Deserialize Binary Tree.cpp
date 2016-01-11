/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (NULL == root) {
            return "()";
        }

        char ch[100];sprintf (ch , "%d" , root -> val);
        return string ("(") + string (ch) + string (")") + serialize (root -> left) + serialize (root -> right);
    }

    TreeNode* dfs (string &s , int &idx) {
        idx ++;
        if (s[idx] == ')') {
            idx ++;
            return NULL;
        }
        int num = 0 , sgn = 1;
        if (s[idx] == '+') idx ++;
        else if (s[idx] == '-') {
            sgn = -1;
            idx ++;
        }
        while (s[idx] != ')') {
            num = num * 10 + (s[idx ++] - '0');
        }
        idx ++;
        TreeNode *root = new TreeNode (num * sgn);
        root -> left = dfs (s , idx);
        root -> right = dfs (s , idx);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfs (data , idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));