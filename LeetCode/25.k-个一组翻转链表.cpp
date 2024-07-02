/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* realhead = dummy;
        
        while(1){
            bool sign = false;
            ListNode* p = head;
            ListNode* pre = NULL;
            for(int i=0;i<k;i++){
                if(p == NULL){
                    sign = true;
                    break;
                }
                pre = p;
                p = p->next;
            }
            if(sign){
                break;
            }
            pre->next = NULL;
            dummy->next = reverseList(head);
            for(int i=0;i<k;i++){
                dummy = dummy->next;
            }
            head = p;
        }
        if(head != NULL){
            dummy->next = head;
        }
        return realhead->next;
    }
};
// @lc code=end

