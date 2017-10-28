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
private:
    bool hasp = false, hasq = false;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        TreeNode* ans1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* ans2 = lowestCommonAncestor(root->right, p, q);
        if(hasp && hasq)
        {
            if(ans1 == NULL) return ans2;
            if(ans2 == NULL) return ans1;
            return root;
        } 
        if(root->val == p->val)
        {
             hasp = true;
             return root;
        }
        if(root->val == q->val)
        {
              hasq = true;
              return root;
        }
        return ans1 != NULL ? ans1 : ans2;
    }
};

/*
26ms, 41.51%

没想到提交几次就过了。。。
错的地方很多啊。。比如一开始没想清楚怎么判断hasp, hasq, 有可能ans1, ans2都不为空。。。
这里要再看看

看了一下答案, 果然我想复杂了
注意这里限定了BST，是个二叉查找树，所以可以比大小的！！！
26ms, 41.51%
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};