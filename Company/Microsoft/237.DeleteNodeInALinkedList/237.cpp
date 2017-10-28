/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

/*
没有看懂题目

通过答案看懂了，觉得之后好简单。。

13ms, 31.49%
因为没有给定要删的节点的前面一项，所有用后面一项的值取代该项，然后删掉后面一项即可
*/