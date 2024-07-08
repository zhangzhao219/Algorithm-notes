/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if(left == right){
            return lists[left];
        }
        int mid = (right - left) / 2 + left;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);
        ListNode* l3 = new ListNode(-1);
        ListNode* head = l3;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                l3->next = l2;
                l2 = l2->next;
            } else if(l2 == NULL){
                l3->next = l1;
                l1 = l1->next;
            } else{
                if(l1->val < l2->val){
                    l3->next = l1;
                    l1 = l1->next;
                } else{
                    l3->next = l2;
                    l2 = l2->next;
                }
            }
            l3 = l3->next;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0){
            return NULL;
        }
        return merge(lists, 0, k-1);
    }
};
// @lc code=end

