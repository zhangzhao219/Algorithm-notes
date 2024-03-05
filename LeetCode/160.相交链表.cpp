/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
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
        ListNode* p = headA;
        ListNode* q = headB;
        int flag = 4;
        while(flag > 0){
            if(p == q){
                return p;
            }
            if (p->next != NULL){
                p = p->next;
            } else{
                p = headB;
                flag -= 1;
            }
            if(q->next != NULL){
                q = q->next;
            } else{
                q = headA;
                flag -= 1;
            }
        }
        return NULL;
    }
};
// @lc code=end

