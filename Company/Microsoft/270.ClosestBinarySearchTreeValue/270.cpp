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
    int value;
    double minRes = 1.79e308;
    int closestValue(TreeNode* root, double target) {
        if(!root) return value;
        
        double res = root->val - target;
        
        if(abs(res) <= minRes)
        {
            value = root->val;
            minRes = abs(res);
        }
        
        if(res >= 0) return closestValue(root->left, target);
        if(res < 0) return closestValue(root->right, target);
    }
};

/*
6ms, 90.24%
我的天哪，居然卡 2147483647, 而且不识别DBL_MAX 据说是定义在float.h里面的

标答的方法
9ms, 17.94%还慢哦
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

    int closestValue(TreeNode* root, double target) {
        double res = root->val - target;
        TreeNode* child = res > 0 ? root->left : root -> right;
        if(!child) return root->val;
        int child_ans = closestValue(child, target);
        return abs(child_ans - target) < abs(res) ? child_ans : root->val;
        
    }
    


};