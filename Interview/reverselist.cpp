#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
};


ListNode* createLinkedList(vector<int> nums){
    ListNode* dummy = new ListNode();
    dummy->next = NULL;
    ListNode* head = dummy;
    for(int i=0;i<nums.size();i++){
        head->next = new ListNode();
        head->next->val = nums[i];
        head->next->next = NULL;
        head = head->next;
    }
    return dummy->next;
}

void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reversedList(ListNode* head){
    ListNode* pre = NULL;
    while(head != NULL){
        ListNode* q = head->next;
        head->next = pre;
        pre = head;
        head = q;
    }
    return pre;
}


int main(){
    vector<int> nums = {1,2,4,5,7,8,5,4,2};
    ListNode* head = createLinkedList(nums);
    printList(head);
    head = reversedList(head);
    printList(head);
    return 0;
}