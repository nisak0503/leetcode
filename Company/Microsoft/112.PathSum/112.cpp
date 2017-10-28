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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && (root->val == sum)) return true;
        int res = sum - root->val;
        if(root->left && hasPathSum(root->left, res)) return true;
        if(root->right && hasPathSum(root->right, res)) return true;
        return false;
    }
};

/*
智障啦！ root->left 没写root, 16,17行 !root->left 的感叹号是什么意思！

13ms, 5.13%可以说是非常慢了

精简了一下 9ms, 20.68%
*/
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && (root->val == sum)) return true;
        if(hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)) return true;
        return false;
    }
};