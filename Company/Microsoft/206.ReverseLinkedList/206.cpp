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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* newHead = head->next;
        ListNode* son = head;
        while(newHead->next != NULL)
        {
            son = newHead;
            newHead = newHead->next;
        }
        son->next = NULL;
        newHead->next = reverseList(head);
        return newHead;
    }
};

/*
注意因为有son 有newHead， 所以边界判断有两个if (13, 14行)
这个办法是递归调用recursive，很慢 
42ms, 0.69%

还有迭代的方法， 这里不是很熟悉
6ms 68.23%
显然这样快很多
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while(head)
        {
            ListNode* son = head->next;
            head->next = pre;
            pre = head;
            head = son;
        }
        return pre;
    }
};