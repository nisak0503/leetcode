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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *A = head;
        ListNode *B = head;
        while(A && B)
        {
            
            if(A)
                A = A->next;
            else
                break;
            if(B && B->next)
                B = (B->next)->next;
            else
                break;
            
            if(A && B && A->val == B->val) 
            {
                return true;
            }
        }
        return false;
    }
};

/*
被自己蠢哭了
9ms, 38.29%

错了七次
交了三次才反应过来 B->val的话if(A && B && B->val)才行
后面四次一直在想两个else break

这里的问题是，假设没有环，最后AB都会停在最后一个，因为最后一个NULL的话，AB不会等于他们。
应该while(fast && fast->next) 这样可以保证slow都不为NULL

9ms, 38.29% 一样的， 思路更清晰
*/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == NULL) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};