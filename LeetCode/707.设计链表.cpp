/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
    }
    
    int get(int index) {
        if(index >= this->size || index <= -1){
            return -1;
        }
        ListNode* p = this->head;
        while(index != 0){
            index -= 1;
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(this->size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > this->size || index <= -1){
            return;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        dummy->next = this->head;
        while(index != 0){
            index -= 1;
            p = p->next;
        }
        ListNode* newnode = new ListNode(val);
        newnode->next = p->next;
        p->next = newnode;
        this->head = dummy->next;
        this->size += 1;
    }
    
    void deleteAtIndex(int index) {
        if(index >= this->size || index <= -1){
            return;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        dummy->next = this->head;
        while(index != 0){
            index -= 1;
            p = p->next;
        }
        p->next = p->next->next;
        this->head = dummy->next;
        this->size -= 1;
    }
private:
    int size;
    ListNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

