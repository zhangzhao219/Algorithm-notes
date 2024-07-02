/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n--){
            fast = fast->next;
        }
        while(fast != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }
};
// @lc code=end

