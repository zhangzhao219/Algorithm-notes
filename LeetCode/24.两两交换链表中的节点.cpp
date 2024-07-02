/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
        while(head != NULL){
            ListNode* q = head->next;
            head->next = pre;
            pre = head;
            head = q;
        }
        return pre;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* realhead = dummy;
        while(head != NULL && head->next != NULL){
            ListNode* q = head->next->next;
            head->next->next = NULL;
            dummy->next = reverseList(head);
            dummy = dummy->next->next;
            head = q;
        }
        if(head != NULL){
            dummy->next = head;
        }
        return realhead->next;
    }
};
// @lc code=end

