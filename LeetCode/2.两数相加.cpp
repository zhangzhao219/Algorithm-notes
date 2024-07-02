/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;
        int cur = 0;
        int sum = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + cur;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != NULL){
                sum = l1->val + cur;
                l1 = l1->next;
            } else if(l2 != NULL){
                sum = l2->val + cur;
                l2 = l2->next;
            }
            if(sum >= 10){
                sum -= 10;
                cur = 1;
            } else{
                cur = 0;
            }
            l3->next = new ListNode(sum);
            l3 = l3->next;
        }
        if (cur == 1){
            l3->next = new ListNode(1);
        }
        return dummy->next;
    }
};
// @lc code=end

