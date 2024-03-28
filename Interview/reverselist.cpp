#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(vector<int>& nums){
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    for(int i=0;i<nums.size();i++){
        head->next = new ListNode(nums[i]);
        head = head->next;
    }
    return p->next;
}

void print_list(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverse_list(ListNode* head){
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
    vector<int> nums = {1,2,4,5,7,8,9,6,5,2,3,6};
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    ListNode* head = create_list(nums);
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    return 0;
}