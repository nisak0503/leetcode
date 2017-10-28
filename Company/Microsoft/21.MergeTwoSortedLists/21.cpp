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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if(l1) ptr->next = l1;
        if(l2) ptr->next = l2;
        return result->next;
    }
};

/*
9ms, 60.94%
很直观的想法，但是注意result = new ListNode(0) 好像必须要写
否则的话 ptr -> next 用不了，这不是废话吗， NULL ->next怎么弄？
*/