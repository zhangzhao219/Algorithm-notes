/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        while(fast != NULL){
            if(fast->next == NULL){
                fast = fast->next;
                flag = true;
            } else{
                fast = fast->next->next;
            }
            ListNode* q = slow->next;
            slow->next = pre;
            pre = slow;
            slow = q;
            if(flag){
                pre = pre->next;
            }

        }
        while(pre != NULL && slow != NULL){
            if(pre->val != slow->val){
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;

    }
};
// @lc code=end

