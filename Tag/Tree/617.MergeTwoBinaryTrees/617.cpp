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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        TreeNode* son = new TreeNode(t1->val + t2->val);
        son->left = mergeTrees(t1->left, t2->left);
        son->right = mergeTrees(t1->right, t2->right);
        return son;
    }
};

/*
45ms
49.97%

时间复杂度O(m)，总共要访问m个节点（min(t1.size(), t2.size)） 
空间复杂度O(m)，树的深度可以达到m,但是平均来说是O(logm)

这里要注意的是，指针一开始定义要 new一下！！

以及、即使把son全部换成t1,时间还是45ms...
*/