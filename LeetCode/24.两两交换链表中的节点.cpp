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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while(p != NULL){
            if (p->next != NULL && p->next->next != NULL){
                ListNode* a = p->next;
                ListNode* b = a->next;
                ListNode* c = b->next;
                p->next = b;
                b->next = a;
                a->next = c;
                p = a;
            } else{
                break;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

