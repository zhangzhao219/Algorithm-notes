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
        while(p != q){
            if(p == NULL){
                p = headB;
            } else{
                p = p->next;
            }
            if(q == NULL){
                q = headA;
            } else{
                q = q->next;
            }
        }
        return p;
    }
};
// @lc code=end

