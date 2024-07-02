/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* mergesort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* right = mergesort(slow->next);
        if(slow != NULL){
            slow->next = NULL;
        }
        ListNode* left = mergesort(head);
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(left != NULL || right != NULL){
            if(left == NULL){
                p->next = right;
                right = right->next;
            } else if(right == NULL){
                p->next = left;
                left = left->next;
            } else{
                if(left->val < right->val){
                    p->next = left;
                    left = left->next;
                } else{
                    p->next = right;
                    right = right->next;
                }
            }
            p = p->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
// @lc code=end

