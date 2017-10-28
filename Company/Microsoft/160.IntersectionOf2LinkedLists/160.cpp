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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pt1 = headA, *pt2 = headB;
        while(pt1 != pt2)
        {
            if(pt1) pt1 = pt1->next;
            else pt1 = headB;
            if(pt2) pt2 = pt2->next;
            else pt2 = headA;
        }
        return pt1;
    }
};

/*
32ms, 92.90%
这道题没想出来好想打自己
既然会做环，那么就把两个链连起来就好啦~！

交点为什么就是相交点呢

A ----1----P ------3-----
B----2-----(P)

pt1 走过了 1 + 3 + 2
pt2 走过了 2 + 3 + 1
所以相遇点一定是p


*/