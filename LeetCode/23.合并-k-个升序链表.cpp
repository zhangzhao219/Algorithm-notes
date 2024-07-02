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
    ListNode* merge(vector<ListNode*>& lists, int start, int end){
        if(start == end){
            return lists[start];
        }
        int mid = (end - start) / 2 + start;
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid+1, end);
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(left != NULL || right != NULL){
            if(left == NULL){
                dummy->next = right;
                right = right->next;
            } else if(right == NULL){
                dummy->next = left;
                left = left->next;
            } else{
                if(left->val < right -> val){
                    dummy->next = left;
                    left = left->next;
                } else{
                    dummy->next = right;
                    right = right->next;
                }
            }
            dummy = dummy->next;
        }
        return p->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        return merge(lists, 0, lists.size()-1);
    }
};
// @lc code=end

